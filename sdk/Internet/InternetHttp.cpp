#include "StdAfx.h"
#include <assert.h>
#include "InternetHttp.h"
#include <string>
#include "FileOpr.h"
#include <memory>
#include "ResCommon.h"
#include "DowningInfoMng.h"
#include "StrCoding.h"
#include "functional.h"
#include "PiBPDown.h"
#include "AutoType.h"
#include "k_STLString.h"
#include "doString.h"
#include "DataMng.h"
using namespace std;
using namespace std::tr1;
typedef shared_ptr<HINTERNET> RAIIHInet;
//using std::string;
#pragma comment(lib, "Wininet.lib")
#define NUM_RETRY_TIMES_MAX     5   //一个文件失败最大可重试次数

const UNLONG	NUM_MAX_SIZE_PER				= NUM_FILE_SIZE_1M * 5; //一次最大分配内存限制
const UNINT		NUM_URL_LENGTH_MAX				= 800;		//整个URL
const UNINT		NUM_HOST_LENGTH_MAX				= 50;		//主机名
const byte		NUM_SERVER_TYPE_LENGTH_MAX		= 10;		//主机名

void DeleteHInet(void* pH)
{
	ClearHInternet(*(HINTERNET*)pH);
}

CInternetHttp::CInternetHttp(void)
{
	InitVariable();
        
}


CInternetHttp::~CInternetHttp(void)
{
	DownloadUnInit();    
}

void CInternetHttp::InitVariable()
{
	m_hInet			= NULL;
	m_hCn			= NULL;
	m_nServiceType  = 0;
	m_dwErrCode		= 0;
	m_dwServerState = 0;
	m_dwFlag		= INTERNET_FLAG_RELOAD;
    m_dwDowned      = 0;
    m_dwSizeTotalSrc   = 0;
    m_idDowningInfo = 0;
    m_pDowningInfoMng   = NULL;
	m_dState		= err_unKnown;
    m_bQuitDown     = false;
    m_szHeader      = nullptr;
    m_hQeq          = NULL;
    m_pBPDown       = NULL;
    m_nCanRetryCountMax     = NUM_RETRY_TIMES_MAX;
    m_nRetryedCount         = 0;
	memset(&m_uc, 0, sizeof(URL_COMPONENTS));
}

bool CInternetHttp::DownloadFile( tcpchar strUrl )
{
	return 
			this->DownloadInit(strUrl)
		&&	this->DownloadObject(strUrl)
		&&	this->DownloadUnInit();
}


int CInternetHttp::GetServiceType( INTERNET_SCHEME nSchemeType )
{
	int nServiceType = 0;
	switch(nSchemeType)
	{
	case INTERNET_SCHEME_FTP:
		nServiceType = INTERNET_SERVICE_FTP;
		break;
	case INTERNET_SCHEME_GOPHER:
		nServiceType = INTERNET_SERVICE_GOPHER;
		break;
	case INTERNET_SCHEME_HTTP:
		nServiceType = INTERNET_SERVICE_HTTP;
		break;
	}
	return nServiceType;
}

bool CInternetHttp::DownloadInit( tcpchar strUrl, tcpchar szProxyServe /*= NULL*/ )
{
	//string sUrl = ws2s(strUrl);
    DWORD dwAccess = 0;
    dwAccess = NULL;
    tstring strProxy;
    tpchar pProxyServer = NULL;
    if(szProxyServe && *szProxyServe)
    {
        dwAccess |= INTERNET_OPEN_TYPE_PROXY;
        strProxy = szProxyServe;
        pProxyServer = &strProxy.at(0);
    }
	m_hInet = ::InternetOpen(NULL, dwAccess, pProxyServer, NULL, NULL);
	SaveErrCodeAndRet(m_hInet);

	
	tchar* szType = new tchar[NUM_SERVER_TYPE_LENGTH_MAX + 1];
	tchar* szHost = new tchar[NUM_HOST_LENGTH_MAX + 1];
	tchar* szBufUrl = new tchar[NUM_URL_LENGTH_MAX + 1];

	tmemset(szType, 0,      NUM_SERVER_TYPE_LENGTH_MAX + 1);
	tmemset(szHost, 0,      NUM_HOST_LENGTH_MAX + 1);
	tmemset(szBufUrl, 0,    NUM_URL_LENGTH_MAX + 1);
	

    //m_dwFlag = /*INTERNET_FLAG_NO_COOKIES | INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_PRAGMA_NOCACHE* |*/ 
     //          INTERNET_FLAG_RELOAD  /* | INTERNET_FLAG_NO_AUTO_REDIRECT*/;	//防止重定向
	
	memset(&m_uc, 0, sizeof(URL_COMPONENTS));
	m_uc.dwStructSize		= sizeof(URL_COMPONENTS);
	m_uc.lpszHostName		= szHost;
	m_uc.dwHostNameLength	= NUM_HOST_LENGTH_MAX;
	m_uc.lpszScheme			= szType;
	m_uc.dwSchemeLength		= NUM_SERVER_TYPE_LENGTH_MAX;
	m_uc.nPort				= 1;
	m_uc.lpszUrlPath		= szBufUrl;
	m_uc.dwUrlPathLength	= NUM_URL_LENGTH_MAX;
	
	m_strUrl = strUrl;
	BOOL bRet = ::InternetCrackUrl(strUrl, 0, NULL, &m_uc);
	SaveErrCodeAndRet(bRet);

	m_nServiceType		= GetServiceType(INTERNET_SCHEME_HTTP);
	m_hCn				= ::InternetConnect(m_hInet, m_uc.lpszHostName, m_uc.nPort, NULL, NULL, m_nServiceType, NULL, NULL);
	SaveErrCodeAndRet(m_hCn);

	CheckSetHttpWay();
    /* 设置超时 **/
    UNLONG nTime = 3000;
    if( ! InternetSetOption(m_hCn, INTERNET_OPTION_CONNECT_TIMEOUT, &nTime, sizeof(nTime))
        || ! InternetSetOption(m_hCn, INTERNET_OPTION_RECEIVE_TIMEOUT, &nTime, sizeof(nTime))
        || ! InternetSetOption(m_hCn, INTERNET_OPTION_SEND_TIMEOUT, &nTime, sizeof(nTime))
        )
    {
        return false;
    }
	return true;
}

bool CInternetHttp::DownloadObject( tcpchar szUrl, tcpchar szSavePath )
{
    m_dwDowned = 0;
	CFileOpr file;	
	if(!file.Open(szSavePath, _T("ab")))  //追加方式打开
    {
        //TODO: 需要处理创建失败时的情况
        m_dState = err_file_create;
        return false;
    }
    

    /*如果要断点续传, 则删除句柄重新链接*/
    if (m_pBPDown)
    {
        m_pBPDown->SetFile(&file);
        if (m_pBPDown->IsNeedBP())
        {
            ClearHInternet(m_hQeq);
        }
    }

    if(!SendCn())
    {
        SaveErrCodeAndRetEx(0, err_unKnown);
    }


	UNLONG dwRemain = 0;
	UNLONG dwRead = 0;

	BOOL bRet = ::InternetQueryDataAvailable(m_hQeq, &dwRemain, 0, 0);
	SaveNetErrCodeAndRet(bRet);

	if(dwRemain < 0)
	{
        SaveErrCodeAndRetEx(0, err_unKnown);
	}
    
    if(m_pBPDown && !m_pBPDown->SetOffsetLocal())
    { 
        SaveErrCodeAndRetEx(0, err_unKnown);
    }

	dwRemain = min(NUM_MAX_SIZE_PER, dwRemain);

	char* pBuf = new char[dwRemain + 1];
    bool bDownSucceed = false;
	while(1)
	{
        //TODO: bool是否需要线程保护
        if (m_bQuitDown)        //是否要停止下载
        {
            bDownSucceed = false;
            m_dState = err_user_stop;
            break;
        }

		memset(pBuf, 0, dwRemain + 1);
        bRet = ::InternetReadFile(m_hQeq, pBuf, dwRemain, &dwRead);
		
        if (!bRet)
        {
            m_dState = err_net;
            m_dwErrCode = GetLastError();
            break;
        }
		else if (bRet && 0 == dwRead)
		{
            if (m_dwDowned > 0 )
            {
                bDownSucceed = true;
            }
            break;

		}
        
        if(!file.Write(pBuf, dwRead))
        {
            //TODO: handle write file fail
            m_dState = err_file_write;
            m_dwErrCode = 0;
            return false;
        }
        m_dwDowned += dwRead;
        //OutInfo(_T("--info update begin"));
        UpdateData(dwRead);   //更新下载进度
        //OutInfo(_T("--info update end"));

        //OutInfo(_T("downedSize:"), m_dwDowned);
        //OutInfo(_T("inet- down data"));
        //file.Flush();

	}

	delete [] pBuf;

	
	file.Close();
	

	return bDownSucceed;
}

bool CInternetHttp::DownloadObject( tcpchar szUrl)
{
	m_dwDowned = 0;
	if(!SendCn())
	{
		SaveErrCodeAndRetEx(0, err_unKnown);
	}


	UNLONG dwRemain = 0;
	UNLONG dwRead = 0;

	BOOL bRet = ::InternetQueryDataAvailable(m_hQeq, &dwRemain, 0, 0);
	SaveNetErrCodeAndRet(bRet);

	if(dwRemain < 0)
	{
		SaveErrCodeAndRetEx(0, err_unKnown);
	}

	if(m_pBPDown && !m_pBPDown->SetOffsetLocal())
	{ 
		SaveErrCodeAndRetEx(0, err_unKnown);
	}

	dwRemain = min(NUM_MAX_SIZE_PER, dwRemain);

	char* pBuf = new char[dwRemain + 1];
	bool bDownSucceed = false;
	while(1)
	{
		//TODO: bool是否需要线程保护
		if (m_bQuitDown)        //是否要停止下载
		{
			bDownSucceed = false;
			m_dState = err_user_stop;
			break;
		}

		memset(pBuf, 0, dwRemain + 1);
		bRet = ::InternetReadFile(m_hQeq, pBuf, dwRemain, &dwRead);

		if (!bRet)
		{
			m_dState = err_net;
			m_dwErrCode = GetLastError();
			break;
		}
		else if (bRet && 0 == dwRead)
		{
			if (m_dwDowned > 0 )
			{
				bDownSucceed = true;
			}
			break;

		}

		
		if(! DealReadData(pBuf, dwRead))
		{
			//TODO: handle write file fail
			m_dState = err_file_write;
			m_dwErrCode = 0;
			return false;
		}
		m_dwDowned += dwRead;
		//OutInfo(_T("--info update begin"));
		UpdateData(dwRead);   //更新下载进度
		//OutInfo(_T("--info update end"));

		//OutInfo(_T("downedSize:"), m_dwDowned);
		//OutInfo(_T("inet- down data"));
		//file.Flush();

	}

	delete [] pBuf;


	return bDownSucceed;
}

bool CInternetHttp::DownloadUnInit()
{
    ClearHInternet(m_hQeq);
	if (m_hCn)
	{
		ClearHInternet(m_hCn);
	}

	if (m_hInet)
	{
		ClearHInternet(m_hInet);
	}


    if (m_uc.lpszHostName)
    {
        ClearMemArr(m_uc.lpszHostName);
    }
    if (m_uc.lpszScheme)
    {
        ClearMemArr(m_uc.lpszScheme);
    }
    if (m_uc.lpszUrlPath)
    {
        ClearMemArr(m_uc.lpszUrlPath);
    }

	return true;
}

tstring CInternetHttp::FindHttpObject( tcpchar szUrl )
{
	
	UNLONG dwLength = _tcslen(szUrl);
	tchar* pBuf = new tchar[dwLength + 1];
	tmemset(pBuf, 0, dwLength + 1);
	//TCHAR cPath[300] = {0};

	URL_COMPONENTS uc;
	memset(&uc, 0, sizeof(URL_COMPONENTS));
	uc.dwStructSize		= sizeof(URL_COMPONENTS);
	uc.dwUrlPathLength	= dwLength;
	uc.lpszUrlPath		= pBuf;

	if(!::InternetCrackUrl(szUrl, 0, NULL, &uc))
	{
		int i = GetLastError();
		return _T("");
	}

	return uc.lpszUrlPath;
}

bool CInternetHttp::QueryFileSize(UNLONG& dwSize)
{
	
	/************************************************************************
		发送请求，获取	请求的文件大小
	/************************************************************************/
    if (!SendCn())
    {
        STLString strMsg;
        strMsg.Format(_T("serCode: %d, errCode:%d"), m_dwServerState, m_dwErrCode);
        /*CAutoType at;
        tstring strMsg(_T("errCode:"));
        strMsg += (tcpchar)at.SetData(m_dwErrCode);*/
//         strMsg += _T("errNet:");
//         strMsg += at.SetData(m_dwErrCode);

        OutInfo(_T("get file size fail, "), strMsg.c_str());
        return false;
    }
    

	tchar cBuf[20] = {0};
    UNLONG dwIndex = 0; 
	UNLONG dwBufLen = sizeof(cBuf);

	/************************************************************************
		获取所有报头信息,在提取出自己要的， 优化， 直接获取 文件名和文件大小字段
	/************************************************************************/
    
// 	UNLONG dwBufLen = 0;
//  	::HttpQueryInfoA(m_hQeq, HTTP_QUERY_RAW_HEADERS , NULL, &dwBufLen, &dwIndex);
//  	char* cBuf = new char[dwBufLen];
//  	memset(cBuf, 0, dwBufLen);

 	//if(!::HttpQueryInfoA(m_hQeq, HTTP_QUERY_RAW_HEADERS , cBuf, &dwBufLen, &dwIndex))
 	//{
  //      SaveErrCodeAndRetEx(0, err_unKnown);
 	//	//SaveNetErrCodeAndRet(0);
 	//}
	
	//文件名字段的报头信息是？？

    if(!HttpQueryInfo(m_hQeq, HTTP_QUERY_CONTENT_LENGTH, cBuf, &dwBufLen, &dwIndex))
    {
        OutInfo(_T("inet, head get file size err"), m_strUrl.c_str());
        SaveErrCodeAndRetEx(0, err_get_file_size);
    }

	m_dwSizeTotalSrc = _ttol(cBuf);
	dwSize = m_dwSizeTotalSrc;
    OutInfo(_T("inet, file size:"), m_dwSizeTotalSrc);
	return true;
}

bool CInternetHttp::QueryFileSize(tcpchar szUrl, UNLONG& dwSize)
{
    bool bRet = true;
	CInternetHttp itn;
	itn.DownloadInit(szUrl);

	if(! itn.QueryFileSize(dwSize))
    {
        bRet = false;
    }

    tstring strMsg(_T("fileUrl:"));
    strMsg += szUrl;
    strMsg += _T(" size:");
    
	itn.DownloadUnInit();
	OutInfo(strMsg.c_str(), dwSize);
	return bRet;
}

bool CInternetHttp::EnsureQueryOK(HINTERNET hq)
{
	/************************************************************************
		请求获取服务器的状态码， 确保是200-OK 	
	/************************************************************************/
	tchar cBuf[20] = {0};
	UNLONG dwBufLen = sizeof(cBuf);
	UNLONG dwIndex = 0;
	if(!HttpQueryInfo(hq, HTTP_QUERY_STATUS_CODE, (LPVOID)cBuf, &dwBufLen, &dwIndex))
	{
		SaveNetErrCodeAndRet(0);
	}

	m_dwServerState = _ttol(cBuf);

	switch(m_dwServerState)
	{
	case HTTP_STATUS_OK:
    case HTTP_STATUS_PARTIAL_CONTENT:
		return true;
		break;

	case HTTP_STATUS_NOT_FOUND:
		m_dState = err_server_404;
		return false;
		break;

	//case HTTP_STATUS_FORBIDDEN:		// 忽略服务器 拒绝的错误
	//	return true;
		break;

	default:
		m_dState = err_server;
		break;
	}
	
	
	return false;
}

DownState CInternetHttp::GetErrType()
{
	return m_dState;
}

void CInternetHttp::QuitDown()
{
    m_bQuitDown = true;
}

void CInternetHttp::ResumeDown()
{
    m_bQuitDown = false;
}


void CInternetHttp::UpdateData( UNLONG nAddSize, bool bClearSpeed /*= false*/)
{
    if (! m_pDowningInfoMng)
    {
        return ;
    }
    m_pDowningInfoMng->UpdaterData(m_idDowningInfo, nAddSize, bClearSpeed);
}

void CInternetHttp::SetDowningInfoMng( CDowningInfoMng* pR )
{
    m_pDowningInfoMng = pR;
}

void CInternetHttp::SetDowningInfoID( ItemID id )
{
    m_idDowningInfo = id;
}

UNLONG CInternetHttp::GetFileSize() const
{
    return m_dwSizeTotalSrc;
}

HINTERNET CInternetHttp::GetConnectHandle()
{
    return m_hCn;
}

bool CInternetHttp::ClearState()
{
    m_dwErrCode = 0;
    m_dwServerState = 0;
    m_dState = err_unKnown;

    m_dwDowned = 0;
    return true;
}

bool CInternetHttp::SetHeader( LPCTSTR param1 )
{
    m_strHeader = param1;
    m_szHeader = m_strHeader.c_str();
    return true;
}

tstring CInternetHttp::QueryFileModifyTime()
{
    if(!SendCn())
    {
        return _T("");
    }
    tchar cBuf[200] = {0};
    UNLONG dwIndex = 0; 
    UNLONG dwBufLen = sizeof(cBuf);

    if(!::HttpQueryInfo(m_hQeq, HTTP_QUERY_LAST_MODIFIED, cBuf, &dwBufLen, &dwIndex))
    {
        return _T("");        
    }

    //m_dwSizeTotal = _ttol(cBuf);
    return cBuf;
}

tstring CInternetHttp::QuestFileModifyTime( tcpchar szUrl )
{
    tstring strTime;
    CInternetHttp http;
    if(http.DownloadInit(szUrl)
        && http.SendCn())
    {
        strTime = http.QueryFileModifyTime();
    }
    return strTime;
}



bool CInternetHttp::AddHeaderOffset( UNLONG m_nOffset )
{
    /*if(-1 == InternetSetFilePointer(m_hQeq, m_nOffset,0, FILE_BEGIN, 0))
    {
        //设置失败
        return false;
    }
    return true;*/


    CAutoType at;
    tstring strHeader;     
 
    strHeader += _T("Accept: */*\r\n");     
// 设置 禁止用缓存和缓存控制     
    strHeader += _T("Pragma: no-cache\r\n");      
    strHeader += _T("Cache-Control: no-cache\r\n");     
// 设置浏览器类型     
//     strHeader += "User-Agent:Mozilla/4.04[en](Win95;I;Nav)\r\n";      
// 设置连接     
    strHeader += _T("Connection:Keep-Alive\r\n");     
// 设置请求文件的大小     
    tstring strRange = _T("Range: bytes=");     
    strRange += (tcpchar)at.SetData(m_nOffset);     
    strRange += _T("-");     
    strRange + _T("\r\n");
    strHeader += strRange;
    return HttpAddRequestHeaders(m_hQeq, strHeader.c_str(), -1,HTTP_ADDREQ_FLAG_ADD | HTTP_ADDREQ_FLAG_REPLACE  ) == TRUE;     

}

bool CInternetHttp::SendCn()
{
    
    if (m_hQeq)
    {
        return true;
    }

    //m_dwSizeTotal = 0;
    BOOL bRet	 = FALSE;
    
    m_hQeq		= ::HttpOpenRequest(m_hCn, NULL, m_uc.lpszUrlPath/*objectName*/, NULL, NULL, NULL, m_dwFlag, NULL);

    //RAIIHInet autoHInet(&hQeq, ::DeleteHInet);

    SaveErrCodeAndRet(m_hQeq);

    
    if( m_pBPDown && ! m_pBPDown->MoveInetFilePos() )
    { 
        SaveErrCodeAndRetEx(0, err_unKnown);
    }
	tcpchar szHeader = nullptr;
	if (m_strHeader.length())
	{
		szHeader = m_strHeader.c_str();
	}
	//::HttpAddRequestHeaders(m_hCn,)
    while(1)
    {
        bRet = ::HttpSendRequest(m_hQeq, szHeader, m_strHeader.length(), NULL, NULL);
        if (bRet )
        {
            if (IsRetryOK())
            {
                OutInfo(_T("retry ok"));
            }
            m_nRetryedCount = 0;
            break;
        }
        if(! CanRetryCn())
        {
            break;
        }
    }

    SaveNetErrCodeAndRet(bRet);

    /*使用WinInet库获取，  主要是HttpQueryInfo(  HTTP_QUERY_CONTENT_LENGTH) 获取文件大小，  
    但大部分网页(文件) 连接 都获取不到大小， 提示12150 ERROR_HTTP_HEADER_NOT_FOUND ， 找不到报头，  但可以下载。     还有文件名如何获取*/
    if(!EnsureQueryOK(m_hQeq))
    {
        return false;
    }

    return true;
}

void CInternetHttp::BPDown( CPiBPDown* param1 )
{
    m_pBPDown = param1;
}

void CInternetHttp::Clear( CInternetHttp* pInet )
{
    pInet->DownloadUnInit();
}

bool CInternetHttp::CanRetryCn()
{
    int nErrLast = GetLastError();
    ++m_nRetryedCount;
    if (ERROR_INTERNET_TIMEOUT == nErrLast && !RetryOut())
    {
        OutInfo(_T("ud, retry"));
        return true;
    }
    m_nRetryedCount = 0;
    return false;
}

bool CInternetHttp::RetryOut()
{
    if (m_nRetryedCount > m_nCanRetryCountMax)
    {
        OutInfo(_T("retry out"));
        return true;
    }
    OutInfo(_T("retry"));
    return false;
}

bool CInternetHttp::IsRetryOK()
{
    return m_nRetryedCount > 0;
}

bool CInternetHttp::DealReadData( void* pData, UNINT nSize )
{
	return true;
}

void CInternetHttp::SetHttpsWay()
{
	m_dwFlag |= INTERNET_FLAG_SECURE | INTERNET_FLAG_IGNORE_CERT_CN_INVALID | INTERNET_FLAG_IGNORE_CERT_DATE_INVALID;
}

tstring CInternetHttp::GetCookie( const tstring& strUrl )
{
	//tstring strCookie;
	tpchar pBuf = nullptr;
	DWORD dwSize = 0;
	BOOL bRet = InternetGetCookieEx(strUrl.c_str(), NULL, pBuf, &dwSize
		, INTERNET_COOKIE_HTTPONLY/*INTERNET_FLAG_RESTRICTED_ZONE*/, NULL) ;	//缓冲太小返回TRUE
	if( !bRet
		&& (ERROR_INSUFFICIENT_BUFFER != GetLastError())
		)
	{
		return _T("");
	}
	
	tstring strBuf(dwSize + 1, 0);
	//pBuf = new tchar[dwSize];
	//tmemset(pBuf, 0, dwSize);

	//memset(pBuf, 0, dwSize + 1);
	
	if(!InternetGetCookieEx(strUrl.c_str(), NULL, &strBuf.at(0), &dwSize
		, INTERNET_COOKIE_HTTPONLY/*INTERNET_FLAG_RESTRICTED_ZONE*/, NULL))
	{
		int a = 0;
	}
	return strBuf.c_str();
}


void CInternetHttp::SetCookie( tcpchar szCookie )
{
	tcpchar szCookieField = _T("Cookie:");

	tstring strTemp;
	if( GetContentBetweenTwoChar(m_strHeader, strTemp, szCookieField, _T("\r\n"))
		&& !strTemp.empty()
		)
	{
		//有内容, 直接替换掉
		StrReplace(m_strHeader, strTemp.c_str(), szCookie);
	}

	STLString strCookie;
	strCookie.Format(_T("Cookie:%s"), szCookie);
	bool bExist = IsValidStrPos(m_strHeader.find(szCookieField));
	if (!bExist)
	{//没字段
		m_strHeader += strCookie;
		return ;
	}

	//有字段
	StrReplace(m_strHeader, szCookieField, strCookie.c_str());
}


void CInternetHttp::SetNoRedirect()
{
	m_dwFlag |= INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP | INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS
		| INTERNET_FLAG_NO_AUTO_REDIRECT
		;
}

bool CInternetHttp::IsNeedRedirect()
{
	return HTTP_STATUS_REDIRECT == m_dwServerState;
}

bool CInternetHttp::DeleteUrlCache( const tstring& strUrl )
{
	tstring strHostName(GetHostName(strUrl.c_str()));
	//"cookie:", "visited:", or NULL
	LPINTERNET_CACHE_ENTRY_INFO picei = nullptr;
	DWORD dwSize = 0;
	::FindFirstUrlCacheEntry(_T("cookie:"), NULL, &dwSize);
	
	picei = (LPINTERNET_CACHE_ENTRY_INFO)new TCHAR[dwSize];
	memset(picei, 0, dwSize * sizeof(TCHAR));
	HANDLE hInet = ::FindFirstUrlCacheEntry(_T("cookie:"), picei, &dwSize);
	if (!hInet)
	{
		return false;
	}
	while(1)
	{
		dwSize = 0;
		if(!::FindNextUrlCacheEntry(hInet, NULL, &dwSize) 
			&& GetLastError() != ERROR_INSUFFICIENT_BUFFER )
		{
			break;
		}
		ClearMemArr(picei);
		picei = (LPINTERNET_CACHE_ENTRY_INFO)new TCHAR[dwSize];
		memset(picei, 0, dwSize * sizeof(TCHAR));
		if(!::FindNextUrlCacheEntry(hInet, picei, &dwSize))
		{
			int nErr = GetLastError();
			break;
			//ERROR_NO_MORE_ITEMS
		}
		OutInfo(_T("cookieUrl:"), picei->lpszSourceUrlName);
		
		tstring strTemp(picei->lpszSourceUrlName);
		if ( !IsValidStrPos(strTemp.find(strHostName)))
		{
			continue;
		}
		if(!DeleteUrlCacheEntry(picei->lpszSourceUrlName))
		{
			return false;
		}
	}
	ClearMemArr(picei);
	return true;
}

tstring CInternetHttp::GetHostName( tcpchar strUrl )
{
	tchar* szHost = new tchar[NUM_HOST_LENGTH_MAX + 1];
	URL_COMPONENTS uc = {0};
	uc.dwStructSize		= sizeof(URL_COMPONENTS);
	uc.lpszHostName		= szHost;
	uc.dwHostNameLength	= NUM_HOST_LENGTH_MAX;

	BOOL bRet = ::InternetCrackUrl(strUrl, 0, NULL, &uc);
	if (!bRet)
	{
		return _T("");
	}
	return uc.lpszHostName;
}

void CInternetHttp::SetDownWeb()
{
	m_dwFlag &= ~INTERNET_FLAG_RELOAD;
	m_dwFlag |= INTERNET_FLAG_HYPERLINK | INTERNET_FLAG_RESYNCHRONIZE;	//跳过缓存从服务器获取

	//m_dwFlag |= INTERNET_FLAG_PRAGMA_NOCACHE;
}

bool CInternetHttp::CheckSetHttpWay()
{
	if(_T("https") == tstring(m_uc.lpszScheme))
	{
		SetHttpsWay();
	}
	return true;
}

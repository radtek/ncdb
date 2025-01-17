#include "StdAfx.h"
#include "PAXmlSoftConfig.h"
#include "functional.h"
#include "XmlPathMgr.h"

#define STRING_PATH_XML_DIR         _T("Config")
#define STRING_NAME_XML             _T("DASoft_Config.cfg")

CPAXmlSoftConfig::CPAXmlSoftConfig(void)
{
}


CPAXmlSoftConfig::~CPAXmlSoftConfig(void)
{
}

bool CPAXmlSoftConfig::CreateXmlData()
{
    m_pXmlUtil->SetDoc(NULL);
    m_pXmlUtil->SetDoc(_T("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"));

    m_pXmlUtil->AddElem(STRING_XML_NOTE_ROOT);
    m_pXmlUtil->IntoElem();


    m_pXmlUtil->AddElem(STRING_XML_SC_MONITOR);
    m_pXmlUtil->AddChildElem(STRING_XML_SC_CPUWARNPERCENT, m_ConfigData.strCPUWarnPercent.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_CPUNORMALBKCOLOR, m_ConfigData.strCPUNormalBkColor.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_CPUWARNBKCOLOR, m_ConfigData.strCPUWarnBkColor.c_str());

    m_pXmlUtil->AddChildElem(STRING_XML_SC_MEMORYWARNPERCENT, m_ConfigData.strMemoryWarnPercent.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_MEMORYNORMALBKCOLOR, m_ConfigData.strMemoryNormalBkColor.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_MEMORYWARNBKCOLOR, m_ConfigData.strMemoryWarnBkColor.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_CPUTimeSpan, m_ConfigData.strCPUTimeSpan.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_MemTimeSpan, m_ConfigData.strMemTimeSpan.c_str());
    
    m_pXmlUtil->AddElem(STRING_XML_SC_UPDATEINTERFACE);
    m_pXmlUtil->AddChildElem(STRING_XML_SC_UPDATE_PIPENAME, m_ConfigData.strPipeName.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_UPDATE_WNDTITLE, m_ConfigData.strWndTitle.c_str());

    m_pXmlUtil->AddElem(STRING_XML_SC_UDONGMAN);
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_LIF          , m_ConfigData.strURL_Lif		    .c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_AD           , m_ConfigData.strURL_Ad			.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_HWINFO       , m_ConfigData.strURL_HwInfo		.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_SOFTWARELIST , m_ConfigData.strURL_SoftwareList	.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_DRIVERLIST   , m_ConfigData.strURL_DriverList	.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_CLOUDLIST    , m_ConfigData.strURL_CloudList     .c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_CLOUDITEM    , m_ConfigData.strURL_CloudItem	    .c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_LOGIN        , m_ConfigData.strURL_Login		    .c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_LOGOUT       , m_ConfigData.strURL_Logout		.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_USERDETAIL   , m_ConfigData.strURL_UserDetail	.c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_USERHABIT    , m_ConfigData.strURL_UserHabit	    .c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_PAUPDATE     , m_ConfigData.strURL_PaUpdate		.c_str());


    m_pXmlUtil->AddElem(STRING_XML_SC_URL_PaClose);
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_ShowPromt             , m_ConfigData.strShowPromt   		    .c_str());
    m_pXmlUtil->AddChildElem(STRING_XML_SC_URL_NerverNotify          , m_ConfigData.strNerverNotify		    .c_str());


    return true;

}

bool CPAXmlSoftConfig::InitDefaultXmlStruct()
{
    m_ConfigData.strCPUWarnPercent          = STRING_VALUE_SC_CPUWARNPERCENT;
    m_ConfigData.strCPUNormalBkColor        = STRING_VALUE_SC_CPUNORMALBKCOLOR;
    m_ConfigData.strCPUWarnBkColor          = STRING_VALUE_SC_CPUWARNBKCOLOR;
    m_ConfigData.strMemoryWarnPercent       = STRING_VALUE_SC_MEMORYWARNPERCENT;
    m_ConfigData.strMemoryNormalBkColor     = STRING_VALUE_SC_MEMORYNORMALBKCOLOR;
    m_ConfigData.strMemoryWarnBkColor       = STRING_VALUE_SC_MEMORYWARNBKCOLOR;
    m_ConfigData.strCPUTimeSpan       = STRING_VALUE_SC_CPUTimeSpan;
    m_ConfigData.strMemTimeSpan       = STRING_VALUE_SC_MemTimeSpan;
    
    m_ConfigData.strPipeName        = STRING_VALUE_SC_UPDATE_PIPENAME;
    m_ConfigData.strWndTitle        = STRING_VALUE_SC_UPDATE_WNDTITLE;

    m_ConfigData.strURL_Lif		            = STRING_VALUE_SC_URL_LIF         ;
    m_ConfigData.strURL_Ad			        = STRING_VALUE_SC_URL_AD          ;
    m_ConfigData.strURL_HwInfo		        = STRING_VALUE_SC_URL_HWINFO      ;
    m_ConfigData.strURL_SoftwareList	    = STRING_VALUE_SC_URL_SOFTWARELIST;
    m_ConfigData.strURL_DriverList	        = STRING_VALUE_SC_URL_DRIVERLIST  ;
    m_ConfigData.strURL_CloudList	        = STRING_VALUE_SC_URL_CLOUDLIST   ;
    m_ConfigData.strURL_CloudItem	        = STRING_VALUE_SC_URL_CLOUDITEM   ;
    m_ConfigData.strURL_Login		        = STRING_VALUE_SC_URL_LOGIN       ;
    m_ConfigData.strURL_Logout		        = STRING_VALUE_SC_URL_LOGOUT      ;
    m_ConfigData.strURL_UserDetail	        = STRING_VALUE_SC_URL_USERDETAIL  ;
    m_ConfigData.strURL_UserHabit	        = STRING_VALUE_SC_URL_USERHABIT   ;
    m_ConfigData.strURL_PaUpdate		    = STRING_VALUE_SC_URL_PAUPDATE    ;
    m_ConfigData.strShowPromt   		    = STRING_VALUE_SC_URL_ShowPromt       ;
    m_ConfigData.strNerverNotify		    = STRING_VALUE_SC_URL_NerverNotify    ;

    return true;

}

bool CPAXmlSoftConfig::DoMapXmlDataToMem()
{
    m_pXmlUtil->ResetPos();

    DealBoolRet(m_pXmlUtil->FindElem());
    DealBoolRet(m_pXmlUtil->IntoElem()); //����root

    
    DealBoolRet(m_pXmlUtil->FindElem(STRING_XML_SC_MONITOR));
    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_CPUWARNPERCENT));
    m_ConfigData.strCPUWarnPercent = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_CPUNORMALBKCOLOR));
    m_ConfigData.strCPUNormalBkColor = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_CPUWARNBKCOLOR));
    m_ConfigData.strCPUWarnBkColor = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_MEMORYWARNPERCENT));
    m_ConfigData.strMemoryWarnPercent = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_MEMORYNORMALBKCOLOR));
    m_ConfigData.strMemoryNormalBkColor = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_MEMORYWARNBKCOLOR));
    m_ConfigData.strMemoryWarnBkColor = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_CPUTimeSpan));
    m_ConfigData.strCPUTimeSpan = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_MemTimeSpan));
    m_ConfigData.strMemTimeSpan = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindElem(STRING_XML_SC_UPDATEINTERFACE));
    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_UPDATE_PIPENAME));
    m_ConfigData.strPipeName = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_UPDATE_WNDTITLE));
    m_ConfigData.strWndTitle = m_pXmlUtil->GetChildData();

    m_pXmlUtil->FindElem(STRING_XML_SC_UDONGMAN);
    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_LIF));
    m_ConfigData.strURL_Lif = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_AD));
    m_ConfigData.strURL_Ad = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_HWINFO));
    m_ConfigData.strURL_HwInfo = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_SOFTWARELIST));
    m_ConfigData.strURL_SoftwareList = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_DRIVERLIST));
    m_ConfigData.strURL_DriverList = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_CLOUDLIST));
    m_ConfigData.strURL_CloudList = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_CLOUDITEM));
    m_ConfigData.strURL_CloudItem = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_LOGIN));
    m_ConfigData.strURL_Login = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_LOGOUT));
    m_ConfigData.strURL_Logout = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_USERDETAIL));
    m_ConfigData.strURL_UserDetail = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_USERHABIT));
    m_ConfigData.strURL_UserHabit = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_PAUPDATE));
    m_ConfigData.strURL_PaUpdate = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindElem(STRING_XML_SC_URL_PaClose));
    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_ShowPromt));
    m_ConfigData.strShowPromt = m_pXmlUtil->GetChildData();

    DealBoolRet(m_pXmlUtil->FindChildElem(STRING_XML_SC_URL_NerverNotify));
    m_ConfigData.strNerverNotify = m_pXmlUtil->GetChildData();
    return true;

}

bool CPAXmlSoftConfig::ReadWriteData( XML_PA_SOFT_CONFIG& ucData, ENUM_DATA_DUTY_SC da, tstring& strData )
{
    bool bRet = false;
    switch(da)
    {
        Imp_Duty_Cn_Interface(ddsc_cpu_warn_percent,        ReadWriteCPUWarnPercent)      
        Imp_Duty_Cn_Interface(ddsc_cpu_normal_bkcolor,      ReadWriteCPUNormalBkColor)    
        Imp_Duty_Cn_Interface(ddsc_cpu_warn_bkcolor,        ReadWriteCPUWarnBkColor)      
        Imp_Duty_Cn_Interface(ddsc_memory_warn_percent,     ReadWriteMemoryWarnPercent)   
        Imp_Duty_Cn_Interface(ddsc_memory_normal_bkcolor,   ReadWriteMemoryNormalBkColor) 	
        Imp_Duty_Cn_Interface(ddsc_memory_warn_bkcolor,     ReadWriteMemoryWarnBkColor)    
        Imp_Duty_Cn_Interface(ddsc_cpu_time_span,           ReadWriteCPUTimeSpan)    
        Imp_Duty_Cn_Interface(ddsc_mem_time_span,           ReadWriteMemTimeSpan)    
        Imp_Duty_Cn_Interface(ddsc_updater_pipename,        ReadWriteUpdaterPipename)    
        Imp_Duty_Cn_Interface(ddsc_updater_wndtitle,        ReadWriteUpdaterWndtitle)    

        Imp_Duty_Cn_Interface(ddsc_url_lif          ,       ReadWriteURL_Lif		    )    
        Imp_Duty_Cn_Interface(ddsc_url_ad           ,       ReadWriteURL_Ad			    )    
        Imp_Duty_Cn_Interface(ddsc_url_hwinfo       ,       ReadWriteURL_HwInfo		    )    
        Imp_Duty_Cn_Interface(ddsc_url_softwarelist ,       ReadWriteURL_SoftwareList	)    
        Imp_Duty_Cn_Interface(ddsc_url_driverlist   ,       ReadWriteURL_DriverList	    )    
        Imp_Duty_Cn_Interface(ddsc_url_cloudlist    ,       ReadWriteURL_CloudList	    )    
        Imp_Duty_Cn_Interface(ddsc_url_clouditem    ,       ReadWriteURL_CloudItem	    )    
        Imp_Duty_Cn_Interface(ddsc_url_login        ,       ReadWriteURL_Login		    )    
        Imp_Duty_Cn_Interface(ddsc_url_logout       ,       ReadWriteURL_Logout		    )    
        Imp_Duty_Cn_Interface(ddsc_url_userdetail   ,       ReadWriteURL_UserDetail	    )    
        Imp_Duty_Cn_Interface(ddsc_url_userhabit    ,       ReadWriteURL_UserHabit	    )    
        Imp_Duty_Cn_Interface(ddsc_url_paupdate     ,       ReadWriteURL_PaUpdate		)    
        Imp_Duty_Cn_Interface(ddsc_show_promt        ,      ReadWriteURL_ShowPromt   		)    
        Imp_Duty_Cn_Interface(ddsc_nerver_notify     ,      ReadWriteURL_NerverNotify		)    
   
    }
    return true;

}

tstring CPAXmlSoftConfig::GetXmlFullPath()
{
    tstring strPath;

    strPath = CXmlPathMgr::GetSoftSettingXmlPath();

    //strPath = _T("D:\\test\\DA\\SoftConfig.xml");
//     strPath = GetModuleFoloder();
//     strPath += STRING_PATH_XML_DIR _T("\\");
//     strPath += STRING_NAME_XML;
    return strPath;
}

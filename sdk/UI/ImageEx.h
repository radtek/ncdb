// GDIPlusHelper.h: interface for the CGDIPlusHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GDIPLUSHELPER_H__BD5F6266_5686_43E2_B146_5EA1217A56FE__INCLUDED_)
#define AFX_GDIPLUSHELPER_H__BD5F6266_5686_43E2_B146_5EA1217A56FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <atlstr.h>

class ImageEx : public Image
{
public:
	ImageEx(IN LPCTSTR  sResourceType, IN LPCTSTR  sResource);
	ImageEx(LPCTSTR filename, BOOL useEmbeddedColorManagement = FALSE);

	
	~ImageEx();
public:

	void	Draw(CDC* pDC);
	::CSize	GetSize();

	bool	IsAnimatedGIF() { return m_nFrameCount > 1; }
	void	SetPause(bool bPause);
	bool	IsPaused() { return m_bPause; }
	bool	InitAnimation(HWND hWnd, ::CPoint pt);
	void	Destroy();
	bool ShowNextFrame( HDC hdcUI );
	void SetDrawPoint(::CPoint pt);
	bool IsPicOk();
	UINT GetCurrentFramePosition() const { return m_nFramePosition; }
	int GetFrameDelay( int param1 );
protected:

	bool				TestForAnimatedGIF();
	void				Initialize();
	bool				DrawFrameGIF();

	IStream*			m_pStream;
	
	bool LoadFromBuffer(BYTE* pBuff, int nSize);
	bool GetResource(LPCTSTR lpName, LPCTSTR lpType, void* pResource, int& nBufSize);
	bool Load(CString sResourceType, CString sResource);

	void ThreadAnimation();

	static UINT WINAPI _ThreadAnimationProc(LPVOID pParam);

private:
	HANDLE			m_hThread;
	HANDLE			m_hPause;
	HANDLE			m_hExitEvent;
	HINSTANCE		m_hInst;
	HWND			m_hWnd;
	UINT			m_nFrameCount;
	UINT			m_nFramePosition;
	
	bool			m_bIsInitialized;
	bool			m_bPause;
	PropertyItem*	m_pPropertyItem;
	::CPoint			m_pt;
};


#endif // !defined(AFX_GDIPLUSHELPER_H__BD5F6266_5686_43E2_B146_5EA1217A56FE__INCLUDED_)

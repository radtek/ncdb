#include "StdAfx.h"
#include "GDIPUtil.h"
#include <GdiPlus.h>
#include "Math/PiMathUnit.h"
#pragma comment( lib, "GdiPlus.lib" )
using namespace Gdiplus;

static const CPiGdip g_gidp;
Pi_NameSpace_Using

CPiGdip::CPiGdip()
{
	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
}

CPiGdip::~CPiGdip()
{
	GdiplusShutdown(m_gdiplusToken);
}

CGDIPUtil::CGDIPUtil(void)
{
}

CGDIPUtil::~CGDIPUtil(void)
{
}

int CGDIPUtil::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if(size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for(UINT j = 0; j < num; ++j)
	{
		if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}    
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}


void CGDIPUtil::ClipPic( LPCTSTR strPicSize, LPCTSTR strPicSrc )
{
	HDC hDCWnd = GetDC(GetDesktopWindow());

	Image imgShade(strPicSize);
	Image* imgShow = Image::FromFile(strPicSrc);
	Bitmap bm(imgShade.GetWidth(), imgShade.GetHeight());
	int nWidth = imgShade.GetWidth(); 
	int nHeight = imgShade.GetHeight();

	Graphics gpDist(&bm);
	gpDist.Clear(Color(0, 255,255,255));

	Graphics gpWnd(hDCWnd);

	Pen pen(Color(255, 255, 0, 0));
	Pen penGreen(Color(255, 0, 255, 0));
	GraphicsPath path(FillModeWinding);

	int nStart = 0;
	int nSweep = -180;

	int nDrawWidth = nWidth / 2;
	int nDrawHeight = nHeight / 2;
	int nLineLen = nWidth - (nDrawWidth)/2 * 2;
	int nLineHeight = nHeight - (nDrawHeight)/2 * 2;

	int nLineY1 = 0;
	int nLineY2 = nHeight - 1;
	int nLineX1 = 0;
	int nLineX2 = nWidth -1;
	int n = 0;

	path.AddArc(0, 0, nDrawWidth, nDrawHeight, 180, 90);	//左上角

	path.AddArc(nWidth / 2, 0, nDrawWidth, nDrawHeight, -90, 90);		//右上角
	path.AddArc(nWidth / 2, nHeight - nDrawHeight, nDrawWidth, nDrawHeight, 0, 90);	//右下角
	path.AddArc(0, nHeight - nDrawHeight, nDrawWidth, nDrawHeight, 90, 90);	//左下角
	gpDist.SetSmoothingMode(SmoothingModeHighSpeed);

	gpDist.SetClip(&path);
	gpDist.DrawImage(imgShow, 0, 0);
	delete imgShow;

	gpWnd.SetSmoothingMode(SmoothingModeHighQuality);

	CLSID pngClsid;
	CGDIPUtil::GetEncoderClsid(L"image/png", &pngClsid);
	bm.Save(strPicSrc, &pngClsid, NULL);
	
}

HBITMAP CGDIPUtil::GetBitmapFromImage(tcpchar szPath, SIZE szPicSize )
{
	Gdiplus::Bitmap tempBmp(szPath);
	if (tempBmp.GetLastStatus() != Ok
		|| tempBmp.GetHeight() == 0
		|| tempBmp.GetWidth() == 0)
	{
		return NULL;
	}

	Color   backColor;
	HBITMAP   hBitmap = NULL;
	if (szPicSize.cx <= 0 || szPicSize.cy <= 0)
	{
		tempBmp.GetHBITMAP(backColor, &hBitmap);
	}
	else
	{
		Bitmap bmDest(szPicSize.cx, szPicSize.cy, PixelFormat32bppARGB); //新建缩放后的位图  
		if (bmDest.GetLastStatus() != Ok)
		{
			return hBitmap;
		}

		Graphics g(&bmDest);
		
		if (g.GetLastStatus() == Ok)
		{
			// 使用高质量模式(相对比较耗时)，可以查看msdn，替换为其他mode   
			g.SetInterpolationMode(InterpolationModeHighQualityBicubic);
			g.DrawImage(&tempBmp, 0, 0, szPicSize.cx, szPicSize.cy);
			bmDest.GetHBITMAP(backColor, &hBitmap);
		}
	}
	return hBitmap;
}

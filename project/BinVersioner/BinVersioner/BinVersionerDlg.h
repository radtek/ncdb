
// BinVersionerDlg.h : ͷ�ļ�
//

#pragma once
#include <string>
#include "..\..\..\sdk\PiTypeDef.h"
using namespace std;


struct tagMemBlock
{
	void* pMem;
	DWORD dwSize;
};
// CBinVersionerDlg �Ի���
class CBinVersionerDlg : public CDialog
{
// ����
public:
	CBinVersionerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BINVERSIONER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	tagMemBlock GetFileVersionData(const tstring& strPath);
};
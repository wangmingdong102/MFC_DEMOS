#pragma once
#include "afxcmn.h"
#include "MFCApplication1Dlg.h"
#include "YEJIAN2QIDLG.h"
#include "tchar.h"

// MAINDLG 对话框

class MAINDLG : public CDialogEx
{
	DECLARE_DYNAMIC(MAINDLG)

public:
	MAINDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MAINDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN_DIALOG };
#endif

protected:
	HICON m_hIcon;

	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg HCURSOR OnQueryDragIcon();
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRect m_DlgRect;
	void repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height);


	DECLARE_MESSAGE_MAP()
public:
	CMFCApplication1Dlg sYejian1Dlg;
	YEJIAN2QIDLG sYejian2Dlg;

	afx_msg void OnTcnSelchangeMainTab(NMHDR *pNMHDR, LRESULT *pResult);
	CTabCtrl sMainTab;
};

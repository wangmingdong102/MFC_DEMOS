
// MFCApplication1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// YEJIAN2QIDLG 对话框
class YEJIAN2QIDLG : public CDialogEx
{
// 构造
public:
	YEJIAN2QIDLG(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_YEJIAN2QI_DIALOG};
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CRect m_DlgRect;
	void repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height);

	DECLARE_MESSAGE_MAP()

	void YEJIAN2QIDLG::dropDownMenuTypeOne(UINT comboId);
	void YEJIAN2QIDLG::dropDownMenuTypeTwo(UINT comboId);
	void YEJIAN2QIDLG::dropDownMenuTypeThree(UINT comboId);
	void YEJIAN2QIDLG::dropDownMenuTypeFour(UINT comboId);

public:
	CComboBox sCombo101;
	CComboBox sCombo102;
	CEdit sEditS1MAX;
	CEdit sEditS1M;
	CEdit sEditL11;
	CEdit sEditL12;
	CEdit sEditN11;

	double sEditS1MAXValue;

	afx_msg void OnBnClickedMainframe();
};

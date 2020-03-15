
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

	int YEJIAN2QIDLG::getDropDownMenuTypeOneIndex(UINT comboId);
	int YEJIAN2QIDLG::getDropDownMenuTypeTwoIndex(UINT comboId);
	int YEJIAN2QIDLG::getDropDownMenuTypeThreeIndex(UINT comboId);
	int YEJIAN2QIDLG::getDropDownMenuTypeFourIndex(UINT comboId);

	void YEJIAN2QIDLG::gtkCompute(UINT C107_IN, UINT C108_IN,
		UINT L17_IN, UINT L18_IN,
		UINT Uk1_IN, UINT ST1_IN,
		UINT S17_IN, UINT N15_IN);
	void YEJIAN2QIDLG::gkyAndzbyCompute(UINT C111_IN,
		UINT Uk1_IN, UINT ST1_IN,
		UINT N14_IN);
	void YEJIAN2QIDLG::sdgCompute(
		UINT S12_IN, UINT S13_IN,
		UINT S22_IN, UINT S23_IN,
		UINT ST1_IN, UINT ST2_IN,
		UINT N11_IN);
	void YEJIAN2QIDLG::zhongjianbianliang();
	bool YEJIAN2QIDLG::checkInputValueInvalid();

public:
	CComboBox sCombo101;
	CComboBox sCombo102;
	CComboBox sCombo103;
	CComboBox sCombo104;
	CComboBox sCombo105;
	CComboBox sCombo106;
	CComboBox sCombo107;
	CComboBox sCombo108;
	CComboBox sCombo109;
	CComboBox sCombo110;
	CComboBox sCombo111;
	CComboBox sCombo211;
	CComboBox sCombo212;
	CComboBox sCombo213;
	CComboBox sCombo214;
	CComboBox sCombo215;
	CComboBox sCombo216;
	CComboBox sCombo217;
	CComboBox sCombo218;
	CComboBox sCombo219;
	CComboBox sCombo220;
	CComboBox sCombo221;

	CEdit sEditS1MAX;
	CEdit sEditS1M;
	CEdit sEditL11;
	CEdit sEditL12;
	CEdit sEditN11;

	double Xsmax = 0, Xsmin = 0;
	double ResultGTK[4] = { 0,0,0,0 };
	double ResultGTYANDZBY[4] = { 0,0,0,0 };
	double ResultSDG[4] = { 0,0,0,0 };
	double IopkXXdsxsd[6] = { 0,0,0,0 };
	//double sEditS1MAXValue;

	afx_msg void OnBnClickedMainframe();
};

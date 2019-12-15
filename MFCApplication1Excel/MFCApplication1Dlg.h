
// MFCApplication1Dlg.h : 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//常量
	double c_Sj = 100;
	double c_Xdianlan = 0.08;
	double c_Xjiakong = 0.4;

	//输入值
	double v_Ssmax;
	double v_Ssmin;
	double v_L1;
	double v_L2;
	double v_n1;
	double v_n2;
	double v_Un1;
	double v_Un2;
	double v_St;
	double v_Uk;

	//中间变量
	double t_Xsmax;
	double t_Xsmin;
	double t_XL1;
	double t_XL2;
	double t_Xt;
	double t_Xmax;
	double t_Xmin;
	double t_I1rt;
	double t_I2rt;
	double t_I2kmax;
	double t_I1k2min;
	double t_I22k2min;
	double t_I2k2min;

	//结果
	double r_Iopk1;
	double r_Iopk2;
	double r_Iopk3;
	
	afx_msg void OnEnChangeEditDefault();
	afx_msg void OnBnClickedButtonResult();
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};

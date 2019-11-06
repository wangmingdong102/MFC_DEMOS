
// MFCApplication1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置标题 nn_20190728
	CString customTitle;
	customTitle.LoadString(IDS_NIUNIU_TOOLS);
	SetWindowText(customTitle);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, v_Ssmax(1)
	, v_Ssmin(1)
	, v_L1(1)
	, v_L2(1)
	, v_n1(1)
	, v_n2(1)
	, v_Un1(1)
	, v_Un2(1)
	, v_St(1)
	, v_Uk(1)
	, r_Iopk1(1)
	, r_Iopk2(1)
	, r_Iopk3(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_NIUNIU_TOOLS_ICON);//更新应用图标

	CDialogEx::SetBackgroundImage(IDB_BITMAP1);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SSMAX, v_Ssmax);
	DDX_Text(pDX, IDC_EDIT_SSMIN, v_Ssmin);

	DDX_Text(pDX, IDC_EDIT_L1, v_L1);
	DDX_Text(pDX, IDC_EDIT_L2, v_L2);
	DDX_Text(pDX, IDC_EDIT_N1, v_n1);
	DDX_Text(pDX, IDC_EDIT_N2, v_n2);
	DDX_Text(pDX, IDC_EDIT_ST, v_St);
	DDX_Text(pDX, IDC_EDIT_UK, v_Uk);
	DDX_Text(pDX, IDC_EDIT_UN1, v_Un1);
	DDX_Text(pDX, IDC_EDIT_UN2, v_Un2);

}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


	ON_EN_CHANGE(IDC_EDIT_SSMAX, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_SSMIN, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_N1, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_N2, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_ST, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_UK, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_UN1, &CMFCApplication1Dlg::OnEnChangeEditDefault)
	ON_EN_CHANGE(IDC_EDIT_UN2, &CMFCApplication1Dlg::OnEnChangeEditDefault)

	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CMFCApplication1Dlg::OnBnClickedButtonResult)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

// nn_20190728 add
void InitConsoleWindow()
{
	int nCrt = 0;
	FILE* fp;
	AllocConsole();
	nCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	fp = _fdopen(nCrt, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
}
// nn_20190728 add

// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	// nn_20190728 add
	// 设置标题 
	CString customTitle;
	customTitle.LoadString(IDS_NIUNIU_TOOLS);
	SetWindowText(customTitle);

	// 打开终端窗口
	InitConsoleWindow();
	TRACE("init console window\n");
	printf("init console window\n");
	// nn_20190728 add

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		/*
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                                 //获取对话框长宽       
		CDC   dcBmp;                                           //定义并创建一个内存设备环境
		dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1);                 //载入资源中的IDB_BITMAP1图片
		BITMAP   m_bitmap;                                     //图片变量                
		bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中
		CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境  
																 //调用函数显示图片 StretchBlt显示形状可变
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
			m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
		*/
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEditDefault()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	//printf("DSZ OR XSG，请不要乱点，点击[计算]按钮即可\n");

}

void printCalculateResult2File(const char* value) {

	// 构造CFile对象，同时以创建和读写的方式打开文件E:\1.txt  
	CFile file(_T("d:\\整定计算结果.txt"), CFile::modeCreate | CFile::modeReadWrite | CFile::modeNoTruncate);

	// 将写入数据的缓存中每个字节都赋值为字符c   

	// 将数据写入到文件中   
	if (file) {
		file.SeekToEnd();
		file.Write(value, strlen(value));

		// 关闭文件   
		file.Close();
	}

	printf(value);
}

void CMFCApplication1Dlg::OnBnClickedButtonResult()
{
	char value[512] = { 0 };

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);

	//常量
	//double c_Sj = 100;
	//double c_Xdianlan = 0.08;
	//double c_Xjiakong = 0.4;

	//输入值
	//double v_Ssmax;
	//double v_Ssmin;
	//double v_L1;
	//double v_L2;
	//double v_n1;
	//double v_n2;
	//double v_Un1;
	//double v_Un2;
	//double v_St;
	//double v_Uk;

	//中间变量
	//double t_Xsmax;
	printCalculateResult2File("##################### START #####################\n");
	if (v_Ssmax != 0) {
		t_Xsmax = c_Sj / v_Ssmax;
	}
	sprintf_s(value, "Xsmax = Sj\/Ssmax = 100\/%f = %f\n", v_Ssmax, t_Xsmax);
	printCalculateResult2File(value);
	//double t_Xsmin;
	if (v_Ssmin != 0) {
		t_Xsmin = c_Sj / v_Ssmin;
	}
	sprintf_s(value, "Xsmin = Sj\/Ssmin = 100\/%f = %f\n", v_Ssmin, t_Xsmin);
	printCalculateResult2File(value);
	//double t_XL1;
	if (v_Un1 != 0) {
		t_XL1 = c_Xdianlan * v_L1 * c_Sj / (pow(v_Un1, 2));
	}
	sprintf_s(value, "XL1 = Xxianlan * L1 * Sj \/ Un1^2 = 0.08 * %f * 100 \/  %f^2 = %f\n", v_L1, v_Un1, t_XL1);
	printCalculateResult2File(value);
	//double t_XL2;
	if (v_Un1 != 0) {
		t_XL2 = c_Xjiakong * v_L2 * c_Sj / (pow(v_Un1, 2));
	}
	sprintf_s(value, "XL2 = Xjiakong * L2 * Sj \/ Un1^2 = 0.4 * %f * 100 \/  %f^2 = %f\n", v_L2, v_Un1, t_XL2);
	printCalculateResult2File(value);
	//double t_Xt;
	if (v_St != 0) {
		t_Xt = v_Uk / v_St;
	}
	sprintf_s(value, "Xt = \(Uk\/100\) * \(Sj\/St\) = %f \/ %f  = %f\n", v_Uk, v_St, t_Xt);
	printCalculateResult2File(value);
	//double t_Xmax;
	t_Xmax = t_Xsmax + t_XL1 + t_XL2 + t_Xt;
	sprintf_s(value, "Xmax = Xsmax + XL1 + XL2 + Xt = %f + %f + %f + %f = %f\n", t_Xsmax, t_XL1, t_XL2, t_Xt, t_Xmax);
	printCalculateResult2File(value);
	//double t_Xmin;
	t_Xmin = t_Xsmin + t_XL1 + t_XL2 + t_Xt;
	sprintf_s(value, "Xmin = Xsmin + XL1 + XL2 + Xt = %f + %f + %f + %f = %f\n", t_Xsmin, t_XL1, t_XL2, t_Xt, t_Xmin);
	printCalculateResult2File(value);
	//double t_I1rt;
	t_I1rt = v_St * 1000 / (sqrt(3) * v_Un1);
	sprintf_s(value, "I1rt = St * 1000 \/ \(sqrt(3) * Un1\) = %f * 1000 \/ sqrt\(3\) * %f = %f\n", v_St, v_Un1, t_I1rt);
	printCalculateResult2File(value);
	//double t_I2rt;
	t_I2rt = v_St * 1000 / (sqrt(3) * v_Un2);
	sprintf_s(value, "I2rt = St * 1000 \/ \(sqrt\(3\) * Un2\) = %f * 1000 \/ sqrt\(3\) * %f = %f\n", v_St, v_Un2, t_I2rt);
	printCalculateResult2File(value);
	//double t_I2kmax;
	t_I2kmax = (100 / (sqrt(3) * (1.05 * v_Un1))) * 1000 / t_Xmax;
	sprintf_s(value, "I2kmax = \(100 \/ \(sqrt\(3\) * \(1.05 * Un1\)\)\) * 1000 \/ Xmax = \(100 \/ \(sqrt\(3\) * \(1.05 * %f\)\)\) * 1000 / %f = %f\n", v_Un1, t_Xmax, t_I2kmax);
	printCalculateResult2File(value);
	//double t_I1k2min;
	t_I1k2min = 0.866 * (100 / (sqrt(3) * (1.05 * v_Un1))) * 1000 / (t_Xsmin + t_XL1 + t_XL2);
	sprintf_s(value, "I1k2min = 0.866 * \(100 \/ \(sqrt\(3\) * \(1.05 * Un1\)\)\) * 1000 \/ \(Xsmin + XL1 + XL2\) = 0.866 * \(100 \/ \(sqrt\(3\) * \(1.05 * %f\)\)\) * 1000 \/ \(%f + %f + %f\) = %f\n", v_Un1, t_Xsmin, t_XL1, t_XL2,t_I2kmax);
	printCalculateResult2File(value);
	//double t_I22k2min;
	t_I22k2min = 0.866 * (100 / (sqrt(3) * (1.05 * v_Un2))) * 1000  / t_Xmin;
	sprintf_s(value, "I22k2min = 0.866 * \(100 \/ \(sqrt\(3\) * \(1.05 * Un2\)\)\) * 1000 \/ Xmin = 0.866 * \(100 / \(sqrt\(3\) * \(1.05 * %f\)\)\) * 1000 \/ %f = %f\n", v_Un2, t_Xmin, t_I22k2min);
	printCalculateResult2File(value);
	//double t_I2k2min;
	t_I2k2min = 2 * t_I22k2min / (3.5 *sqrt(3));
	sprintf_s(value, "I2k2min = 2 * I22k2min \/ \(3.5 *sqrt\(3\)\) = 2 * %f \/ \(3.5 *sqrt\(3\)\) = %f\n", t_I22k2min, t_I2k2min);
	printCalculateResult2File(value);

	//结果
	//double r_Iopk1;
	r_Iopk1 = 1.05 * t_I1rt / (0.9 * v_n2);	
	sprintf_s(value, "Iopk1 = 1.05 * I1rt \/ \(0.9 * n2\) = 1.05 * %f \/ \(0.9 * %f\) = %f\n", t_I1rt, v_n2, r_Iopk1);
	printCalculateResult2File(value);
	//double r_Iopk2;
	r_Iopk2 = 1.2 * 1.4 * t_I1rt / (0.9 * v_n2);
	sprintf_s(value, "Iopk2 = 1.2 * 1.4 * I1rt \/ \(0.9 * vn2\) = 1.2 * 1.4 * %f \/ \(0.9 * %f\) = %f\n", t_I1rt, v_n2, r_Iopk2);
	printCalculateResult2File(value);
	double ksen2 = t_I2k2min / (r_Iopk2 * v_n2);
	sprintf_s(value, "ksen2 = I2k2min \/ \(Iopk2 * n2\) = %f \/ \(%f * %f\) = %f\n", t_I2k2min, r_Iopk2, v_n2, ksen2);
	printCalculateResult2File(value);
	//double r_Iopk3;
	r_Iopk3 = 1.3 * t_I2kmax / v_n2;
	sprintf_s(value, "Iopk3 = 1.3 * I2kmax \/ n2 = 1.3 * %f \/ %f = %f\n", t_I2kmax, v_n2, r_Iopk3);
	printCalculateResult2File(value);
	double ksen3 = t_I1k2min / (r_Iopk3 * v_n2);
	sprintf_s(value, "ksen3 = I1k2min \/ \(Iopk3 * n2\) = %f \/ \(%f * %f\) = %f\n", t_I1k2min, r_Iopk3, v_n2, ksen3);
	printCalculateResult2File(value);

	printCalculateResult2File("##################### END #####################\n\n");
}


void CMFCApplication1Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	printf("OnGetMinMaxInfo x:%d y:%d\n", lpMMI->ptMinTrackSize.x, lpMMI->ptMinTrackSize.y);

	lpMMI->ptMinTrackSize.x = 800;
	lpMMI->ptMinTrackSize.y = 800;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

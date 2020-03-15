
// YEJIAN2QIDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "YEJIAN2QIDLG.h"
#include "afxdialogex.h"




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框




// YEJIAN2QIDLG 对话框



YEJIAN2QIDLG::YEJIAN2QIDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_YEJIAN2QI_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_NIUNIU_TOOLS_ICON);//更新应用图标

	CDialogEx::SetBackgroundImage(IDB_YEJIAN2QI_BG, BACKGR_TOPLEFT, true);
	m_DlgRect.SetRect(0, 0, 0, 0);
}

void YEJIAN2QIDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_COMBO101, sCombo101);
	DDX_Control(pDX, IDC_COMBO102, sCombo102);
	DDX_Control(pDX, IDC_EDIT_S1MAX, sEditS1MAX);
	//DDX_Text(pDX, IDC_EDIT_S1MAX, sEditS1MAXValue);
	DDX_Control(pDX, IDC_EDIT_S1MIN, sEditS1M);
	DDX_Control(pDX, IDC_EDIT_L11, sEditL11);
	DDX_Control(pDX, IDC_EDIT_L12, sEditL12);
	DDX_Control(pDX, IDC_EDIT_N11, sEditN11);
	DDX_Control(pDX, IDC_COMBO103, sCombo103);
	DDX_Control(pDX, IDC_COMBO104, sCombo104);
	DDX_Control(pDX, IDC_COMBO105, sCombo105);
	DDX_Control(pDX, IDC_COMBO106, sCombo106);
	DDX_Control(pDX, IDC_COMBO107, sCombo107);
	DDX_Control(pDX, IDC_COMBO108, sCombo108);
	DDX_Control(pDX, IDC_COMBO109, sCombo109);
	DDX_Control(pDX, IDC_COMBO110, sCombo110);
	DDX_Control(pDX, IDC_COMBO111, sCombo111);
	DDX_Control(pDX, IDC_COMBO211, sCombo211);
	DDX_Control(pDX, IDC_COMBO212, sCombo212);
	DDX_Control(pDX, IDC_COMBO213, sCombo213);
	DDX_Control(pDX, IDC_COMBO214, sCombo214);
	DDX_Control(pDX, IDC_COMBO215, sCombo215);
	DDX_Control(pDX, IDC_COMBO216, sCombo216);
	DDX_Control(pDX, IDC_COMBO217, sCombo217);
	DDX_Control(pDX, IDC_COMBO218, sCombo218);
	DDX_Control(pDX, IDC_COMBO219, sCombo219);
	DDX_Control(pDX, IDC_COMBO220, sCombo220);
	DDX_Control(pDX, IDC_COMBO221, sCombo221);
}

BEGIN_MESSAGE_MAP(YEJIAN2QIDLG, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDR_MAINFRAME, &YEJIAN2QIDLG::OnBnClickedMainframe)
END_MESSAGE_MAP()

// nn_20190728 add
void InitConsoleWindowYEJIAN2QI()
{
	// debug start
// DEBUG OPEN
	int nCrt = 0;
	FILE* fp;
	AllocConsole();
	nCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);
	fp = _fdopen(nCrt, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
// DEBUG CLOSE
	//FreeConsole();
	// debug stop
}
// nn_20190728 add

// YEJIAN2QIDLG 消息处理程序

void YEJIAN2QIDLG::dropDownMenuTypeOne(UINT comboId) {
	CString strTemp;
	CComboBox* comboBox = NULL;

	comboBox = ((CComboBox*)GetDlgItem(comboId));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%3d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 240);
	comboBox->AddString(strTemp);
}

void YEJIAN2QIDLG::dropDownMenuTypeTwo(UINT comboId) {
	CString strTemp;
	CComboBox* comboBox = NULL;

	comboBox = ((CComboBox*)GetDlgItem(comboId));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%3d"), 50);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 70);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 95);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 120);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 150);
	comboBox->AddString(strTemp);
}
void YEJIAN2QIDLG::dropDownMenuTypeThree(UINT comboId) {
	CString strTemp;
	CComboBox* comboBox = NULL;

	comboBox = ((CComboBox*)GetDlgItem(comboId));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%3d"), 50);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 70);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%3d"), 95);
	comboBox->AddString(strTemp);
}
void YEJIAN2QIDLG::dropDownMenuTypeFour(UINT comboId) {
	CString strTemp;
	CComboBox* comboBox = NULL;

	comboBox = ((CComboBox*)GetDlgItem(comboId));
	comboBox->ResetContent();//消除现有所有内容
	strTemp = "Yyn";
	comboBox->AddString(strTemp);
	strTemp = "Dyn";
	comboBox->AddString(strTemp);
}

BOOL YEJIAN2QIDLG::OnInitDialog()
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
	InitConsoleWindowYEJIAN2QI();
	//TRACE("init console window\n");
	//printf("init console window\n");
	// nn_20190728 add

	dropDownMenuTypeOne(IDC_COMBO101);//1 
	dropDownMenuTypeOne(IDC_COMBO102);//2
	dropDownMenuTypeOne(IDC_COMBO211);//11
	dropDownMenuTypeOne(IDC_COMBO212);//12

	dropDownMenuTypeTwo(IDC_COMBO103);//3 
	dropDownMenuTypeTwo(IDC_COMBO104);//4
	dropDownMenuTypeTwo(IDC_COMBO213);//13
	dropDownMenuTypeTwo(IDC_COMBO214);//14

	dropDownMenuTypeTwo(IDC_COMBO105);//5
	dropDownMenuTypeTwo(IDC_COMBO106);//6
	dropDownMenuTypeTwo(IDC_COMBO215);//15
	dropDownMenuTypeTwo(IDC_COMBO216);//16

	dropDownMenuTypeThree(IDC_COMBO107);//7
	dropDownMenuTypeThree(IDC_COMBO108);//8
	dropDownMenuTypeThree(IDC_COMBO109);//9
	dropDownMenuTypeThree(IDC_COMBO110);//10
	dropDownMenuTypeThree(IDC_COMBO217);//17
	dropDownMenuTypeThree(IDC_COMBO218);//18
	dropDownMenuTypeThree(IDC_COMBO219);//19
	dropDownMenuTypeThree(IDC_COMBO220);//20

	dropDownMenuTypeFour(IDC_COMBO111);//11
	dropDownMenuTypeFour(IDC_COMBO221);//21

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}


// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void YEJIAN2QIDLG::OnPaint()
{
	/*
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
	*/
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



void YEJIAN2QIDLG::repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height)
//更新控件位置和大小函数，可以根据需要自行修改
{
	CRect rect;
	CWnd *wnd = NULL;
	wnd = GetDlgItem(id);
	if (NULL == wnd) {
		MessageBox(_T("相应控件不存在"));
	}
	wnd->GetWindowRect(&rect);
	ScreenToClient(&rect);
	double proportion_x = now_Width / (double)last_Width;
	double proportion_y = now_Height / (double)last_Height;
	rect.left = (long)(rect.left*proportion_x + 0.5);
	rect.right = (long)(rect.right*proportion_x + 0.5);
	rect.top = (long)(rect.top *proportion_y + 0.5);
	rect.bottom = (long)(rect.bottom *proportion_y + 0.5);

	//printf("repaint %d %d %d\n", id, last_Width, now_Width);
	//printf("repaint %d %d %d\n", id, rect.Width(), rect.Height());

	wnd->MoveWindow(&rect);
}

void YEJIAN2QIDLG::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	//printf("OnSize cx %d %d\n", cx, cy);
	//TRACE("OnSize cx %d %d\n", cx, cy);

	if (m_DlgRect.left >= 0) {
		return;
	}

	//printf("OnSize left %d right %d\n", m_DlgRect.left, m_DlgRect.right);
	if (0 == m_DlgRect.left && 0 == m_DlgRect.right && 0 == m_DlgRect.top && 0 == m_DlgRect.bottom)
		//第一次启动对话框时的大小变化不做处理	
	{
		GetClientRect(&m_DlgRect); //save size of dialog
		//printf("OnSize Width %d Height %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	}
	if (0 == cx && 0 == cy)//如果是按下了最小化，则触发条件，这时不保存对话框数据		
	{
		return;
	}
	{
		CRect rectDlgChangeSize;
		GetClientRect(&rectDlgChangeSize);//存储对话框大小改变后对话框大小数据 		
		
		int woc;
		HWND  hwndChild = ::GetWindow(m_hWnd, GW_CHILD);
		while (hwndChild) {
			woc = ::GetDlgCtrlID(hwndChild);
			repaint(woc,
				m_DlgRect.Width(), 
				rectDlgChangeSize.Width(), 
				m_DlgRect.Height(), 
				rectDlgChangeSize.Height());

			hwndChild = ::GetWindow(hwndChild, GW_HWNDNEXT);
		}


		//repaint(IDC_EDIT_UN2, m_DlgRect.Width(), rectDlgChangeSize.Width(), m_DlgRect.Height(), rectDlgChangeSize.Height());
		//repaint(IDC_BUTTON_RESULT, m_DlgRect.Width(), rectDlgChangeSize.Width(), m_DlgRect.Height(), rectDlgChangeSize.Height());
	}
	GetClientRect(&m_DlgRect); //save size of dialog	
	//printf("OnSize %d %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	//TRACE("OnSize %d %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	
	Invalidate();//更新窗口
}
void YEJIAN2QIDLG::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	printf("OnGetMinMaxInfo x:%d y:%d\n", lpMMI->ptMinTrackSize.x, lpMMI->ptMinTrackSize.y);

	int cx, cy;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);	
	printf("OnGetMinMaxInfo cx:%d cy:%d\n", cx, cy);

	if (cx >= 1570) {
		lpMMI->ptMinTrackSize.x = 1570;
		lpMMI->ptMinTrackSize.y = 990;
	}
	else {
		lpMMI->ptMinTrackSize.x = cx;
		lpMMI->ptMinTrackSize.y = cy;
	}
	lpMMI->ptMaxTrackSize.x = cx;
	lpMMI->ptMaxTrackSize.y = cy;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

int YEJIAN2QIDLG::getDropDownMenuTypeOneIndex(UINT comboId) {
	CString cstr;
	GetDlgItem(comboId)->GetWindowText(cstr);
	//double editValue = _wtof(cstr);
	//printf("getDropDownMenuTypeOneIndex cstr:%S\n", cstr);

	if (150 == _wtoi(cstr)) {
		return 0;
	}
	else if (185 == _wtoi(cstr)) {
		return 1;
	}
	else if (240 == _wtoi(cstr)) {
		return 2;
	}
	else {
		return -1;
	}
}
int YEJIAN2QIDLG::getDropDownMenuTypeTwoIndex(UINT comboId) {
	CString cstr;
	GetDlgItem(comboId)->GetWindowText(cstr);
	//double editValue = _wtof(cstr);
	//printf("getDropDownMenuTypeTwoIndex cstr:%S\n", cstr);

	if (50 == _wtoi(cstr)) {
		return 0;
	}
	else if (70 == _wtoi(cstr)) {
		return 1;
	}
	else if (95 == _wtoi(cstr)) {
		return 2;
	}
	else if (120 == _wtoi(cstr)) {
		return 3;
	}
	else if (150 == _wtoi(cstr)) {
		return 4;
	}
	else {
		return -1;
	}
}
int YEJIAN2QIDLG::getDropDownMenuTypeThreeIndex(UINT comboId) {
	CString cstr;
	GetDlgItem(comboId)->GetWindowText(cstr);
	//double editValue = _wtof(cstr);
	//printf("getDropDownMenuTypeThreeIndex cstr:%S\n", cstr);

	if (50 == _wtoi(cstr)) {
		return 0;
	}
	else if (70 == _wtoi(cstr)) {
		return 1;
	}
	else if (95 == _wtoi(cstr)) {
		return 2;
	}
	else {
		return -1;
	}
}
int YEJIAN2QIDLG::getDropDownMenuTypeFourIndex(UINT comboId) {
	CString cstr;
	GetDlgItem(comboId)->GetWindowText(cstr);
	//double editValue = _wtof(cstr);
	printf("getDropDownMenuTypeFourIndex cstr:%S\n", cstr);

	if ("Yyn" == cstr) {
		return 0;
	}
	else if ("Dyn" == cstr) {
		return 1;
	}
	else {
		return -1;
	}
}

double getMaxValueOfArray(double* pValue, int count) {
	double value = pValue[0];
	printf("getMaxValueOfArray count:%d\n", count);
	for (int i = 1; i < count; i++) {
		value = (pValue[i] > value) ? pValue[i] : value;
	}
	return value;
}
double getMinValueOfArray(double* pValue, int count) {
	double value = pValue[0];
	for (int i = 1; i < count; i++) {
		value = (pValue[i] < value) ? pValue[i] : value;
	}
	return value;
}

/*
* 贯通馈,自闭馈计算 
*/
void YEJIAN2QIDLG::gtkCompute(UINT C107_IN, UINT C108_IN,
	UINT L17_IN, UINT L18_IN,
	UINT Uk1_IN, UINT ST1_IN,
	UINT S17_IN, UINT N15_IN) {
	double Sj = 100;
	// 贯通馈一
	double R17 = 0, X17 = 0;
	double R18 = 0, X18 = 0;
	int index = getDropDownMenuTypeThreeIndex(C107_IN);
	//printf("C107_IN index:%d\n", index);
	if (index == 0) {
		R17 = 0.409;
		X17 = 0.097;
	}
	else if (index == 1) {
		R17 = 0.292;
		X17 = 0.091;
	}
	else if (index == 2) {
		R17 = 0.215;
		X17 = 0.087;
	}
	else {
		printf("贯通馈 未选择\n");
	}
	index = getDropDownMenuTypeThreeIndex(C108_IN);
	//printf("C108_IN index:%d\n", index);
	if (index == 0) {
		R18 = 0.38;
		X18 = 0.34;
	}
	else if (index == 1) {
		R18 = 0.27;
		X18 = 0.33;
	}
	else if (index == 2) {
		R18 = 0.20;
		X18 = 0.32;
	}
	else {
		printf("贯通馈 未选择\n");
	}
	double X1gtk1 = 0, R1gtk1 = 0;
	double XT1 = 0;
	double I2k2min17 = 0;
	double Iopk17gdl = 0;
	double Ksen17gdl = 0;
	double Ik2max17 = 0; 
	double I1k2min17 = 0;
	double Iopk17wsxsd = 0; 
	double Ksen17wsxsd = 0;
	double L17 = 0, L18 = 0;
	double Uk1 = 0, ST1 = 0;
	double S17 = 0;
	double n15 = 0;
	CString cstr;
	double editValue = 0;
	((CEdit*)GetDlgItem(L17_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L17 = editValue;
	((CEdit*)GetDlgItem(L18_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L18 = editValue;
	((CEdit*)GetDlgItem(Uk1_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	Uk1 = editValue;
	((CEdit*)GetDlgItem(ST1_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	ST1 = editValue;
	((CEdit*)GetDlgItem(S17_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S17 = editValue;
	((CEdit*)GetDlgItem(N15_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	n15 = editValue;

	X1gtk1 = X18 * L18 + X17 * L17;
	R1gtk1 = R18 * L18 + R17 * L17;
	XT1 = Uk1 * 10 * Sj / ST1;
	I2k2min17 = 0.866 *5.5 * 1000 / sqrt(pow((Xsmax+ X1gtk1+XT1),2)+pow(R1gtk1,2));
	//result:
	Iopk17gdl = 0.07698 * S17 / n15;
	Ksen17gdl = I2k2min17 / (Iopk17gdl * n15);

	Ik2max17 = 5.5 *1000 / sqrt(pow((Xsmin + X1gtk1 + XT1), 2) + pow(R1gtk1, 2));
	I1k2min17 = 0.866 * 5.5 * 1000 / sqrt(pow((Xsmax + XT1),2));
	//result
	Iopk17wsxsd = 1.2 * I2k2min17 / n15;
	Ksen17wsxsd = I1k2min17 / (Iopk17wsxsd * n15);

	ResultGTK[0] = Iopk17gdl;
	ResultGTK[1] = Ksen17gdl;
	ResultGTK[2] = Iopk17wsxsd;
	ResultGTK[3] = Ksen17wsxsd;
}

/*
* 贯通压,自闭压计算
*/
void YEJIAN2QIDLG::gkyAndzbyCompute(UINT C111_IN,
	UINT Uk1_IN, UINT ST1_IN,
	UINT N14_IN) {

	double Sj = 100;
	CString cstr;
	double editValue = 0;

	double XT1 = 0;
	double Uk1 = 0, ST1 = 0;
	double n14 = 0;

	double I2k2min14 = 0;


	((CEdit*)GetDlgItem(N14_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	n14 = editValue;
	((CEdit*)GetDlgItem(Uk1_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	Uk1 = editValue;
	((CEdit*)GetDlgItem(ST1_IN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	ST1 = editValue;

	XT1 = Uk1 * 10 * Sj / ST1;

	int index = getDropDownMenuTypeFourIndex(C111_IN);
	//printf("C111_IN index:%d\n", index);
	if (index == 0) {
		I2k2min14 = 0.866 * 5.5 * 1000 / (Xsmax + XT1);
	}
	else if (index == 1) {
		I2k2min14 = 0.866 * 5.5 * 2 * 1000 / (sqrt(3) * (Xsmax + XT1));
	}
	else {
		printf("贯通压,自闭压 未选择\n");
	}

	double Iopk14gfh = 0.067359 * ST1 / n14;

	// result
	double Iopk14gdl = 1.2 * 1.4 * ST1 / (10 * sqrt(3) * 0.9 * n14);
	double Ksen14gdl = I2k2min14 / (Iopk14gdl * n14);

	double I2kmax14 = 5.5 * 1000 / (Xsmin + XT1);
	double I1k2min14 = 0.866 * 5.5 * 1000 / Xsmax;

	//result
	double Iopk14sd = 1.3 * I2kmax14 / n14;
	double Ksen14sd = I1k2min14 / (Iopk14sd * n14);

	ResultGTYANDZBY[0] = Iopk14gdl;
	ResultGTYANDZBY[1] = Ksen14gdl;
	ResultGTYANDZBY[2] = Iopk14sd;
	ResultGTYANDZBY[3] = Ksen14sd;
}

void YEJIAN2QIDLG::sdgCompute(
	UINT S12_IN,UINT S13_IN,
	UINT S22_IN, UINT S23_IN,
	UINT ST1_IN, UINT ST2_IN,
	UINT N11_IN) {
	CString cstr;
	double S12 = 0, S13 = 0;
	double S22 = 0, S23 = 0;
	double ST1 = 0, ST2 = 0;
	double n11 = 0;

	((CEdit*)GetDlgItem(S12_IN))->GetWindowText(cstr);
	S12 = _wtof(cstr);
	((CEdit*)GetDlgItem(S13_IN))->GetWindowText(cstr);
	S13 = _wtof(cstr);
	((CEdit*)GetDlgItem(S22_IN))->GetWindowText(cstr);
	S22 = _wtof(cstr);
	((CEdit*)GetDlgItem(S23_IN))->GetWindowText(cstr);
	S23 = _wtof(cstr);
	((CEdit*)GetDlgItem(ST1_IN))->GetWindowText(cstr);
	ST1 = _wtof(cstr);
	((CEdit*)GetDlgItem(ST2_IN))->GetWindowText(cstr);
	ST2 = _wtof(cstr);
	((CEdit*)GetDlgItem(N11_IN))->GetWindowText(cstr);
	n11 = _wtof(cstr);

	double I2k2min11 = 0.866 * 5.5 * 1000 / Xsmax;
	//result
	double Iopk11gdl = 0.07698 * (S12 + S13 + ST1 + S22 + S23 + ST2) / n11;
	double Ksen11gdl = I2k2min11 / (Iopk11gdl * n11);

	double I3kmax11 = getMaxValueOfArray(IopkXXdsxsd, (sizeof(IopkXXdsxsd)/sizeof(double)));
	double I1k2min11 = 0.866 * 5.5 * 1000 / Xsmax;
	//result
	double Iopk11dsxsd = 1.2 * I3kmax11 / n11;
	printf("I3kmax11:%f Iopk11dsxsd:%f\n", I1k2min11, I1k2min11);
	printf("n11:%f Iopk11dsxsd:%f\n", n11, Iopk11dsxsd);
	double Ksen11dsxsd = I1k2min11 / (Iopk11dsxsd * n11);

	ResultSDG[0] = Iopk11gdl;
	ResultSDG[1] = Ksen11gdl;
	ResultSDG[2] = Iopk11dsxsd;
	ResultSDG[3] = Ksen11dsxsd;
}

/*
* 中间变量
*/ 
void YEJIAN2QIDLG::zhongjianbianliang()
{
	double Sj = 100;

	double R11 = 0, X11 = 0;//电缆
	double R12 = 0, X12 = 0;//架空
	double R21 = 0, X21 = 0;
	double R22 = 0, X22 = 0;
	double S1max = 0, S1min = 0;
	double S2max = 0, S2min = 0;
	double L11 = 0, L12 = 0;
	double L21 = 0, L22 = 0;
	double X1smax = 0, X1smin = 0;
	double X2smax = 0, X2smin = 0;
	
	double X1dy1 = 0, X1dy2 = 0;
	double R1dy1 = 0, R1dy2 = 0;

	//double Xsmax = 0, Xsmin = 0;

	// 站馈一
	double R13 = 0, X13 = 0;
	double R14 = 0, X14 = 0;
	double L13 = 0, L14 = 0;
	double S12 = 0, n12 = 0;
	double X1zk1 = 0, R1zk1 = 0;
	double I2k2min12 = 0;
	double Iopk12gdl = 0;
	double Ksen12gdl = 0;
	double I3kmax12 = 0, I1k2min12 = 0;
	double Uk121 = 0, S121 = 0;
	double Iopk12dsxsd = 0, Ksen12dsxsd = 0;

	// 站馈二
	double R23 = 0, X23 = 0;
	double R24 = 0, X24 = 0;
	double L23 = 0, L24 = 0;
	double S22 = 0, n22 = 0;
	double X1zk2 = 0, R1zk2 = 0;
	double I2k2min22 = 0;
	double Iopk22gdl = 0;
	double Ksen22gdl = 0;
	double I3kmax22 = 0, I1k2min22 = 0;
	double Uk221 = 0, S221 = 0;
	double Iopk22dsxsd = 0, Ksen22dsxsd = 0;

	// 站馈三
	double R15 = 0, X15 = 0;
	double R16 = 0, X16 = 0;
	double L15 = 0, L16 = 0;
	double S13 = 0, n13 = 0;
	double X1zk3 = 0, R1zk3 = 0;
	double I2k2min13 = 0;
	double Iopk13gdl = 0;
	double Ksen13gdl = 0;
	double I3kmax13 = 0, I1k2min13 = 0;
	double Uk131 = 0, S131 = 0;
	double Iopk13dsxsd = 0, Ksen13dsxsd = 0;

	// 站馈四
	double R25 = 0, X25 = 0;
	double R26 = 0, X26 = 0;
	double L25 = 0, L26 = 0;
	double S23 = 0, n23 = 0;
	double X1zk4 = 0, R1zk4 = 0;
	double I2k2min23 = 0;
	double Iopk23gdl = 0;
	double Ksen23gdl = 0;
	double I3kmax23 = 0, I1k2min23 = 0;
	double Uk231 = 0, S231 = 0;
	double Iopk23dsxsd = 0, Ksen23dsxsd = 0;


	printf("Start...\n");
	int index = getDropDownMenuTypeOneIndex(IDC_COMBO101);
	if (index == 0) {
		R11 = 0.137;
		X11 = 0.084;
	}
	else if (index == 1) {
		R11 = 0.11;
		X11 = 0.082;
	}
	else if (index == 2) {
		R11 = 0.086;
		X11 = 0.079;
	}
	printf("R11:%f X11:%f\n", R11, X11);

	index = getDropDownMenuTypeOneIndex(IDC_COMBO102);
	if (index == 0) {
		R12 = 0.13;
		X12 = 0.31;
	}
	else if (index == 1) {
		R12 = 0.1;
		X12 = 0.3;
	}
	else if (index == 2) {
		R12 = 0.08;
		X12 = 0.29;
	}
	printf("R12:%f X12:%f\n", R12, X12);

	index = getDropDownMenuTypeOneIndex(IDC_COMBO211);
	if (index == 0) {
		R21 = 0.137;
		X21 = 0.084;
	}
	else if (index == 1) {
		R21 = 0.11;
		X21 = 0.082;
	}
	else if (index == 2) {
		R21 = 0.086;
		X21 = 0.079;
	}
	printf("R21:%f X21:%f\n", R21, X21);

	index = getDropDownMenuTypeOneIndex(IDC_COMBO212);
	if (index == 0) {
		R22 = 0.13;
		X22 = 0.31;
	}
	else if (index == 1) {
		R22 = 0.1;
		X22 = 0.3;
	}
	else if (index == 2) {
		R22 = 0.08;
		X22 = 0.29;
	}
	printf("R22:%f X22:%f\n", R22, X22);

	CString cstr;
	double editValue = 0;

	((CEdit*)GetDlgItem(IDC_EDIT_S1MAX))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S1max = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_S1MIN))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S1min = editValue;
	printf("S1max:%f S1min:%f\n", S1max, S1min);
	((CEdit*)GetDlgItem(IDC_EDIT_S2max))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S2max = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_S2min))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S2min = editValue;
	printf("S2max:%f S2min:%f\n", S2max, S2min);

	((CEdit*)GetDlgItem(IDC_EDIT_L11))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L11 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_L12))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L12 = editValue;
	printf("L11:%f L12:%f\n", L11, L12);
	((CEdit*)GetDlgItem(IDC_EDIT_L21))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L21 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_L22))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L22 = editValue;
	printf("L21:%f L22:%f\n", L21, L22);

	X1smax = Sj / S1max;
	X1smin = Sj / S1min;
	X2smax = Sj / S2max;
	X2smin = Sj / S2min;
	printf("X1smax:%f X1smin:%f\n", X1smax, X1smin);
	printf("X2smax:%f X2smin:%f\n", X2smax, X2smin);

	X1dy1 = X12 * L12 + X11 * L11;
	X1dy2 = X22 * L22 + X21 * L21;
	R1dy1 = R12 * L12 + R11 * L11;
	R1dy2 = R22 * L22 + R21 * L21;
	printf("X1dy1:%f X1dy2:%f\n", X1dy1, X1dy2);
	printf("R1dy1:%f R1dy2:%f\n", R1dy1, R1dy2);

	double V1 = sqrt(pow((X1smax + X1dy1), 2) + pow((0 + R1dy1), 2));
	double V2 = sqrt(pow((X2smax + X1dy2), 2) + pow((0 + R1dy2), 2));
	double V3 = sqrt(pow((X2smin + X1dy2), 2) + pow((0 + R1dy2), 2));
	double V4 = sqrt(pow((X1smax + X1dy1), 2) + pow((0 + R1dy1), 2));
	double vValues[4] = {V1, V2, V3, V4};
	printf("V1:%f V2:%f\n", V1, V2);
	printf("V3:%f V4:%f\n", V3, V4);
	Xsmax = getMinValueOfArray(vValues, sizeof(vValues)/sizeof(double));
	Xsmin = getMaxValueOfArray(vValues, sizeof(vValues)/sizeof(double));
	printf("Xsmax:%f Xsmin:%f\n", Xsmax, Xsmin);

	// 站馈一
	index = getDropDownMenuTypeTwoIndex(IDC_COMBO103);
	printf("站馈一 C103 index:%d\n", index);
	if (index == 0) {
		R13 = 0.409;
		X13 = 0.097;
	}
	else if (index == 1) {
		R13 = 0.292;
		X13 = 0.091;
	}
	else if (index == 2) {
		R13 = 0.215;
		X13 = 0.087;
	}
	else if (index == 3) {
		R13 = 0.17;
		X13 = 0.087;
	}
	else if (index == 4) {
		R13 = 0.137;
		X13 = 0.084;
	}
	printf("R13:%f X13:%f\n", R13, X13);

	index = getDropDownMenuTypeTwoIndex(IDC_COMBO104);
	printf("站馈一 C104 index:%d\n", index);
	if (index == 0) {
		R14 = 0.38;
		X14 = 0.34;
	}
	else if (index == 1) {
		R14 = 0.27;
		X14 = 0.33;
	}
	else if (index == 2) {
		R14 = 0.20;
		X14 = 0.32;
	}
	else if (index == 3) {
		R14 = 0.16;
		X14 = 0.31;
	}
	else if (index == 4) {
		R14 = 0.13;
		X14 = 0.31;
	}
	printf("R14:%f X14:%f\n", R14, X14);

	((CEdit*)GetDlgItem(IDC_EDIT_L13))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L13 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_L14))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L14 = editValue;
	printf("L13:%f L14:%f\n", L13, L14);
	((CEdit*)GetDlgItem(IDC_EDIT_S12))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S12 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_N12))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	n12 = editValue;
	printf("S12:%f n12:%f\n", S12, n12);
	X1zk1 = X14 * L14 + X13 * L13;
	R1zk1 = R14 * L14 + R13 * L13;
	I2k2min12 = (0.866*5.5*1000) / sqrt((pow((Xsmax + X1zk1), 2) + pow(R1zk1, 2)));
	Iopk12gdl = 0.07698 * S12 / n12;
	Ksen12gdl = I2k2min12 / (Iopk12gdl * n12);
	printf("X1zk1:%f R1zk1:%f\n", X1zk1, R1zk1);
	printf("I2k2min12:%f Iopk12gdl:%f Ksen12gdl:%f\n", 
		I2k2min12, Iopk12gdl, Ksen12gdl);

	((CEdit*)GetDlgItem(IDC_EDIT_Uk121))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	Uk121 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_S121))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S121 = editValue;
	printf("Uk121:%f S121:%f\n", Uk121, S121);
	I3kmax12 = 5.5 * 1000 / sqrt(pow((Xsmin + X1zk1 + (10 * Uk121 * Sj) / S121 ), 2) + pow(R1zk1, 2));
	I1k2min12 = (0.866 * 5.5 * 1000) / Xsmax;

	Iopk12dsxsd = 1.2 * I3kmax12 / n12;
	printf("I3kmax12:%f I1k2min12:%f\n", I3kmax12, I1k2min12);
	printf("n12:%f Iopk12dsxsd:%f\n", n12, Iopk12dsxsd);
	Ksen12dsxsd = I1k2min12 / (Iopk12dsxsd * n12);



	// 站馈二
	index = getDropDownMenuTypeTwoIndex(IDC_COMBO213);
	printf("站馈二 C213 index:%d\n", index);
	if (index == 0) {
		R23 = 0.409;
		X23 = 0.097;
	}
	else if (index == 1) {
		R23 = 0.292;
		X23 = 0.091;
	}
	else if (index == 2) {
		R23 = 0.215;
		X23 = 0.087;
	}
	else if (index == 3) {
		R23 = 0.17;
		X23 = 0.087;
	}
	else if (index == 4) {
		R23 = 0.137;
		X23 = 0.084;
	}
	printf("R23:%f X23:%f\n", R23, X23);

	index = getDropDownMenuTypeTwoIndex(IDC_COMBO214);
	printf("站馈二 C214 index:%d\n", index);
	if (index == 0) {
		R24 = 0.38;
		X24 = 0.34;
	}
	else if (index == 1) {
		R24 = 0.27;
		X24 = 0.33;
	}
	else if (index == 2) {
		R24 = 0.20;
		X24 = 0.32;
	}
	else if (index == 3) {
		R24 = 0.16;
		X24 = 0.31;
	}
	else if (index == 4) {
		R24 = 0.13;
		X24 = 0.31;
	}
	printf("R24:%f X24:%f\n", R24, X24);

	((CEdit*)GetDlgItem(IDC_EDIT_L23))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L23 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_L24))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L24 = editValue;
	printf("L23:%f L24:%f\n", L23, L24);
	((CEdit*)GetDlgItem(IDC_EDIT_S22))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S22 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_N22))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	n22 = editValue;
	printf("S22:%f n22:%f\n", S22, n22);
	X1zk2 = X24 * L24 + X23 * L23;
	R1zk2 = R24 * L24 + R23 * L23;
	I2k2min22 = (0.866*5.5 * 1000) / sqrt((pow((Xsmax + X1zk2), 2) + pow(R1zk2, 2)));
	Iopk22gdl = 0.07698 * S22 / n22;
	Ksen22gdl = I2k2min22 / (Iopk22gdl * n22);
	printf("X1zk2:%f R1zk2:%f\n", X1zk2, R1zk2);
	printf("I2k2min22:%f Iopk22gdl:%f Ksen22gdl:%f\n",
		I2k2min22, Iopk22gdl, Ksen22gdl);

	((CEdit*)GetDlgItem(IDC_EDIT_Uk221))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	Uk221 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_S221))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S221 = editValue;
	printf("Uk221:%f S221:%f\n", Uk221, S221);
	I3kmax22 = 5.5 * 1000 / sqrt(pow((Xsmin + X1zk2 + (10 * Uk221 * Sj) / S221), 2) + pow(R1zk2, 2));
	I1k2min22 = (0.866 * 5.5 * 1000) / Xsmax;

	Iopk22dsxsd = 1.2 * I3kmax22 / n22;
	printf("I3kmax22:%f I1k2min22:%f\n", I3kmax22, I1k2min22);
	printf("n22:%f Iopk22dsxsd:%f\n", n22, Iopk22dsxsd);
	Ksen22dsxsd = I1k2min22 / (Iopk22dsxsd * n22);



	// 站馈三
	index = getDropDownMenuTypeTwoIndex(IDC_COMBO105);
	if (index == 0) {
		R15 = 0.409;
		X15 = 0.097;
	}
	else if (index == 1) {
		R15 = 0.292;
		X15 = 0.091;
	}
	else if (index == 2) {
		R15 = 0.215;
		X15 = 0.087;
	}
	else if (index == 3) {
		R15 = 0.17;
		X15 = 0.087;
	}
	else if (index == 4) {
		R15 = 0.137;
		X15 = 0.084;
	}
	printf("R15:%f X15:%f\n", R15, X15);

	index = getDropDownMenuTypeTwoIndex(IDC_COMBO106);
	if (index == 0) {
		R16 = 0.38;
		X16 = 0.34;
	}
	else if (index == 1) {
		R16 = 0.27;
		X16 = 0.33;
	}
	else if (index == 2) {
		R16 = 0.20;
		X16 = 0.32;
	}
	else if (index == 3) {
		R16 = 0.16;
		X16 = 0.31;
	}
	else if (index == 4) {
		R16 = 0.13;
		X16 = 0.31;
	}
	printf("R16:%f X16:%f\n", R16, X16);

	((CEdit*)GetDlgItem(IDC_EDIT_L15))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L15 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_L16))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L16 = editValue;
	printf("L15:%f L16:%f\n", L15, L16);
	((CEdit*)GetDlgItem(IDC_EDIT_S13))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S13 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_N13))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	n13 = editValue;
	printf("S13:%f n13:%f\n", S13, n13);
	X1zk3 = X16 * L16 + X15 * L15;
	R1zk3 = R16 * L16 + R15 * L15;
	I2k2min13 = (0.866*5.5 * 1000) / sqrt((pow((Xsmax + X1zk3), 2) + pow(R1zk3, 2)));
	Iopk13gdl = 0.07698 * S13 / n13;
	Ksen13gdl = I2k2min13 / (Iopk13gdl * n13);
	printf("X1zk3:%f R1zk3:%f\n", X1zk3, R1zk3);
	printf("I2k2min13:%f Iopk13gdl:%f Ksen13gdl:%f\n",
		I2k2min13, Iopk13gdl, Ksen13gdl);

	((CEdit*)GetDlgItem(IDC_EDIT_Uk131))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	Uk131 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_S131))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S131 = editValue;
	printf("Uk131:%f S131:%f\n", Uk131, S131);
	I3kmax13 = 5.5 * 1000 / sqrt(pow((Xsmin + X1zk3 + (10 * Uk131 * Sj) / S131), 2) + pow(R1zk3, 2));
	I1k2min13 = (0.866 * 5.5 * 1000) / Xsmax;
	printf("I3kmax13:%f I1k2min13:%f\n", I3kmax13, I1k2min13);

	Iopk13dsxsd = 1.2 * I3kmax13 / n13;
	Ksen13dsxsd = I1k2min13 / (Iopk13dsxsd * n13);



	// 站馈四
	index = getDropDownMenuTypeTwoIndex(IDC_COMBO215);
	if (index == 0) {
		R25 = 0.409;
		X25 = 0.097;
	}
	else if (index == 1) {
		R25 = 0.292;
		X25 = 0.091;
	}
	else if (index == 2) {
		R25 = 0.215;
		X25 = 0.087;
	}
	else if (index == 3) {
		R25 = 0.17;
		X25 = 0.087;
	}
	else if (index == 4) {
		R25 = 0.137;
		X25 = 0.084;
	}
	printf("R25:%f X25:%f\n", R25, X25);

	index = getDropDownMenuTypeTwoIndex(IDC_COMBO216);
	if (index == 0) {
		R26 = 0.38;
		X26 = 0.34;
	}
	else if (index == 1) {
		R26 = 0.27;
		X26 = 0.33;
	}
	else if (index == 2) {
		R26 = 0.20;
		X26 = 0.32;
	}
	else if (index == 3) {
		R26 = 0.16;
		X26 = 0.31;
	}
	else if (index == 4) {
		R26 = 0.13;
		X26 = 0.31;
	}
	printf("R26:%f X26:%f\n", R26, X26);

	((CEdit*)GetDlgItem(IDC_EDIT_L25))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L25 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_L26))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	L26 = editValue;
	printf("L25:%f L26:%f\n", L25, L26);
	((CEdit*)GetDlgItem(IDC_EDIT_S23))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S23 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_N23))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	n23 = editValue;
	printf("S23:%f n23:%f\n", S23, n23);
	X1zk4 = X26 * L26 + X25 * L25;
	R1zk4 = R26 * L26 + R25 * L25;
	I2k2min23 = (0.866*5.5 * 1000) / sqrt((pow((Xsmax + X1zk4), 2) + pow(R1zk4, 2)));
	Iopk23gdl = 0.07698 * S23 / n23;
	Ksen23gdl = I2k2min23 / (Iopk23gdl * n23);
	printf("X1zk4:%f R1zk4:%f\n", X1zk4, R1zk4);
	printf("I2k2min23:%f Iopk23gdl:%f Ksen23gdl:%f\n",
		I2k2min23, Iopk23gdl, Ksen23gdl);

	((CEdit*)GetDlgItem(IDC_EDIT_Uk231))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	Uk231 = editValue;
	((CEdit*)GetDlgItem(IDC_EDIT_S231))->GetWindowText(cstr);
	editValue = _wtof(cstr);
	S231 = editValue;
	printf("Uk231:%f S231:%f\n", Uk231, S231);
	I3kmax23 = 5.5 * 1000 / sqrt(pow((Xsmin + X1zk4 + (10 * Uk231 * Sj) / S231), 2) + pow(R1zk4, 2));
	I1k2min23 = (0.866 * 5.5 * 1000) / Xsmax;
	printf("I3kmax23:%f I1k2min23:%f\n", I3kmax23, I1k2min23);

	Iopk23dsxsd = 1.2 * I3kmax23 / n23;
	Ksen23dsxsd = I1k2min23 / (Iopk23dsxsd * n23);


	printf("站馈一\n");
	printf(" Iopk12gdl:%f\n", Iopk12gdl);
	printf(" Ksen12gdl:%f\n", Ksen12gdl);
	printf(" Iopk12dsxsd:%f\n", Iopk12dsxsd);
	printf(" Ksen12dsxsd:%f\n", Ksen12dsxsd);
	printf("站馈二\n");
	printf(" Iopk22gdl:%f\n", Iopk22gdl);
	printf(" Ksen22gdl:%f\n", Ksen22gdl);
	printf(" Iopk22dsxsd:%f\n", Iopk22dsxsd);
	printf(" Ksen22dsxsd:%f\n", Ksen22dsxsd);
	printf("站馈三\n");
	printf(" Iopk13gdl:%f\n", Iopk13gdl);
	printf(" Ksen13gdl:%f\n", Ksen13gdl);
	printf(" Iopk13dsxsd:%f\n", Iopk13dsxsd);
	printf(" Ksen13dsxsd:%f\n", Ksen13dsxsd);
	printf("站馈四\n");
	printf(" Iopk23gdl:%f\n", Iopk23gdl);
	printf(" Ksen23gdl:%f\n", Ksen23gdl);
	printf(" Iopk23dsxsd:%f\n", Iopk23dsxsd);
	printf(" Ksen23dsxsd:%f\n", Ksen23dsxsd);



	//贯通馈一
	gtkCompute(IDC_COMBO107, IDC_COMBO108,
		IDC_EDIT_L17, IDC_EDIT_L18,
		IDC_EDIT_Uk1, IDC_EDIT_ST1,
		IDC_EDIT_S17, IDC_EDIT_N15);
	printf("贯通馈一\n");
	printf(" Iopk17:%f\n", ResultGTK[0]);
	printf(" Ksen17gdl:%f\n", ResultGTK[1]);
	printf(" Iopk17wsxsd:%f\n", ResultGTK[2]);
	printf(" Ksen17wsxsd:%f\n", ResultGTK[3]);
	//贯通馈二
	gtkCompute(IDC_COMBO109, IDC_COMBO110,
		IDC_EDIT_L19, IDC_EDIT_L110,
		IDC_EDIT_Uk1, IDC_EDIT_ST1,
		IDC_EDIT_S18, IDC_EDIT_N16);
	printf("贯通馈二\n");
	printf(" Iopk18:%f\n", ResultGTK[0]);
	printf(" Ksen18gdl:%f\n", ResultGTK[1]);
	printf(" Iopk18wsxsd:%f\n", ResultGTK[2]);
	printf(" Ksen18wsxsd:%f\n", ResultGTK[3]);
	//自闭馈一
	gtkCompute(IDC_COMBO217, IDC_COMBO218,
		IDC_EDIT_L27, IDC_EDIT_L28,
		IDC_EDIT_Uk2, IDC_EDIT_ST2,
		IDC_EDIT_S27, IDC_EDIT_N25);
	printf("自闭馈一\n");
	printf(" Iopk27:%f\n", ResultGTK[0]);
	printf(" Ksen27gdl:%f\n", ResultGTK[1]);
	printf(" Iopk27wsxsd:%f\n", ResultGTK[2]);
	printf(" Ksen27wsxsd:%f\n", ResultGTK[3]);
	//自闭馈二
	gtkCompute(IDC_COMBO219, IDC_COMBO220,
		IDC_EDIT_L29, IDC_EDIT_L210,
		IDC_EDIT_Uk2, IDC_EDIT_ST2,
		IDC_EDIT_S28, IDC_EDIT_N26);
	printf("自闭馈二\n");
	printf(" Iopk28:%f\n", ResultGTK[0]);
	printf(" Ksen28gdl:%f\n", ResultGTK[1]);
	printf(" Iopk28wsxsd:%f\n", ResultGTK[2]);
	printf(" Ksen28wsxsd:%f\n", ResultGTK[3]);

	
	//贯通调压柜
	gkyAndzbyCompute(IDC_COMBO111,
		IDC_EDIT_Uk1, IDC_EDIT_ST1,
		IDC_EDIT_N14);
	printf("贯通调压柜\n");
	printf(" Iopk14gdl:%f\n", ResultGTYANDZBY[0]);
	printf(" Ksen14gdl:%f\n", ResultGTYANDZBY[1]);
	printf(" Iopk14sd:%f\n", ResultGTYANDZBY[2]);
	printf(" Ksen14sd:%f\n", ResultGTYANDZBY[3]);
	double Iopk14sd = ResultGTYANDZBY[2];

	//自闭调压柜
	gkyAndzbyCompute(IDC_COMBO221,
		IDC_EDIT_Uk2, IDC_EDIT_ST2,
		IDC_EDIT_N24);
	printf("自闭调压柜\n");
	printf(" Iopk24gdl:%f\n", ResultGTYANDZBY[0]);
	printf(" Ksen24gdl:%f\n", ResultGTYANDZBY[1]);
	printf(" Iopk24sd:%f\n", ResultGTYANDZBY[2]);
	printf(" Ksen24sd:%f\n", ResultGTYANDZBY[3]);
	double Iopk24sd = ResultGTYANDZBY[2];

	((CEdit*)GetDlgItem(IDC_EDIT_N14))->GetWindowText(cstr);
	double n14 = _wtof(cstr);
	((CEdit*)GetDlgItem(IDC_EDIT_N24))->GetWindowText(cstr);
	double n24 = _wtof(cstr);

	IopkXXdsxsd[0] = Iopk12dsxsd * n12;
	IopkXXdsxsd[1] = Iopk13dsxsd * n13;
	IopkXXdsxsd[2] = Iopk22dsxsd * n22;
	IopkXXdsxsd[3] = Iopk23dsxsd * n23;
	IopkXXdsxsd[4] = Iopk14sd * n14;
	IopkXXdsxsd[5] = Iopk24sd * n24;

	//受电一柜
	sdgCompute(
		 IDC_EDIT_S12,  IDC_EDIT_S13,
		 IDC_EDIT_S22,  IDC_EDIT_S23,
		 IDC_EDIT_ST1,  IDC_EDIT_ST2,
		 IDC_EDIT_N11);
	printf("受电一柜\n");
	printf(" Iopk11gdl:%f\n", ResultSDG[0]);
	printf(" Ksen11gdl:%f\n", ResultSDG[1]);
	printf(" Iopk11sd:%f\n", ResultSDG[2]);
	printf(" Ksen11sd:%f\n", ResultSDG[3]);

	//受电二柜
	sdgCompute(
		IDC_EDIT_S12, IDC_EDIT_S13,
		IDC_EDIT_S22, IDC_EDIT_S23,
		IDC_EDIT_ST1, IDC_EDIT_ST2,
		IDC_EDIT_N21);
	printf("受电二柜\n");
	printf(" Iopk21gdl:%f\n", ResultSDG[0]);
	printf(" Ksen21gdl:%f\n", ResultSDG[1]);
	printf(" Iopk21sd:%f\n", ResultSDG[2]);
	printf(" Ksen21sd:%f\n", ResultSDG[3]);
}

bool YEJIAN2QIDLG::checkInputValueInvalid() {
	CString cstr;

		CWnd *pChild = this->GetWindow(GW_CHILD);
		TCHAR szClassName[255] = { 0 };
		while (pChild)
		{
				//获得类名
				GetClassName(pChild->GetSafeHwnd(), szClassName, 255);
				HWND p = pChild->m_hWnd;
				int m_ID = ::GetDlgCtrlID(p);

				if (_tcsicmp(szClassName, _T("Edit")) == 0) {
					printf("checkInputValueInvalid EDIT id:%d %S\n", m_ID, szClassName);

					((CEdit*)GetDlgItem(m_ID))->GetWindowText(cstr);
					printf("checkInputValueInvalid EDIT value:%S\n", cstr);

					if (cstr.IsEmpty()) {
						printf("checkInputValueInvalid EDIT empty\n");
						MessageBox(_T("文本框未输入有效数据"));
						return true;
					}
					if (cstr.SpanIncluding(_T("0123456789")) != cstr) {
						printf("checkInputValueInvalid EDIT invalid\n");
						MessageBox(_T("文本框未输入有效数据，如：含非数字"));
						return true;
					}
				}
				else if (_tcsicmp(szClassName, _T("ComboBox")) == 0) {
					printf("checkInputValueInvalid ComboBox id:%d %S\n", m_ID, szClassName);
				
					printf("checkInputValueInvalid ComboBox index:%d\n",
						((CComboBox*)GetDlgItem(m_ID))->GetCurSel());

					if (((CComboBox*)GetDlgItem(m_ID))->GetCurSel() < 0) {
						printf("checkInputValueInvalid ComboBox empty\n");
						MessageBox(_T("下拉菜单未选择"));
						return true;
					}
				}

				pChild = pChild->GetWindow(GW_HWNDNEXT);
		}

	return false;
}

void YEJIAN2QIDLG::OnBnClickedMainframe()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(true);

	if (checkInputValueInvalid()) {
		return;
	}

	zhongjianbianliang();

	//GetDlgItem(IDC_COMBO101)->GetWindowText(cstr);
	//double editValue = _wtof(cstr);
	//printf("OnBnClickedMainframe IDC_COMBO101:%S\n", cstr);
	//printf("OnBnClickedMainframe IDC_COMBO101:%f\n", editValue);
	
	//((CEdit*)GetDlgItem(IDC_EDIT_S1MAX))->GetWindowText(cstr);
	//editValue = _wtof(cstr);
	//printf("OnBnClickedMainframe IDC_EDIT_S1MAX:%S\n", cstr);
	//printf("OnBnClickedMainframe IDC_EDIT_S1MAX:%f\n", editValue);


	//printf("OnBnClickedMainframe IDC_EDIT_S1MAX:%f\n", sEditS1MAXValue);
	

}

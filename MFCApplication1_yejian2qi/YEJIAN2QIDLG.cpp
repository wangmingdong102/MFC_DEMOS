
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
	DDX_Control(pDX, IDC_EDIT_S1MIN, sEditS1M);
	DDX_Control(pDX, IDC_EDIT_L11, sEditL11);
	DDX_Control(pDX, IDC_EDIT_L12, sEditL12);
	DDX_Control(pDX, IDC_EDIT_N11, sEditN11);
}

BEGIN_MESSAGE_MAP(YEJIAN2QIDLG, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()


	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
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

	CString strTemp;
	CComboBox* comboBox = NULL;
	//1 
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO101));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);
	//2
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO102));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);

	//11
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO211));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);
	//12
	comboBox = ((CComboBox*)GetDlgItem(IDC_COMBO212));
	comboBox->ResetContent();//消除现有所有内容
	strTemp.Format(_T("%d"), 150);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 185);
	comboBox->AddString(strTemp);
	strTemp.Format(_T("%d"), 240);
	comboBox->AddString(strTemp);

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
	printf("OnSize cx %d %d\n", cx, cy);
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


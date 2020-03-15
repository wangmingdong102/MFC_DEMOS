// MAINDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MAINDLG.h"
#include "afxdialogex.h"
#include "YEJIAN2QIDLG.h"
#include "MFCApplication1Dlg.h"

// MAINDLG 对话框

// ???????????? CAboutDlg ???

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ?????
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ??
	virtual BOOL OnInitDialog();
// ??
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

	// ???? nn_20190728
	CString customTitle;
	customTitle.LoadString(IDS_NIUNIU_TOOLS);
	SetWindowText(customTitle);

	return TRUE;  // ??????????,???? TRUE
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

IMPLEMENT_DYNAMIC(MAINDLG, CDialogEx)

MAINDLG::MAINDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MAIN_DIALOG, pParent)
{

}

MAINDLG::~MAINDLG()
{

	m_DlgRect.SetRect(0, 0, 0, 0);
}

void MAINDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MAIN_TAB, sMainTab);
}


BEGIN_MESSAGE_MAP(MAINDLG, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_NOTIFY(TCN_SELCHANGE, IDC_MAIN_TAB, &MAINDLG::OnTcnSelchangeMainTab)
	ON_WM_GETMINMAXINFO()
	ON_WM_SIZE()
END_MESSAGE_MAP()

void InitConsoleWindowMainDlg()
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
void MAINDLG::OnSysCommand(UINT nID, LPARAM lParam)
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

//??????????????????????
//???
HCURSOR MAINDLG::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL MAINDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// IDM_ABOUTBOX ???????????
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

	SetIcon(m_hIcon, TRUE);			// ?????
	SetIcon(m_hIcon, FALSE);		// ?????

	CString customTitle;
	customTitle.LoadString(IDS_NIUNIU_TOOLS);
	SetWindowText(customTitle);

	InitConsoleWindowMainDlg();

	sMainTab.InsertItem(0, _T("                整定計算A                "));
	sMainTab.InsertItem(1, _T("                整定計算B                "));

	sYejian1Dlg.Create(IDD_MFCAPPLICATION1_DIALOG, GetDlgItem(IDC_MAIN_TAB));
	sYejian2Dlg.Create(IDD_YEJIAN2QI_DIALOG, GetDlgItem(IDC_MAIN_TAB));

	//获得IDC_TABTEST客户区大小 
	CRect rs;
	sMainTab.GetClientRect(&rs);
	//调整子对话框在父窗口中的位置 
//	rs.top += 30;
//	rs.bottom -= 60;
//	rs.left += 1;
//	rs.right -= 2;

	//设置子对话框尺寸并移动到指定位置 
//	sYejian1Dlg.MoveWindow(&rs);
//	sYejian2Dlg.MoveWindow(&rs);

	//分别设置隐藏和显示 
	sYejian1Dlg.ShowWindow(true);
	sYejian2Dlg.ShowWindow(false);

	//设置默认的选项卡 
	sMainTab.SetCurSel(0);

	//printf("MAINDLG OnInitDialog tab w %d h %d\n", rs.Width(), rs.Height());

	GetClientRect(&rs);
	//printf("MAINDLG OnInitDialog this w %d h %d\n", rs.Width(), rs.Height());
//	if (rs.Width() < rs.Width() && rs.Width() > 0) {
//		OnSize(SIZE_RESTORED, rs.Width(), rs.Height());
//	}

	sMainTab.MoveWindow(&rs);

	rs.top += 30;
	rs.bottom -= 60;
	rs.left += 1;
	rs.right -= 2;
	sYejian1Dlg.MoveWindow(&rs);
	sYejian2Dlg.MoveWindow(&rs);

	return TRUE;
}

// MAINDLG 消息处理程序
void MAINDLG::OnTcnSelchangeMainTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int CurSel = sMainTab.GetCurSel();
	switch (CurSel){
	case 0:
		sYejian1Dlg.ShowWindow(true);
		sYejian2Dlg.ShowWindow(false);
		break;
	case 1:
		sYejian2Dlg.ShowWindow(true);
		sYejian1Dlg.ShowWindow(false);
		break;
	default:
		;
	}
	*pResult = 0;
}
void MAINDLG::repaint(UINT id, int last_Width, int now_Width, int last_Height, int now_Height)
//???????????,??????????
{
	CRect rect;
	CWnd *wnd = NULL;
	wnd = GetDlgItem(id);
	if (NULL == wnd) {
		MessageBox(_T("id not existed"));
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

void MAINDLG::OnSize(UINT nType, int cx, int cy)
{
	//printf("MAINDLG OnSize 1 cx %d %d\n", cx, cy);
	CDialogEx::OnSize(nType, cx, cy);
	//printf("MAINDLG OnSize 2 cx %d %d\n", cx, cy);
	//TRACE("OnSize cx %d %d\n", cx, cy);

	//printf("OnSize left %d right %d\n", m_DlgRect.left, m_DlgRect.right);
	if (0 == m_DlgRect.left && 0 == m_DlgRect.right && 0 == m_DlgRect.top && 0 == m_DlgRect.bottom)
		//??????????????????	
	{
		GetClientRect(&m_DlgRect); //save size of dialog
		//printf("OnSize Width %d Height %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	}
	if (SIZE_MINIMIZED == nType)    //防止最小化时程序崩溃
		return;

//	if (0 == cx && 0 == cy)//?????????,?????,??????????		
//	{
//		return;
//	}
	{
		CRect rect;
		GetClientRect(&rect);//????????????????? 		

		sMainTab.MoveWindow(&rect);

		rect.top += 30;
		sYejian1Dlg.MoveWindow(&rect);
		sYejian2Dlg.MoveWindow(&rect);

		//repaint(IDC_EDIT_UN2, m_DlgRect.Width(), rectDlgChangeSize.Width(), m_DlgRect.Height(), rectDlgChangeSize.Height());
		//repaint(IDC_BUTTON_RESULT, m_DlgRect.Width(), rectDlgChangeSize.Width(), m_DlgRect.Height(), rectDlgChangeSize.Height());
	}
	GetClientRect(&m_DlgRect); //save size of dialog	
	//printf("OnSize %d %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	//TRACE("OnSize %d %d\n", m_DlgRect.Width(), m_DlgRect.Height());
	
	Invalidate();//????
}

void MAINDLG::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: ?????????????/??????
	//printf("MAINDLG OnGetMinMaxInfo x:%d y:%d\n", lpMMI->ptMinTrackSize.x, lpMMI->ptMinTrackSize.y);

	int cx, cy;
	cx = GetSystemMetrics(SM_CXSCREEN);
	cy = GetSystemMetrics(SM_CYSCREEN);	
	//printf("MAINDLG OnGetMinMaxInfo cx:%d cy:%d\n", cx, cy);

	if (cx >= 1920) {
		lpMMI->ptMinTrackSize.x = 1920;
		lpMMI->ptMinTrackSize.y = 1080;
		lpMMI->ptMaxTrackSize.x = 1920;
		lpMMI->ptMaxTrackSize.y = 1080;
	}
	else {
		lpMMI->ptMinTrackSize.x = cx;
		lpMMI->ptMinTrackSize.y = cy;
		lpMMI->ptMaxTrackSize.x = cx;
		lpMMI->ptMaxTrackSize.y = cy;
	}

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}



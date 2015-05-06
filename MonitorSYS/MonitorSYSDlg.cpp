
// MonitorSYSDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BtnST.h"
#include "MonitorSYS.h"
#include "MonitorSYSDlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMonitorSYSDlg 对话框



CMonitorSYSDlg::CMonitorSYSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMonitorSYSDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMonitorSYSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTPROCESS, m_btprocess);
	DDX_Control(pDX, IDC_BTGOLD, m_btgold);
	DDX_Control(pDX, IDC_BTANTIMONY, m_btantimony);
	DDX_Control(pDX, IDC_BTCONTROL, m_btcontrol);
	DDX_Control(pDX, IDC_BTCONDITION, m_btcondition);
	DDX_Control(pDX, IDC_MINZOOM, m_btmin);

	DDX_Control(pDX, IDC_CANCEL, m_btcalcel);
	DDX_Control(pDX, IDC_TIMEUSED, m_usedtime);
	DDX_Control(pDX, IDC_LEBELCONDITION, m_workcondition);
	DDX_Control(pDX, IDC_TIME, m_time);
	DDX_Control(pDX, IDC_LABEL, m_label);
}

BEGIN_MESSAGE_MAP(CMonitorSYSDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_MINZOOM, &CMonitorSYSDlg::OnBnClickedMinzoom)
	ON_BN_CLICKED(IDC_CANCEL, &CMonitorSYSDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTGOLD, &CMonitorSYSDlg::OnBnClickedBtgold)
	ON_BN_CLICKED(IDC_BTPROCESS, &CMonitorSYSDlg::OnBnClickedBtprocess)
	ON_BN_CLICKED(IDC_BTANTIMONY, &CMonitorSYSDlg::OnBnClickedBtantimony)
	ON_BN_CLICKED(IDC_BTCONTROL, &CMonitorSYSDlg::OnBnClickedBtcontrol)
	ON_BN_CLICKED(IDC_BTCONDITION, &CMonitorSYSDlg::OnBnClickedBtcondition)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMonitorSYSDlg 消息处理程序

BOOL CMonitorSYSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	loginDlg.DoModal();
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

	// TODO:  在此添加额外的初始化代码
	m_brush.CreateSolidBrush(RGB(0, 122, 204));
	m_font.CreatePointFont(150, L"微软雅黑");
	m_font1.CreatePointFont(130, L"微软雅黑");
	m_font2.CreatePointFont(110, L"微软雅黑");

	setbtColor(&m_btmin, RGB(0, 122, 204));
	m_btmin.setfalseColor(RGB(255, 255, 0));
	m_btmin.SetFont(&m_font2);

	setbtColor(&m_btcalcel, RGB(0, 122, 204));
	m_btcalcel.setfalseColor(RGB(255, 255, 0));
	m_btcalcel.SetFont(&m_font2);

	setbtColor(&m_btprocess, RGB(0, 122, 204));
	m_btprocess.setfalseColor(RGB(255,255,0));
	m_btprocess.SetFont(&m_font1);
	setbtColor(&m_btgold, RGB(0, 122, 204));
	m_btgold.setfalseColor(RGB(255, 255, 0));
	m_btgold.SetFont(&m_font1);
	setbtColor(&m_btantimony, RGB(0, 122, 204));
	m_btantimony.setfalseColor(RGB(255, 255, 0));
	m_btantimony.SetFont(&m_font1);
	setbtColor(&m_btcontrol, RGB(0, 122, 204));
	m_btcontrol.setfalseColor(RGB(255, 255, 0));
	m_btcontrol.SetFont(&m_font1);
	setbtColor(&m_btcondition, RGB(0, 122, 204));
	m_btcondition.setfalseColor(RGB(255, 255, 0));
	m_btcondition.SetFont(&m_font1);

	setbtColor(&m_usedtime, RGB(0, 122, 204));
	m_usedtime.setfalseColor(RGB(255, 255, 0));
	m_usedtime.SetFont(&m_font2);

	setbtColor(&m_workcondition, RGB(0, 122, 204));
	m_workcondition.setfalseColor(RGB(255, 255, 0));
	m_workcondition.SetFont(&m_font2);

	setbtColor(&m_time, RGB(0, 122, 204));
	m_time.setfalseColor(RGB(255, 255, 0));
	m_time.SetFont(&m_font2);

	setbtColor(&m_label, RGB(0, 122, 204));
	m_label.setfalseColor(RGB(255, 255, 0));
	m_label.SetFont(&m_font2);

 	processDlg.Create(IDD_PROCESSDIAGRAM, this);
 	processDlg.SetWindowPos(NULL, 20, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
	processDlg.ShowWindow(SW_SHOW);
	m_btprocess.EnableWindow(FALSE);

	

	goldDlg.Create(IDD_GOLDDLG, this);
	goldDlg.SetWindowPos(NULL, 20, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

	antimonyDlg.Create(IDD_ANTIMONYDLG, this);
	antimonyDlg.SetWindowPos(NULL, 20, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

	optimizeCtrDlg.Create(IDD_OPTIMIZECTRDLG, this);
	optimizeCtrDlg.SetWindowPos(NULL, 20, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

	conditionDlg.Create(IDD_CONDITIONDLG, this);
	conditionDlg.SetWindowPos(NULL, 20, 100, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

	_tsetlocale(LC_ALL, _T("chs"));
	SetTimer(1, 100, NULL);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMonitorSYSDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMonitorSYSDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMonitorSYSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CMonitorSYSDlg::OnNcHitTest(CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	UINT   nHitTest = CDialog::OnNcHitTest(point);
	//   如果鼠标在窗口客户区，则返回标题条代号给Windows       
	//   使Windows按鼠标在标题条上类进行处理，即可单击移动窗口       
	return   (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
}


HBRUSH CMonitorSYSDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_DLG)  //给对话框的刷子上色，即给对话框设置背景颜色
		return   m_brush;   //返加浅绿色刷子
	if (nCtlColor == CTLCOLOR_STATIC) //设置静态文本框的背景为透明
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SelectObject(&m_font);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
void CMonitorSYSDlg::setbtColor(CButtonST *btst, COLORREF crColor, COLORREF textColor)
{
	btst->SetColor(0, crColor);
	btst->SetColor(2, crColor);
	btst->SetColor(1, textColor);
	btst->SetColor(3, textColor);
	btst->SetColor(4, crColor);
	btst->SetColor(5, crColor);
}

void CMonitorSYSDlg::OnBnClickedMinzoom()
{
	// TODO:  在此添加控件通知处理程序代码
	ShowWindow(SW_MINIMIZE);
}





void CMonitorSYSDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	exit(0);
}

void CMonitorSYSDlg::OnBnClickedBtprocess()
{
	// TODO:  在此添加控件通知处理程序代码

	m_btprocess.EnableWindow(FALSE);
	m_btgold.EnableWindow(TRUE);
	m_btantimony.EnableWindow(TRUE);
	m_btcontrol.EnableWindow(TRUE);
	m_btcondition.EnableWindow(TRUE);
	goldDlg.ShowWindow(SW_HIDE);
	antimonyDlg.ShowWindow(SW_HIDE);
	optimizeCtrDlg.ShowWindow(SW_HIDE);
	conditionDlg.ShowWindow(SW_HIDE);
	processDlg.ShowWindow(SW_SHOW);
	
}

void CMonitorSYSDlg::OnBnClickedBtgold()
{
	// TODO:  在此添加控件通知处理程序代码

	m_btgold.EnableWindow(FALSE);
	m_btprocess.EnableWindow(TRUE);
	m_btantimony.EnableWindow(TRUE);
	m_btcontrol.EnableWindow(TRUE);
	m_btcondition.EnableWindow(TRUE);
	goldDlg.ShowWindow(SW_SHOW);
	antimonyDlg.ShowWindow(SW_HIDE);
	optimizeCtrDlg.ShowWindow(SW_HIDE);
	conditionDlg.ShowWindow(SW_HIDE);
	processDlg.ShowWindow(SW_HIDE);
	
}





void CMonitorSYSDlg::OnBnClickedBtantimony()
{
	// TODO:  在此添加控件通知处理程序代码

	m_btgold.EnableWindow(TRUE);
	m_btprocess.EnableWindow(TRUE);
	m_btantimony.EnableWindow(FALSE);
	m_btcontrol.EnableWindow(TRUE);
	m_btcondition.EnableWindow(TRUE);
	goldDlg.ShowWindow(SW_HIDE);
	antimonyDlg.ShowWindow(SW_SHOW);
	optimizeCtrDlg.ShowWindow(SW_HIDE);
	conditionDlg.ShowWindow(SW_HIDE);
	processDlg.ShowWindow(SW_HIDE);
	
}


void CMonitorSYSDlg::OnBnClickedBtcontrol()
{
	// TODO:  在此添加控件通知处理程序代码
	m_btgold.EnableWindow(TRUE);
	m_btprocess.EnableWindow(TRUE);
	m_btantimony.EnableWindow(TRUE);
	m_btcontrol.EnableWindow(FALSE);
	m_btcondition.EnableWindow(TRUE);
	goldDlg.ShowWindow(SW_HIDE);
	antimonyDlg.ShowWindow(SW_HIDE);
	optimizeCtrDlg.ShowWindow(SW_SHOW);
	conditionDlg.ShowWindow(SW_HIDE);
	processDlg.ShowWindow(SW_HIDE);
}


void CMonitorSYSDlg::OnBnClickedBtcondition()
{
	// TODO:  在此添加控件通知处理程序代码
	m_btgold.EnableWindow(TRUE);
	m_btprocess.EnableWindow(TRUE);
	m_btantimony.EnableWindow(TRUE);
	m_btcontrol.EnableWindow(TRUE);
	m_btcondition.EnableWindow(FALSE);
	goldDlg.ShowWindow(SW_HIDE);
	antimonyDlg.ShowWindow(SW_HIDE);
	optimizeCtrDlg.ShowWindow(SW_HIDE);
	conditionDlg.ShowWindow(SW_SHOW);
	processDlg.ShowWindow(SW_HIDE);
}



void CMonitorSYSDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1){
		//static int nCount = 0;
		//CString str;
		//str.Format(_T("%d"), nCount);
		////SetDlgItemText(IDC_MAIN_EDIT, str);
		//SetDlgItemText(IDC_STATIC_SHOW, str);
		//++nCount;
		//if (nCount >= 10){
		//	KillTimer(1);
		//}
		CTime mTime;
		mTime = CTime::GetCurrentTime();
		CString strTime = mTime.Format(_T("%Y-%m-%d %H:%M:%S"));
		SetDlgItemText(IDC_TIME, strTime);
		CDialogEx::OnTimer(nIDEvent);
	}
}

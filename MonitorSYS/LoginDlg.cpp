// LoginDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "LoginDlg.h"
#include "afxdialogex.h"

#define IDC_EDITUSERID 111
#define IDC_EDITSUERPWD 112
#define IDC_BUTTONLOGIN 211
#define  IDC_BUTTONCANCEL 212
#define  IDC_BUTTONMINWIND 213
// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialog)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
: CDialog(CLoginDlg::IDD, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_WM_NCHITTEST()
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTONCANCEL, &CLoginDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTONLOGIN, &CLoginDlg::OnBnClickedLogin)
	ON_BN_CLICKED(IDC_BUTTONMINWIND, &CLoginDlg::OnBnClickedMinWind)
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	editUserID = new CDLEdit();

	//editUserID->setText(L"username");


	editUserID->m_strGrayString = L"username";

	editUserID->Create(ES_LEFT | WS_VISIBLE, CRect(40, 100, 210, 120), this, IDC_EDITUSERID);
	editUserPWD = new CDLEdit();
	editUserPWD->m_strGrayString = L"password";
	//editUserPWD->m_nFocusStyle = ;
	editUserPWD->Create(ES_LEFT | WS_VISIBLE, CRect(40, 140, 210, 160), this, IDC_EDITSUERPWD);
	btLogin = new CButtonST();
	btLogin->Create(L"Enter", WS_VISIBLE, CRect(38, 185, 212, 220), this, IDC_BUTTONLOGIN);
	btLogin->SetColor(0, RGB(79, 197, 173));
	btLogin->SetColor(2, RGB(79, 197, 173));
	btLogin->SetColor(1, RGB(255, 255, 255));
	btLogin->SetColor(3, RGB(255, 255, 255));
	btLogin->SetColor(4, RGB(79, 197, 173));
	btLogin->SetColor(5, RGB(79, 197, 173));
	cancell = new CButtonST();
	cancell->Create(L"x", WS_VISIBLE, CRect(232, 7, 247, 22), this, IDC_BUTTONCANCEL);
	cancell->SetColor(0, RGB(69, 159, 134));
	cancell->SetColor(2, RGB(69, 159, 134));
	cancell->SetColor(1, RGB(255, 255, 255));
	cancell->SetColor(3, RGB(255, 255, 255));
	cancell->SetColor(4, RGB(69, 159, 134));
	cancell->SetColor(5, RGB(69, 159, 134));
	minwind = new CButtonST();
	minwind->Create(L"－", WS_VISIBLE, CRect(212, 7, 227, 22), this, IDC_BUTTONMINWIND);
	minwind->SetColor(0, RGB(69, 159, 134));
	minwind->SetColor(2, RGB(69, 159, 134));
	minwind->SetColor(1, RGB(255, 255, 255));
	minwind->SetColor(3, RGB(255, 255, 255));
	minwind->SetColor(4, RGB(69, 159, 134));
	minwind->SetColor(5, RGB(69, 159, 134));

	m_brush.CreateSolidBrush(RGB(69, 159, 134));
	m_font.CreatePointFont(150, L"微软雅黑");
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


//************************************
// Method:    OnNcHitTest
// FullName:  CMonitorSystemDlg::OnNcHitTest
// Access:    public 
// Returns:   LRESULT
// Qualifier: 对话框无标题栏时用于拖动对话框
// Parameter: CPoint point
//************************************
LRESULT CLoginDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UINT   nHitTest = CDialog::OnNcHitTest(point);
	//   如果鼠标在窗口客户区，则返回标题条代号给Windows       
	//   使Windows按鼠标在标题条上类进行处理，即可单击移动窗口       
	return   (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
}


void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
}


HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

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
void CLoginDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
	//this->OnCancel();
}

void CLoginDlg::OnBnClickedLogin()
{
	// TODO: 在此添加控件通知处理程序代码

	CString userNameS("xuan");
	CString userPwdS("123");
	CString userName = NULL;
	CString userPwd = NULL;

	GetDlgItem(IDC_EDITUSERID)->GetWindowText(userName);
	GetDlgItem(IDC_EDITSUERPWD)->GetWindowText(userPwd);
	if (userNameS != userName && userPwdS != userPwd)
	{
		this->OnCancel();
	}
	else
	{
		MessageBox(L"用户名或密码错误");
	}
}
void CLoginDlg::OnBnClickedMinWind()
{
	ShowWindow(SW_MINIMIZE);
}
// LoginDlg.cpp : ʵ���ļ�
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
// CLoginDlg �Ի���

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


// CLoginDlg ��Ϣ�������


BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	minwind->Create(L"��", WS_VISIBLE, CRect(212, 7, 227, 22), this, IDC_BUTTONMINWIND);
	minwind->SetColor(0, RGB(69, 159, 134));
	minwind->SetColor(2, RGB(69, 159, 134));
	minwind->SetColor(1, RGB(255, 255, 255));
	minwind->SetColor(3, RGB(255, 255, 255));
	minwind->SetColor(4, RGB(69, 159, 134));
	minwind->SetColor(5, RGB(69, 159, 134));

	m_brush.CreateSolidBrush(RGB(69, 159, 134));
	m_font.CreatePointFont(150, L"΢���ź�");
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


//************************************
// Method:    OnNcHitTest
// FullName:  CMonitorSystemDlg::OnNcHitTest
// Access:    public 
// Returns:   LRESULT
// Qualifier: �Ի����ޱ�����ʱ�����϶��Ի���
// Parameter: CPoint point
//************************************
LRESULT CLoginDlg::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT   nHitTest = CDialog::OnNcHitTest(point);
	//   �������ڴ��ڿͻ������򷵻ر��������Ÿ�Windows       
	//   ʹWindows������ڱ�����������д������ɵ����ƶ�����       
	return   (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
}


void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}


HBRUSH CLoginDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (nCtlColor == CTLCOLOR_DLG)  //���Ի����ˢ����ɫ�������Ի������ñ�����ɫ
		return   m_brush;   //����ǳ��ɫˢ��
	if (nCtlColor == CTLCOLOR_STATIC) //���þ�̬�ı���ı���Ϊ͸��
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SelectObject(&m_font);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
void CLoginDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);
	//this->OnCancel();
}

void CLoginDlg::OnBnClickedLogin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

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
		MessageBox(L"�û������������");
	}
}
void CLoginDlg::OnBnClickedMinWind()
{
	ShowWindow(SW_MINIMIZE);
}
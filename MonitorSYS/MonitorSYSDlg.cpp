
// MonitorSYSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BtnST.h"
#include "MonitorSYS.h"
#include "MonitorSYSDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMonitorSYSDlg �Ի���



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


// CMonitorSYSDlg ��Ϣ�������

BOOL CMonitorSYSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	loginDlg.DoModal();
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_brush.CreateSolidBrush(RGB(0, 122, 204));
	m_font.CreatePointFont(150, L"΢���ź�");
	m_font1.CreatePointFont(130, L"΢���ź�");
	m_font2.CreatePointFont(110, L"΢���ź�");

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
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMonitorSYSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMonitorSYSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CMonitorSYSDlg::OnNcHitTest(CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UINT   nHitTest = CDialog::OnNcHitTest(point);
	//   �������ڴ��ڿͻ������򷵻ر��������Ÿ�Windows       
	//   ʹWindows������ڱ�����������д������ɵ����ƶ�����       
	return   (nHitTest == HTCLIENT) ? HTCAPTION : nHitTest;
}


HBRUSH CMonitorSYSDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_MINIMIZE);
}





void CMonitorSYSDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	exit(0);
}

void CMonitorSYSDlg::OnBnClickedBtprocess()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

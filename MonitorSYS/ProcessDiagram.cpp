// ProcessDiagram.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "ProcessDiagram.h"
#include "afxdialogex.h"

int m_icurShow = 1;
// CProcessDiagram 对话框

IMPLEMENT_DYNAMIC(CProcessDiagram, CDialog)

CProcessDiagram::CProcessDiagram(CWnd* pParent /*=NULL*/)
: CDialog(CProcessDiagram::IDD, pParent)
{

}

CProcessDiagram::~CProcessDiagram()
{
}

void CProcessDiagram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProcessDiagram, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CProcessDiagram 消息处理程序


HBRUSH CProcessDiagram::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (nCtlColor == CTLCOLOR_STATIC) //设置静态文本框的背景为透明
	{
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SelectObject(&m_font);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  在此更改 DC 的任何特性

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


BOOL CProcessDiagram::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_font.CreatePointFont(200, L"微软雅黑");
	SetTimer(1, 500, NULL);
	m_bkbmp1.LoadBitmap(IDB_FLOW1);
	m_bkbmp2.LoadBitmap(IDB_FLOW2);
	m_bkbmp3.LoadBitmap(IDB_FLOW3);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CProcessDiagram::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (1 == nIDEvent)
	{

		static int i_count = 0;
		//display the diagram sequence;
		BITMAP bitinfo;
		if (m_bkbmp1.m_hObject)
			m_bkbmp1.GetBitmap(&bitinfo);

		int width = bitinfo.bmWidth;
		int height = bitinfo.bmHeight;

		CRect rectClient;
		CBrush brushBkColor;
		GetClientRect(rectClient);
		int screenwidth = rectClient.Width();
		int screenheight = rectClient.Height();

		int left = (screenwidth - width) / 2;
		int top = (screenheight - height) / 2;

		//////////////////////////////////////////////////////////////////////////
		HDC hdc;
		hdc = ::GetDC(m_hWnd);



		HDC hdcMem1 = CreateCompatibleDC(hdc);
		HBITMAP hBit = CreateCompatibleBitmap(hdc, width, height);
		HBITMAP hOldSel1 = (HBITMAP)SelectObject(hdcMem1, hBit);

		HDC hdcMem2 = CreateCompatibleDC(hdc);
		HBITMAP hBmp;
		HBITMAP hOldSel2;

		if (m_icurShow == 1)
		{
			hBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCEW(IDB_FLOW1));
			hOldSel2 = (HBITMAP)SelectObject(hdcMem2, hBmp);
			//BitBlt(hdcMem1, 0, 0, width, height, hdcMem2, 0, 0, SRCCOPY);
			StretchBlt(hdcMem1, 0, 0, screenwidth, screenheight, hdcMem2, 0, 0, width, height, SRCCOPY);
			SelectObject(hdcMem2, hOldSel2);
			DeleteObject(hBmp);
			m_icurShow = 2;
		}
		else if (m_icurShow == 2)
		{
			hBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCEW(IDB_FLOW2));
			hOldSel2 = (HBITMAP)SelectObject(hdcMem2, hBmp);
			//BitBlt(hdcMem1, 0, 0, width, height, hdcMem2, 0, 0, SRCCOPY);
			StretchBlt(hdcMem1, 0, 0, screenwidth, screenheight, hdcMem2, 0, 0, width, height, SRCCOPY);
			SelectObject(hdcMem2, hOldSel2);
			DeleteObject(hBmp);
			m_icurShow = 3;
		}
		else if (m_icurShow == 3)
		{
			hBmp = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCEW(IDB_FLOW3));
			hOldSel2 = (HBITMAP)SelectObject(hdcMem2, hBmp);
			//BitBlt(hdcMem1, 0, 0, width, height, hdcMem2, 0, 0, SRCCOPY);
			StretchBlt(hdcMem1, 0, 0, screenwidth, screenheight, hdcMem2, 0, 0, width, height, SRCCOPY);
			SelectObject(hdcMem2, hOldSel2);
			DeleteObject(hBmp);
			m_icurShow = 1;
		}
		//BitBlt(hdc, left, top, width + left, height + top, hdcMem1, 0, 0, SRCCOPY);
		StretchBlt(hdc, 0, 0, width, height, hdcMem1, 0, 0, width, height, SRCCOPY);
		SelectObject(hdcMem1, hOldSel1);

	}
	CDialog::OnTimer(nIDEvent);
}


void CProcessDiagram::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	DestroyWindow();
}

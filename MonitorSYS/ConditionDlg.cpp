// ConditionDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "ConditionDlg.h"
#include "afxdialogex.h"


// CConditionDlg 对话框

IMPLEMENT_DYNAMIC(CConditionDlg, CDialog)

CConditionDlg::CConditionDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConditionDlg::IDD, pParent)
{

}

CConditionDlg::~CConditionDlg()
{
}

void CConditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConditionDlg, CDialog)
END_MESSAGE_MAP()


// CConditionDlg 消息处理程序


void CConditionDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	DestroyWindow();
}

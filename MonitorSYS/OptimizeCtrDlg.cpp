// OptimizeCtrDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "OptimizeCtrDlg.h"
#include "afxdialogex.h"


// COptimizeCtrDlg 对话框

IMPLEMENT_DYNAMIC(COptimizeCtrDlg, CDialog)

COptimizeCtrDlg::COptimizeCtrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptimizeCtrDlg::IDD, pParent)
{

}

COptimizeCtrDlg::~COptimizeCtrDlg()
{
}

void COptimizeCtrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COptimizeCtrDlg, CDialog)
END_MESSAGE_MAP()


// COptimizeCtrDlg 消息处理程序


void COptimizeCtrDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	DestroyWindow();
}

// OptimizeCtrDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "OptimizeCtrDlg.h"
#include "afxdialogex.h"


// COptimizeCtrDlg �Ի���

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


// COptimizeCtrDlg ��Ϣ�������


void COptimizeCtrDlg::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���

	DestroyWindow();
}

// ConditionDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "ConditionDlg.h"
#include "afxdialogex.h"


// CConditionDlg �Ի���

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


// CConditionDlg ��Ϣ�������


void CConditionDlg::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���

	DestroyWindow();
}

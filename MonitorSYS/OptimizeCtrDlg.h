#pragma once


// COptimizeCtrDlg �Ի���

class COptimizeCtrDlg : public CDialog
{
	DECLARE_DYNAMIC(COptimizeCtrDlg)

public:
	COptimizeCtrDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~COptimizeCtrDlg();
	virtual void OnCancel();
// �Ի�������
	enum { IDD = IDD_OPTIMIZECTRDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	
};

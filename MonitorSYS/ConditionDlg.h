#pragma once


// CConditionDlg �Ի���

class CConditionDlg : public CDialog
{
	DECLARE_DYNAMIC(CConditionDlg)

public:
	CConditionDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CConditionDlg();
	virtual void OnCancel();
// �Ի�������
	enum { IDD = IDD_CONDITIONDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	
};

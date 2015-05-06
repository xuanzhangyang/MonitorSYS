#pragma once

#include "DLEdit.h"
#include "BtnST.h"
// CLoginDlg �Ի���

class CLoginDlg : public CDialog
{
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

	// �Ի�������
	enum { IDD = IDD_LOGINDLG };
	CBrush m_brush;
	CFont m_font;
	CDLEdit *editUserID;
	CDLEdit *editUserPWD;
	CButtonST *btLogin;
	CButtonST *cancell;
	CButtonST *minwind;
	LPWSTR userNameBuff;
	LPWSTR userPwdBuff;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedLogin();
	void OnBnClickedMinWind();
};

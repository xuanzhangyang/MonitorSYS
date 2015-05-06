#pragma once


// CProcessDiagram �Ի���

class CProcessDiagram : public CDialog
{
	DECLARE_DYNAMIC(CProcessDiagram)

public:
	CProcessDiagram(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CProcessDiagram();
	CFont m_font;
	CBitmap m_bkbmp1;
	CBitmap m_bkbmp2;
	CBitmap m_bkbmp3;
	// �Ի�������
	enum { IDD = IDD_PROCESSDIAGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnCancel();
};

#pragma once


// CProcessDiagram 对话框

class CProcessDiagram : public CDialog
{
	DECLARE_DYNAMIC(CProcessDiagram)

public:
	CProcessDiagram(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CProcessDiagram();
	CFont m_font;
	CBitmap m_bkbmp1;
	CBitmap m_bkbmp2;
	CBitmap m_bkbmp3;
	// 对话框数据
	enum { IDD = IDD_PROCESSDIAGRAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnCancel();
};

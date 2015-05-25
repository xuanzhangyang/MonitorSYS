
// MonitorSYSDlg.h : ͷ�ļ�
//

#pragma once
#include "LoginDlg.h"
#include "BtnST.h"
#include "afxwin.h"
#include "AntimonyDlg.h"
#include "ConditionDlg.h"
#include "LoginDlg.h"
#include "OptimizeCtrDlg.h"
#include "GoldDlg.h"
#include "ProcessDiagram.h"

// CMonitorSYSDlg �Ի���
class CMonitorSYSDlg : public CDialogEx
{
// ����
public:
	CMonitorSYSDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CLoginDlg loginDlg;
	CProcessDiagram processDlg;
	CGoldDlg goldDlg;
	CAntimonyDlg antimonyDlg;
	COptimizeCtrDlg optimizeCtrDlg;
	CConditionDlg conditionDlg;
	CBrush m_brush;
	CFont m_font;
	CFont m_font1;
	CFont m_font2;
// �Ի�������
	enum { IDD = IDD_MONITORSYS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButtonST m_btmin;
	CButtonST m_btcalcel;
	CButtonST m_btprocess;
	CButtonST m_btgold;
	CButtonST m_btantimony;
	CButtonST m_btcontrol;
	CButtonST m_btcondition;
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void setbtColor(CButtonST *btst, COLORREF crColor, COLORREF textColor = RGB(255, 255, 255));
	afx_msg void OnBnClickedMinzoom();

	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtgold();
	afx_msg void OnBnClickedBtprocess();
	
	afx_msg void OnBnClickedBtantimony();
	afx_msg void OnBnClickedBtcontrol();
	afx_msg void OnBnClickedBtcondition();
	CButtonST m_usedtime;
	CButtonST m_workcondition;
	CButtonST m_time;
	CButtonST m_label;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButtonST m_home;
	CButtonST m_history;
	CButtonST m_expertsys;
};

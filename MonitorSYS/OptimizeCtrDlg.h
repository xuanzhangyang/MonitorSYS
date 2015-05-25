#pragma once
#include "BtnST.h"
#include "afxwin.h"


// COptimizeCtrDlg 对话框

class COptimizeCtrDlg : public CDialog
{
	DECLARE_DYNAMIC(COptimizeCtrDlg)

public:
	COptimizeCtrDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COptimizeCtrDlg();
	virtual void OnCancel();

	void setbtColor(CButtonST *btst, COLORREF crColor);
// 对话框数据
	enum { IDD = IDD_OPTIMIZECTRDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
public:
	CButtonST m_goldDosing;
	CButtonST m_antiDosing;
	CButtonST m_pharmacy;
	CButtonST m_realtime1;
	CButtonST m_suggest1;
	CButtonST m_na2co3;
	CButtonST m_cu2so4;
	CButtonST m_na2sio4;
	CButtonST m_na2co3RT;
	CButtonST m_na2co3SU;
	CButtonST m_cu2so4RT;
	CButtonST m_cu2so4SU;
	CButtonST m_na2sio4RT;
	CButtonST m_na2sio4SU;
	CButtonST m_pharmacAnti;
	CButtonST m_realtimeAnti;
	CButtonST m_suggestAnti;
	CButtonST m_xanthate;
	CButtonST m_XanthateAntiRT;
	CButtonST m_xanthateAntiSU;
	CButtonST m_aerofloat;
	CButtonST m_aerofloatRT;
	CButtonST m_aerofloatSU;
	CButtonST m_cu2so4Anti;
	CButtonST m_cu2so4AntiRT;
	CButtonST m_cu2so4AntiSU;
	CButtonST m_pbno32;
	CButtonST m_pbno32RT;
	CButtonST m_pbno32SU;
	CButtonST m_pharmacyGold;
	CButtonST m_realtimeGold;
	CButtonST m_xanthateGold;
	CButtonST m_xanthateGoldRT;
	CButtonST m_xanthateGoldSU;
	CButtonST m_oil;
	CButtonST m_oilRT;
	CButtonST m_oilSU;
	CButtonST m_na2sGold;
	CButtonST m_na2sGoldRT;
	CButtonST m_na2sGoldSU;
	CButtonST m_ph;
	CButtonST m_phGoldLabel;
	CButtonST m_phAntiLabel;
	CButtonST m_phGold;
	CButtonST m_phAnti;
	CButtonST m_oldSpeedLabel;
	CButtonST m_oldSpeed;
	CButtonST m_newSpeedLabel;
	CButtonST m_newSpeed;

	CBrush m_brush;
	CFont m_font;
	CFont m_font1;
	CFont m_font2;
	CFont m_font3;
	CFont m_font4;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButtonST m_changeExpert;
	CButtonST m_suggestGold;
};

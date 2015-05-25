#pragma once
#include "stdafx.h"

#include "CvvImage.h"
#include "afxwin.h"
#include "BtnST.h"
#include "ChartClass/ChartCtrl.h"
#include "ChartClass/ChartLineSerie.h"
// CGoldDlg 对话框
using namespace cv;
class CGoldDlg : public CDialog
{
	DECLARE_DYNAMIC(CGoldDlg)

public:
	CGoldDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CGoldDlg();

	// 对话框数据
	enum { IDD = IDD_GOLDDLG };
	CBrush m_brush;
	CFont m_font;
	CFont m_font1;
	CFont m_font2;
	CFont m_font3;
	CFont m_font4;
	CButtonST m_btfeature;
	CButtonST m_realTimePic;
	CButtonST m_btcurve;
	CButtonST m_flowEffect;
	CButtonST m_btflowEffect;
	CButtonST m_suggest;
	CButtonST m_btsuggest;
	CButtonST m_workCondition;
	CButtonST m_btworkCondition;
	CChartCtrl m_chartSize;
	CChartCtrl m_chartSpeed;
	CChartCtrl m_chartTexture;
	CChartCtrl m_chartColor;
	CRect picrect;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	void showImage(IplImage *image, UINT ID);
	void showVedio();
	static UINT __cdecl ThreadProc(LPVOID lpParameter);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void setbtColor(CButtonST *btst, COLORREF crColor);
	
	virtual void OnCancel();
	afx_msg void OnPaint();
	void resize_image(IplImage* img, IplImage *theimg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButtonST m_play;
	CButtonST m_pause;
};

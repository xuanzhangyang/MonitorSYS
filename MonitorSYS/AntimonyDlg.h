#pragma once
#include "BtnST.h"
#include "afxwin.h"
#include "CvvImage.h"
#include "opencv2/opencv.hpp"
#include "ChartClass/ChartCtrl.h"
#include "ChartClass/ChartLineSerie.h"
// CAntimonyDlg 对话框
using namespace cv;

class CAntimonyDlg : public CDialog
{
	DECLARE_DYNAMIC(CAntimonyDlg)

public:
	CAntimonyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAntimonyDlg();

	// 对话框数据
	enum { IDD = IDD_ANTIMONYDLG };
	CBrush m_brush;
	CFont m_font;
	CFont m_font1;
	CFont m_font2;
	CFont m_font3;
	CFont m_font4;
	CRect picrect;
	Mat vedioframe;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual BOOL OnInitDialog();
	CButtonST m_btfeature;
	void setbtColor(CButtonST *btst, COLORREF crColor);
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
	virtual void OnCancel();
	void showImage(IplImage *image, UINT ID);
	void showVedio();
	afx_msg void OnPaint();
	void resize_image(IplImage* img, IplImage *theimg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButtonST m_play;
	CButtonST m_pause;
};

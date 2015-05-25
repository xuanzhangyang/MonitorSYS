// OptimizeCtrDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "OptimizeCtrDlg.h"
#include "afxdialogex.h"


// COptimizeCtrDlg 对话框

IMPLEMENT_DYNAMIC(COptimizeCtrDlg, CDialog)

COptimizeCtrDlg::COptimizeCtrDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COptimizeCtrDlg::IDD, pParent)
{

}

COptimizeCtrDlg::~COptimizeCtrDlg()
{
}

void COptimizeCtrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GOLDDOSING, m_goldDosing);
	DDX_Control(pDX, IDC_ANTIMONYDOSING, m_antiDosing);
	DDX_Control(pDX, IDC_BUTTON3, m_pharmacy);
	DDX_Control(pDX, IDC_BUTTON7, m_realtime1);
	DDX_Control(pDX, IDC_BUTTON8, m_suggest1);
	DDX_Control(pDX, IDC_BUTTON4, m_na2co3);
	DDX_Control(pDX, IDC_BUTTON5, m_cu2so4);
	DDX_Control(pDX, IDC_BUTTON6, m_na2sio4);
	DDX_Control(pDX, IDC_BUTTON9, m_na2co3RT);
	DDX_Control(pDX, IDC_BUTTON12, m_na2co3SU);
	DDX_Control(pDX, IDC_BUTTON10, m_cu2so4RT);
	DDX_Control(pDX, IDC_BUTTON13, m_cu2so4SU);
	DDX_Control(pDX, IDC_BUTTON11, m_na2sio4RT);
	DDX_Control(pDX, IDC_BUTTON14, m_na2sio4SU);
	DDX_Control(pDX, IDC_BUTTON27, m_pharmacAnti);
	DDX_Control(pDX, IDC_BUTTON34, m_realtimeAnti);
	DDX_Control(pDX, IDC_BUTTON29, m_suggestAnti);
	DDX_Control(pDX, IDC_BUTTON30, m_xanthate);
	DDX_Control(pDX, IDC_BUTTON35, m_XanthateAntiRT);
	DDX_Control(pDX, IDC_BUTTON39, m_xanthateAntiSU);
	DDX_Control(pDX, IDC_BUTTON31, m_aerofloat);
	DDX_Control(pDX, IDC_BUTTON36, m_aerofloatRT);
	DDX_Control(pDX, IDC_BUTTON41, m_aerofloatSU);
	DDX_Control(pDX, IDC_BUTTON32, m_cu2so4Anti);
	DDX_Control(pDX, IDC_BUTTON37, m_cu2so4AntiRT);
	DDX_Control(pDX, IDC_BUTTON42, m_cu2so4AntiSU);
	DDX_Control(pDX, IDC_BUTTON33, m_pbno32);
	DDX_Control(pDX, IDC_BUTTON38, m_pbno32RT);
	DDX_Control(pDX, IDC_BUTTON40, m_pbno32SU);
	DDX_Control(pDX, IDC_BUTTON15, m_pharmacyGold);
	DDX_Control(pDX, IDC_BUTTON16, m_realtimeGold);
	DDX_Control(pDX, IDC_BUTTON18, m_xanthateGold);
	DDX_Control(pDX, IDC_BUTTON21, m_xanthateGoldRT);
	DDX_Control(pDX, IDC_BUTTON24, m_xanthateGoldSU);
	DDX_Control(pDX, IDC_BUTTON19, m_oil);
	DDX_Control(pDX, IDC_BUTTON22, m_oilRT);
	DDX_Control(pDX, IDC_BUTTON25, m_oilSU);
	DDX_Control(pDX, IDC_BUTTON20, m_na2sGold);
	DDX_Control(pDX, IDC_BUTTON23, m_na2sGoldRT);
	DDX_Control(pDX, IDC_BUTTON26, m_na2sGoldSU);
	DDX_Control(pDX, IDC_BUTTON28, m_ph);
	DDX_Control(pDX, IDC_BUTTON43, m_phGoldLabel);
	DDX_Control(pDX, IDC_BUTTON44, m_phAntiLabel);
	DDX_Control(pDX, IDC_BUTTON45, m_phGold);
	DDX_Control(pDX, IDC_BUTTON46, m_phAnti);
	DDX_Control(pDX, IDC_BUTTON48, m_oldSpeedLabel);
	DDX_Control(pDX, IDC_BUTTON49, m_oldSpeed);
	DDX_Control(pDX, IDC_BUTTON47, m_newSpeedLabel);
	DDX_Control(pDX, IDC_BUTTON50, m_newSpeed);
	
	DDX_Control(pDX, IDC_BUTTON17, m_suggestGold);
}


BEGIN_MESSAGE_MAP(COptimizeCtrDlg, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// COptimizeCtrDlg 消息处理程序


void COptimizeCtrDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	DestroyWindow();
}


BOOL COptimizeCtrDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(0, 122, 204));
	m_font.CreatePointFont(120, L"微软雅黑");
	m_font1.CreatePointFont(150, L"微软雅黑");
	m_font2.CreatePointFont(200, L"微软雅黑");
	m_font3.CreatePointFont(170, L"微软雅黑");
	m_font4.CreatePointFont(240, L"微软雅黑");

	setbtColor(&m_goldDosing, RGB(0, 122, 204));
	m_goldDosing.SetFont(&m_font3);
	m_goldDosing.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_antiDosing, RGB(0, 122, 204));
	m_antiDosing.SetFont(&m_font3);
	m_antiDosing.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_pharmacy, RGB(106, 167, 27));
	m_pharmacy.SetFont(&m_font1);
	m_pharmacy.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2co3, RGB(149, 186, 18));
	m_na2co3.SetFont(&m_font1);
	m_na2co3.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_cu2so4, RGB(181, 201, 15));
	m_cu2so4.SetFont(&m_font1);
	m_cu2so4.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2sio4, RGB(214, 214, 6));
	m_na2sio4.SetFont(&m_font1);
	m_na2sio4.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_pharmacyGold, RGB(232, 217, 4));
	m_pharmacyGold.SetFont(&m_font1);
	m_pharmacyGold.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_xanthateGold, RGB(249, 214, 2));
	m_xanthateGold.SetFont(&m_font1);
	m_xanthateGold.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_oil, RGB(250, 191, 0));
	m_oil.SetFont(&m_font1);
	m_oil.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2sGold, RGB(250, 167, 1));
	m_na2sGold.SetFont(&m_font1);
	m_na2sGold.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_pharmacAnti, RGB(240, 212, 192));
	m_pharmacAnti.SetFont(&m_font1);
	m_pharmacAnti.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_xanthate, RGB(244, 193, 159));
	m_xanthate.SetFont(&m_font1);
	m_xanthate.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_aerofloat, RGB(221, 156, 128));
	m_aerofloat.SetFont(&m_font1);
	m_aerofloat.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_cu2so4Anti, RGB(174, 93, 92));
	m_cu2so4Anti.SetFont(&m_font1);
	m_cu2so4Anti.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_pbno32, RGB(138, 53, 76));
	m_pbno32.SetFont(&m_font1);
	m_pbno32.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_realtime1, RGB(0, 122, 204));
	m_realtime1.SetFont(&m_font1);
	m_realtime1.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_suggest1, RGB(0, 122, 204));
	m_suggest1.SetFont(&m_font1);
	m_suggest1.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_realtimeAnti, RGB(0, 122, 204));
	m_realtimeAnti.SetFont(&m_font1);
	m_realtimeAnti.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_suggestAnti, RGB(0, 122, 204));
	m_suggestAnti.SetFont(&m_font1);
	m_suggestAnti.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_realtimeGold, RGB(0, 122, 204));
	m_realtimeGold.SetFont(&m_font1);
	m_realtimeGold.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_suggestGold, RGB(0, 122, 204));
	m_suggestGold.SetFont(&m_font1);
	m_suggestGold.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_na2co3RT, RGB(0, 122, 204));
	m_na2co3RT.SetFont(&m_font1);
	m_na2co3RT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2co3SU, RGB(0, 122, 204));
	m_na2co3SU.SetFont(&m_font1);
	m_na2co3SU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_cu2so4RT, RGB(0, 122, 204));
	m_cu2so4RT.SetFont(&m_font1);
	m_cu2so4RT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_cu2so4SU, RGB(0, 122, 204));
	m_cu2so4SU.SetFont(&m_font1);
	m_cu2so4SU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2sio4RT, RGB(0, 122, 204));
	m_na2sio4RT.SetFont(&m_font1);
	m_na2sio4RT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2sio4SU, RGB(0, 122, 204));
	m_na2sio4SU.SetFont(&m_font1);
	m_na2sio4SU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_XanthateAntiRT, RGB(0, 122, 204));
	m_XanthateAntiRT.SetFont(&m_font1);
	m_XanthateAntiRT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_xanthateAntiSU, RGB(0, 122, 204));
	m_xanthateAntiSU.SetFont(&m_font1);
	m_xanthateAntiSU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_aerofloatRT, RGB(0, 122, 204));
	m_aerofloatRT.SetFont(&m_font1);
	m_aerofloatRT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_aerofloatSU, RGB(0, 122, 204));
	m_aerofloatSU.SetFont(&m_font1);
	m_aerofloatSU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_cu2so4AntiRT, RGB(0, 122, 204));
	m_cu2so4AntiRT.SetFont(&m_font1);
	m_cu2so4AntiRT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_cu2so4AntiSU, RGB(0, 122, 204));
	m_cu2so4AntiSU.SetFont(&m_font1);
	m_cu2so4AntiSU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_pbno32RT, RGB(0, 122, 204));
	m_pbno32RT.SetFont(&m_font1);
	m_pbno32RT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_pbno32SU, RGB(0, 122, 204));
	m_pbno32SU.SetFont(&m_font1);
	m_pbno32SU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_xanthateGoldRT, RGB(0, 122, 204));
	m_xanthateGoldRT.SetFont(&m_font1);
	m_xanthateGoldRT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_xanthateGoldSU, RGB(0, 122, 204));
	m_xanthateGoldSU.SetFont(&m_font1);
	m_xanthateGoldSU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_oilRT, RGB(0, 122, 204));
	m_oilRT.SetFont(&m_font1);
	m_oilRT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_oilSU, RGB(0, 122, 204));
	m_oilSU.SetFont(&m_font1);
	m_oilSU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2sGoldRT, RGB(0, 122, 204));
	m_na2sGoldRT.SetFont(&m_font1);
	m_na2sGoldRT.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_na2sGoldSU, RGB(0, 122, 204));
	m_na2sGoldSU.SetFont(&m_font1);
	m_na2sGoldSU.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_ph, RGB(255, 132, 0));
	m_ph.SetFont(&m_font1);
	m_ph.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_phGoldLabel, RGB(0, 122, 204));
	m_phGoldLabel.SetFont(&m_font1);
	m_phGoldLabel.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_phAntiLabel, RGB(0, 122, 204));
	m_phAntiLabel.SetFont(&m_font1);
	m_phAntiLabel.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_oldSpeedLabel, RGB(0, 122, 204));
	m_oldSpeedLabel.SetFont(&m_font1);
	m_oldSpeedLabel.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_newSpeedLabel, RGB(0, 122, 204));
	m_newSpeedLabel.SetFont(&m_font1);
	m_newSpeedLabel.setfalseColor(RGB(255, 255, 0));//黄色

	setbtColor(&m_phGold, RGB(0, 122, 204));
	m_phGold.SetFont(&m_font1);
	m_phGold.setfalseColor(RGB(255, 255, 255));//黄色


	setbtColor(&m_phAnti, RGB(0, 122, 204));
	m_phAnti.SetFont(&m_font1);
	m_phAnti.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_oldSpeed, RGB(0, 122, 204));
	m_oldSpeed.SetFont(&m_font1);
	m_oldSpeed.setfalseColor(RGB(255, 255, 255));//黄色

	setbtColor(&m_newSpeed, RGB(0, 122, 204));
	m_newSpeed.SetFont(&m_font1);
	m_newSpeed.setfalseColor(RGB(255, 255, 255));//黄色



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


HBRUSH COptimizeCtrDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_DLG)  //给对话框的刷子上色，即给对话框设置背景颜色
		return   m_brush;

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

void COptimizeCtrDlg::setbtColor(CButtonST *btst, COLORREF crColor)
{
	btst->SetColor(0, crColor);
	btst->SetColor(2, crColor);
	btst->SetColor(1, RGB(255, 255, 255));
	btst->SetColor(3, RGB(255, 255, 255));
	btst->SetColor(4, crColor);
	btst->SetColor(5, crColor);
}
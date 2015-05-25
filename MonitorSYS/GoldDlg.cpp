// GoldDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "GoldDlg.h"
#include "afxdialogex.h"
#include "MonitorSYSDlg.h"

// CGoldDlg 对话框
using namespace std;
IMPLEMENT_DYNAMIC(CGoldDlg, CDialog)

double xa[100], ya[100] = { 332.530401, 401.433433, 442.250552, 524.28355, 504.240342, 535.52554, 600.8352, 642.535355, 755.08535, 753.35854,
765.505521, 830.135424, 754.15433, 435.334241, 522.335444, 634.48345, 645.152542, 633.80504, 615.32442, 532.500024, 530.535421, 533.80455, 445.255244,
450.58331, 446.84153, 338.503535, 350.425155, 338.034551, 82.82524, 82.32745, 222.05625, 224.155553, 228.413542, 85.884, 243.42275, 252.84322,
222.500225, 285.33358, 301.324324, 245.355332, 242.550044, 285.355131, 313.2468, 84.424545, 281.535251, 236.543054, 253.51338, 244.34438, 253.035455, 302.253542,
338.73431, 315.455413, 402.4881, 343.330413, 442.52033, 431.213424, 432.555303, 524.84422, 455.521325, 453.8403, 402.25243, 384.0208, 252.354453, 251.202224,
444.05133, 535.205313, 540.84054, 533.82254, 624.8733, 644.503222, 444.35565, 442.252225, 450.20284, 434.43482, 333.54245, 324.04375, 82.344203, 243.550413,
254.443555, 334.43655, 320.524015, 434.224001, 453.025353, 453.025353, 352.544213, 435.303052, 352.58213, 340.405054, 348.34501, 302.213304, 331.535252, 243.55584,
254.304321, 228.530504, 204.2883, 282.450402, 204.222033, 304.42438, 355.254435, 334.24833};
double xb[100], yb[100] = { 
3.2368,
3.3669,
3.4265,
3.5148,
3.4541,
3.4631,
3.4743,
3.4301,
3.2964,
3.2109,
3.1162,
3.0734,
3.0161,
3.0414,
3.0321,
3.1003,
3.1997,
3.245,
3.2505,
3.2511,
3.2607,
3.2883,
3.1573,
3.0625,
3.0471,
3.0541,
2.9826,
2.9428,
3.0246,
3.0683,
3.1154,
3.1424,
3.3396,
3.3799,
3.3965,
3.3448,
3.3212,
3.2273,
3.1053,
3.0696,
3.0826,
3.6049,
3.5247,
3.4384,
3.3933,
3.3793,
3.3875,
3.3705,
3.3623,
3.3729,
3.3961,
3.3986,
3.4499,
3.5048,
3.6105,
3.6304,
3.636,
3.6249,
3.5775,
3.5717,
3.5841,
3.6321,
3.1035,
3.305,
3.1267,
3.1177,
3.131,
3.1457,
3.2415,
3.3169,
3.4466,
3.5109,
3.5527,
3.5897,
3.5981,
3.6323,
3.6278,
3.6504,
3.6242,
3.5142,
3.3393,
3.2777,
3.221,
3.1929,
3.1919,
3.1971,
3.328,
3.0376,
2.9199,
3.2289,
3.2394,
3.2743,
3.2348,
3.1645,
3.1655,
3.2789,
3.2947,
3.3007,
3.2805,
3.2569,
};
double xc[100], yc[100] = { 
0.571299,
0.558449,
0.552339,
0.564321,
0.561624,
0.567767,
0.568679,
0.576475,
0.569376,
0.568742,
0.572039,
0.574656,
0.57296,
0.573398,
0.569047,
0.567563,
0.56635,
0.57005,
0.564195,
0.575336,
0.559542,
0.566157,
0.571437,
0.574917,
0.5774,
0.56699,
0.563392,
0.569611,
0.574821,
0.565992,
0.567021,
0.562316,
0.56864,
0.565898,
0.569847,
0.571737,
0.567618,
0.559012,
0.570523,
0.560041,
0.557939,
0.563022,
0.568127,
0.568562,
0.574457,
0.566867,
0.570636,
0.571941,
0.569764,
0.566915,
0.568608,
0.574389,
0.571659,
0.570301,
0.570777,
0.566704,
0.565208,
0.559907,
0.567544,
0.566635,
0.570759,
0.569967,
0.566804,
0.571253,
0.560179,
0.566621,
0.564135,
0.567507,
0.566629,
0.555896,
0.562129,
0.567751,
0.570649,
0.565219,
0.569933,
0.577192,
0.573709,
0.572774,
0.569131,
0.570054,
0.574869,
0.575074,
0.57262,
0.573116,
0.568302,
0.574467,
0.56823,
0.571219,
0.567358,
0.562152,
0.563249,
0.565608,
0.566203,
0.571408,
0.56651,
0.575821,
0.568882,
0.566145,
0.572403,
0.570181
};
double xd[100], yd[100] = {  99.410873, 103.144028, 96.897629, 99.379364, 92.612709, 96.275146, 91.323456, 93.412086, 94.189804,
93.314972, 93.530846, 95.071724, 94.351227, 93.36296, 96.041053, 93.963715, 95.615387, 94.967522,  97.367859, 94.892761, 96.046204, 96.079865, 95.802788,
94.407867, 94.718254, 95.751884, 96.996277, 101.398468, 99.383781, 93.573914, 94.545189, 96.36145, 99.326843, 97.971283, 98.549896, 102.327187, 98.021339,
95.984024, 99.933235, 99.955643, 99.91509, 98.861778, 99.401878, 99.065979, 104.00061, 103.554176, 102.487572, 102.093658, 103.017967, 102.691032, 104.599792,
102.887306, 99.358604, 99.929146, 101.467918, 98.229485, 97.32682, 95.43395, 94.896108, 94.720047, 99.649399, 102.016212, 99.02961, 99.144646,
99.957123, 106.830254, 101.070984, 94.057945, 99.529503, 94.865807, 96.028969, 94.987465, 95.847672, 95.750282, 95.821648, 99.010681, 98.306274, 97.631034,
95.926048, 96.872398, 96.063553, 98.20285, 97.578506, 96.486603, 96.893616, 97.566368, 97.252396, 97.960976, 96.899857, 99.163956, 99.203079, 99.698898, 99.288696, 101.293953, 99.058327,
99.206764, 102.594345, 99.242958, 101.157684, 99.968964 };

CGoldDlg::CGoldDlg(CWnd* pParent /*=NULL*/)
: CDialog(CGoldDlg::IDD, pParent)
{

}

CGoldDlg::~CGoldDlg()
{
}

void CGoldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BTFEATURE, m_btfeature);
	DDX_Control(pDX, IDC_REALTIMEPIC, m_realTimePic);
	DDX_Control(pDX, IDC_BTCURVE, m_btcurve);
	DDX_Control(pDX, IDC_FLOWEFFECT, m_flowEffect);
	DDX_Control(pDX, IDC_BTFLOWEFFECT, m_btflowEffect);
	DDX_Control(pDX, IDC_SUGGEST, m_suggest);
	DDX_Control(pDX, IDC_BTSUGGEST, m_btsuggest);
	DDX_Control(pDX, IDC_WORKCONDITION, m_workCondition);
	DDX_Control(pDX, IDC_BTWORKCONDITION, m_btworkCondition);
	DDX_Control(pDX, IDC_CHARTSIZE, m_chartSize);
	DDX_Control(pDX, IDC_CHARTSPEED, m_chartSpeed);
	DDX_Control(pDX, IDC_CHARTTEXTURE, m_chartTexture);
	DDX_Control(pDX, IDC_CHARTCOLOR, m_chartColor);
	DDX_Control(pDX, IDC_PLAY, m_play);
	DDX_Control(pDX, IDC_PAUSE, m_pause);
}


BEGIN_MESSAGE_MAP(CGoldDlg, CDialog)
	ON_WM_CTLCOLOR()

	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()

UINT __cdecl threadGoldVedio(LPVOID lpParameter)
{
	while (TRUE)
	{
		CGoldDlg *dlg = (CGoldDlg *)lpParameter;
		//dlg->vedioframe = imread("E:\\毕设\\锑粗选视频\\1\\20140608115045Sb\\2.jpg");
		VideoCapture capture("D:\\Desktop\\毕设\\20140622110422Sb.avi");
		Mat frame;
		IplImage image1;
		if (!capture.isOpened())
		{
			MessageBox(NULL, _T("警告"), _T("视频连接失败！"), 1);
			return 1;
		}
		int rate = capture.get(CV_CAP_PROP_FPS);
		int delay = 1000 / rate;
		int i = 0;
		CWnd *bt = dlg->GetDlgItem(IDC_REALTIMEPIC);
		int frameCount = capture.get(CV_CAP_PROP_FRAME_COUNT);
		while (i < frameCount)
		{
			capture >> frame;
			image1 = frame;

			dlg->showImage(&image1, IDC_SHOWAVI);

			CString str;
			str.Format(_T("%d"), i++);
			//bt->SetWindowText(str);
			Sleep(delay);
		}
	}
	return 0;
}
// CGoldDlg 消息处理程序

BOOL CGoldDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
	m_brush.CreateSolidBrush(RGB(0, 122, 204));
	m_font.CreatePointFont(120, L"微软雅黑");
	m_font1.CreatePointFont(150, L"微软雅黑");
	m_font2.CreatePointFont(200, L"微软雅黑");
	m_font3.CreatePointFont(170, L"微软雅黑");
	m_font4.CreatePointFont(240, L"微软雅黑");
	setbtColor(&m_btfeature, RGB(0, 122, 204));
	m_btfeature.SetFont(&m_font1);
	m_btfeature.setfalseColor(RGB(255, 255, 0));
	setbtColor(&m_realTimePic, RGB(0, 122, 204));
	m_realTimePic.SetFont(&m_font1);
	m_realTimePic.setfalseColor(RGB(255, 255, 0));
	setbtColor(&m_btcurve, RGB(0, 122, 204));
	m_btcurve.SetFont(&m_font1);
	m_btcurve.setfalseColor(RGB(255, 255, 0));
	setbtColor(&m_flowEffect, RGB(241, 196, 15));
	m_flowEffect.SetFont(&m_font1);
	m_flowEffect.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_btflowEffect, RGB(241, 196, 15));
	m_btflowEffect.SetFont(&m_font4);
	m_btflowEffect.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_suggest, RGB(230, 127, 34));
	m_suggest.SetFont(&m_font1);
	m_suggest.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_btsuggest, RGB(230, 127, 34));
	m_btsuggest.SetFont(&m_font3);
	m_btsuggest.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_workCondition, RGB(214, 84, 0));
	m_workCondition.SetFont(&m_font1);
	m_workCondition.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_btworkCondition, RGB(214, 84, 0));
	m_btworkCondition.SetFont(&m_font3);
	m_btworkCondition.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_play, RGB(0, 122, 204));
	m_play.SetIcon(IDI_PLAY);
	setbtColor(&m_pause, RGB(0, 122, 204));
	m_pause.SetIcon(IDI_PAUSE);
	///////////////////////////为特征曲线图添加数值型的坐标轴///////////////////////////
	CChartAxis *pAxis = NULL;
	//pAxis = m_chartSize.CreateStandardAxis(CChartCtrl::BottomAxis);
	//pAxis->SetAutomatic(true);
	pAxis = m_chartSize.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartSize.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartSpeed.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartSpeed.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartTexture.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartTexture.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartColor.CreateStandardAxis(CChartCtrl::LeftAxis);
	pAxis->SetAutomatic(true);
	pAxis = m_chartColor.CreateStandardAxis(CChartCtrl::BottomAxis);
	pAxis->SetAutomatic(true);
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////为特征曲线图添加左标题与下标题//////////////////////////
	CChartAxisLabel* pLabel = NULL;
	
	TChartString str1 = _T("泡沫大小");
	TChartString str2 = _T("泡沫速度");
	TChartString str3 = _T("泡沫稳定度");
	TChartString str4 = _T("红色分量");
	

	pAxis = m_chartSize.GetLeftAxis();
	if (pAxis)
		pLabel = pAxis->GetLabel();
	if (pLabel)
		pLabel->SetText(str1);
	pAxis = m_chartSpeed.GetLeftAxis();
	if (pAxis)
		pLabel = pAxis->GetLabel();
	if (pLabel)
		pLabel->SetText(str2);
	pAxis = m_chartTexture.GetLeftAxis();
	if (pAxis)
		pLabel = pAxis->GetLabel();
	if (pLabel)
		pLabel->SetText(str3);
	pAxis = m_chartColor.GetLeftAxis();
	if (pAxis)
		pLabel = pAxis->GetLabel();
	if (pLabel)
		pLabel->SetText(str4);
// 	str1 = _T("数值坐标轴");
// 	pAxis = m_chartCtr.GetBottomAxis();
// 	if (pAxis)
// 		pLabel = pAxis->GetLabel();
// 	if (pLabel)
// 		pLabel->SetText(str1);
	/////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < 100; i++)
	{
		xa[i] = xb[i] = xc[i] = xd[i] = i;
		
	}
	

	SetTimer(1, 500, NULL);
	SetTimer(2, 500, NULL);
	SetTimer(3, 500, NULL);
	SetTimer(4, 500, NULL);
	GetDlgItem(IDC_SHOWAVI)->GetClientRect(&picrect);
	AfxBeginThread(threadGoldVedio, this);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}
void CGoldDlg::showImage(IplImage *image, UINT ID)    // ID 是Picture Control控件的ID号
{
	CvSize ImgSize;
	IplImage *theimg;
	ImgSize.width = picrect.Width();
	ImgSize.height = picrect.Height();
	theimg = cvCreateImage(ImgSize, IPL_DEPTH_8U, 3);
	IplImage *image2 = image;
	resize_image(image2, theimg);

	CDC *pDC = GetDlgItem(ID)->GetDC();
	HDC hDC = pDC->GetSafeHdc();

	int rw = picrect.right - picrect.left;
	int rh = picrect.bottom - picrect.top;
	int iw = theimg->width;
	int ih = theimg->height;
	int tx = (int)(rw - iw) / 2;
	int ty = (int)(rh - ih) / 2;
	SetRect(picrect, tx, ty, tx + iw, ty + ih);
	CvvImage cimg;
	cimg.CopyOf(theimg); // 复制图片
	cimg.DrawToHDC(hDC, &picrect); // 将图片绘制到显示控件的指定区域内
	ReleaseDC(pDC);
}

// void CGoldDlg::showVedio()
// {
// 	//VideoCapture capture("E:\\毕设\\锑粗选视频\\1\\20140608115045Sb.avi");
// 	Mat frame = imread("E:\\毕设\\锑粗选视频\\1\\20140608115045Sb\\1.jpg");
// // 	for (int i = 0; i < 100; i++)
// // 	{
// // 		capture >> frame;
// 	CvSize ImgSize;
// 	IplImage *theimg;
// 	ImgSize.width = picrect.Width();
// 	ImgSize.height = picrect.Height();
// 	theimg = cvCreateImage(ImgSize, IPL_DEPTH_8U, 3);
// 	IplImage image = frame;
// 		resize_image(&image,theimg);
// 		showImage(theimg, IDC_SHOWAVI);
// // 		waitKey(30);
// // 	}
// }



HBRUSH CGoldDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_DLG)  //给对话框的刷子上色，即给对话框设置背景颜色
		return   m_brush;
	if (nCtlColor == CTLCOLOR_STATIC) //设置静态文本框的背景为透明
	{
		pDC->SetBkMode(TRANSPARENT);
		// 		if ((CStatic *)GetDlgItem(IDC_FEATURE) == &m_featureSta )
		// 		{
		// 			m_font.CreatePointFont(140, L"微软雅黑");
		// 			pDC->SetTextColor(RGB(255, 255, 255));
		// 			pDC->SelectObject(&m_font);
		// 		}
		// 		else
		// 		{

		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SelectObject(&m_font);
		//		}

		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}



void CGoldDlg::setbtColor(CButtonST *btst, COLORREF crColor)
{
	btst->SetColor(0, crColor);
	btst->SetColor(2, crColor);
	btst->SetColor(1, RGB(255, 255, 255));
	btst->SetColor(3, RGB(255, 255, 255));
	btst->SetColor(4, crColor);
	btst->SetColor(5, crColor);
}

void CGoldDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	DestroyWindow();
}


void CGoldDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码

// 	不为绘图消息调用 
// 		CDialog::OnPaint();
// 		CDialog::UpdateWindow();				// 更新windows窗口，如果无这步调用，图片显示还会出现问题
// 		showVedio();	// 重绘图片函数
}

void CGoldDlg::resize_image(IplImage* img,IplImage *theimg)
{
	// 读取图片的宽和高
	int w = img->width;
	int h = img->height;

	// 找出宽和高中的较大值者
	int max = (w > h) ? w : h;

	
	
	int x = picrect.Width();
	int y = picrect.Height();
	float a = (float)w / (float)x;
	float b = (float)h / (float)y;
	float scale;
	if (a>b)
	{
		scale = a;
	}
	else
	{
		scale = b;
	}
	// 计算将图片缩放到TheImage区域所需的比例因子

	// 缩放后图片的宽和高
	int nw = (int)(w / scale);
	int nh = (int)(h / scale);

	// 为了将缩放后的图片存入 TheImage 的正中部位，需计算图片在 TheImage 左上角的期望坐标值
	int tlx = (nw > nh) ? 0 : (int)(x - nw) / 2;
	int tly = (nw > nh) ? (int)(y - nh) / 2 : 0;
	// 设置 TheImage 的 ROI 区域，用来存入图片 img
	cvSetImageROI(theimg, cvRect(tlx, tly, nw, nh));

	// 对图片 img 进行缩放，并存入到 TheImage 中
	cvResize(img, theimg);

	// 重置 TheImage 的 ROI 准备读入下一幅图片
	cvResetImageROI(theimg);
}


void CGoldDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (1 == nIDEvent)
	{
		m_chartSize.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  
	
		CChartLineSerie *pLineSerie1;
		m_chartSize.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartSize.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xa, ya, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第一条线"));//SetName的作用将在后面讲到 
		m_chartSize.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			ya[i - 1] = ya[i];
// 		}
// 		ya[99] = rand()%2-1;
	}
	if (2 == nIDEvent)
	{
		m_chartSpeed.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartSpeed.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartSpeed.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xb, yb, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第二条线"));//SetName的作用将在后面讲到 
		m_chartSpeed.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yb[i - 1] = yb[i];
// 		}
// 		yb[99] = rand()%20;
	}
	if (3 == nIDEvent)
	{
		m_chartTexture.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartTexture.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartTexture.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xc, yc, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第三条线"));//SetName的作用将在后面讲到 
		m_chartTexture.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yc[i - 1] = yc[i];
// 		}
// 		yc[99] = rand()%10;
	}
	if (4 == nIDEvent)
	{
		m_chartColor.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartColor.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartColor.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xd, yd, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第四条线"));//SetName的作用将在后面讲到 
		m_chartColor.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yd[i - 1] = yd[i];
// 		}
// 		yd[99] = rand()%5;
	}
	CDialog::OnTimer(nIDEvent);
}

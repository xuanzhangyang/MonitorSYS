// AntimonyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "AntimonyDlg.h"
#include "afxdialogex.h"


// CAntimonyDlg 对话框

IMPLEMENT_DYNAMIC(CAntimonyDlg, CDialog)

double xxa[100], yya[100] = { 776.570801, 801.473877, 846.690552, 928.223755, 908.680786, 975.52594, 1000.18396, 1046.539795, 1155.012939, 1157.792358,
1105.509521, 1270.135864, 1194.19873, 839.738281, 966.339844, 1038.463745, 1045.156982, 1033.180908, 1015.76886, 1232.900024, 970.535461, 973.630859, 845.259644,
890.514771, 810.148193, 767.507935, 750.429199, 712.074951, 676.632568, 676.361145, 662.051025, 668.195557, 627.417542, 679.63678, 643.422119, 656.634766,
662.900269, 679.333923, 701.324768, 685.795776, 682.590088, 679.359131, 713.281067, 634.824585, 671.579651, 710.547058, 697.513367, 684.748718, 693.079895, 706.297546,
716.113831, 715.895813, 806.827271, 783.770813, 846.56073, 871.217468, 1276.595703, 924.674866, 859.961365, 893.23407, 702.25647, 674.06012, 692.394897, 691.606628,
848.09137, 975.209717, 940.634094, 977.636658, 1064.161133, 1048.503662, 884.795105, 842.252625, 690.602234, 878.874146, 777.98645, 728.047119, 672.784607, 643.990417,
698.847595, 774.831055, 760.528015, 834.664001, 893.069397, 893.069397, 796.544617, 835.707092, 792.918213, 740.409058, 818.38501, 706.613708, 731.575256, 687.999634,
598.304321, 618.930908, 608.663147, 632.450806, 604.666077, 708.424316, 759.658875, 734.242737 };
double xxb[100], yyb[100] = { 13.1573,
13.0625,
13.0471,
13.0541,
12.9826,
12.9428,
13.0246,
13.0683,
13.1154,
13.1424,
13.2368,
13.3669,
13.4265,
13.5148,
13.4541,
13.4631,
13.4743,
13.4301,
13.2964,
13.2109,
13.1162,
13.0734,
13.0161,
13.0414,
13.0321,
13.1003,
13.1997,
13.245,
13.2505,
13.2511,
13.2607,
13.2883,
13.3396,
13.3799,
13.3965,
13.3448,
13.3212,
13.2273,
13.1053,
13.0696,
13.0826,
13.1035,
13.1305,
13.1267,
13.1177,
13.1131,
13.1457,
13.2415,
13.3169,
13.4466,
13.5109,
13.5527,
13.5897,
13.5981,
13.6323,
13.6278,
13.6049,
13.5247,
13.4384,
13.3933,
13.3793,
13.3875,
13.3705,
13.3623,
13.3729,
13.3961,
13.3986,
13.4499,
13.5048,
13.6105,
13.6304,
13.636,
13.6249,
13.5775,
13.5717,
13.5841,
13.6321,
13.6504,
13.6242,
13.5142,
13.3393,
13.2777,
13.221,
13.1929,
13.1919,
13.2289,
13.2394,
13.2743,
13.2348,
13.1645,
13.1655,
13.2789,
13.2947,
13.3007,
13.2805,
13.2569,
13.1971,
13.1328,
13.0376,
12.9199,
};
double xxc[100], yyc[100] = { 0.96699,
0.963392,
0.969611,
0.974821,
0.965992,
0.967021,
0.962316,
0.96864,
0.965898,
0.969847,
0.971737,
0.967618,
0.959012,
0.970523,
0.960041,
0.957939,
0.963022,
0.971299,
0.958449,
0.952339,
0.964321,
0.961624,
0.967767,
0.968679,
0.976475,
0.969376,
0.968742,
0.972039,
0.974656,
0.97296,
0.973398,
0.969047,
0.967563,
0.96635,
0.97005,
0.964195,
0.975336,
0.959542,
0.966157,
0.971437,
0.974917,
0.9774,
0.968127,
0.968562,
0.974457,
0.966867,
0.970636,
0.967544,
0.966635,
0.970759,
0.969967,
0.966804,
0.971253,
0.960179,
0.966621,
0.964135,
0.967507,
0.966629,
0.955896,
0.962129,
0.971941,
0.969764,
0.966915,
0.968608,
0.974389,
0.971659,
0.970301,
0.970777,
0.966704,
0.965208,
0.959907,
0.967751,
0.970649,
0.965219,
0.969933,
0.977192,
0.973709,
0.972774,
0.969131,
0.970054,
0.974869,
0.971219,
0.967358,
0.962152,
0.963249,
0.965608,
0.966203,
0.971408,
0.96651,
0.975821,
0.975074,
0.97262,
0.973116,
0.968302,
0.974467,
0.96823,
0.968882,
0.966145,
0.972403,
0.970181,
};
double xxd[100], yyd[100] = { 106.041153, 103.963715, 105.615387, 104.967522, 105.433105, 104.896118, 104.720047, 110.649399, 112.016212, 109.02961, 109.144646,
110.957123, 116.830254, 111.070984, 104.057945, 109.529503, 110.411873, 113.144028, 106.897629, 109.379364, 102.612709, 106.275146, 101.323456, 103.412086, 104.189804,
103.314972, 103.530846, 105.071724, 104.351227, 103.362106, 104.865807, 106.028969, 104.987465, 105.847672, 105.750282, 105.821648, 109.011681, 108.306274, 107.631134,
105.926048, 106.872398, 106.063553, 108.20285, 107.578506, 106.486603, 106.893616, 107.566368, 107.252396, 107.367859, 104.892761, 106.046204, 106.079865, 105.802788,
104.407867, 104.718254, 105.751884, 106.996277, 111.398468, 110.383781, 103.573914, 104.545189, 106.36145, 109.326843, 107.971283, 108.549896, 112.327187, 108.021339,
105.984024, 110.933235, 109.955643, 110.101509, 108.861778, 107.32682, 107.960976, 106.899857, 109.163956, 110.203079, 110.698898, 110.288696, 111.293953, 109.058327,
110.206764, 112.594345, 109.242958, 111.157684, 109.968964, 110.401878, 109.065979, 114.00061, 113.554176, 112.487572, 112.093658, 113.017967, 112.691132, 114.599792,
112.887306, 110.358604, 110.929146, 111.467918, 108.229485 };

UINT __cdecl threadVedio(LPVOID lpParameter)
{
	while (TRUE)
	{
		CAntimonyDlg *dlg = (CAntimonyDlg *)lpParameter;
		//dlg->vedioframe = imread("E:\\毕设\\锑粗选视频\\1\\20140608115045Sb\\2.jpg");
		VideoCapture capture("D:\\Desktop\\毕设\\20140608115045Sb.avi");
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
		while (i<frameCount)
		{
			capture >> frame;
			image1 = frame;
		
			dlg->showImage(&image1, IDC_SHOWAVIS);
		
			CString str;
			str.Format(_T("%d"),i++);
			//bt->SetWindowText(str);
			Sleep(delay);
		}
	}
	return 0;
}


CAntimonyDlg::CAntimonyDlg(CWnd* pParent /*=NULL*/)
: CDialog(CAntimonyDlg::IDD, pParent)
{

}

CAntimonyDlg::~CAntimonyDlg()
{
}

void CAntimonyDlg::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(CAntimonyDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CAntimonyDlg 消息处理程序


HBRUSH CAntimonyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (nCtlColor == CTLCOLOR_DLG)  //给对话框的刷子上色，即给对话框设置背景颜色
		return   m_brush;
	if (nCtlColor == CTLCOLOR_STATIC) //设置静态文本框的背景为透明
	{
		pDC->SetBkMode(TRANSPARENT);

		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SelectObject(&m_font);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
void CAntimonyDlg::setbtColor(CButtonST *btst, COLORREF crColor)
{
	btst->SetColor(0, crColor);
	btst->SetColor(2, crColor);
	btst->SetColor(1, RGB(255, 255, 255));
	btst->SetColor(3, RGB(255, 255, 255));
	btst->SetColor(4, crColor);
	btst->SetColor(5, crColor);
}


BOOL CAntimonyDlg::OnInitDialog()
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
	setbtColor(&m_workCondition, RGB(232, 76, 61));
	m_workCondition.SetFont(&m_font1);
	m_workCondition.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_btworkCondition, RGB(232, 76, 61));
	m_btworkCondition.SetFont(&m_font3);
	m_btworkCondition.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_play, RGB(0, 122, 204));
	m_play.SetIcon(IDI_PLAY);
	setbtColor(&m_pause, RGB(0, 122, 204));
	m_pause.SetIcon(IDI_PAUSE);

	GetDlgItem(IDC_SHOWAVIS)->GetClientRect(&picrect);
	//showVedio();
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
		xxa[i] = xxb[i] = xxc[i] = xxd[i] = i;
//		yya[i] = yyb[i] = yyc[i] = yyd[i] = sin(float(i));
	}

	SetTimer(5, 500, NULL);
	SetTimer(6, 500, NULL);
	SetTimer(7, 500, NULL);
	SetTimer(8, 500, NULL);
	AfxBeginThread(threadVedio,this);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CAntimonyDlg::OnCancel()
{
	// TODO:  在此添加专用代码和/或调用基类

	DestroyWindow();
}

void CAntimonyDlg::showImage(IplImage *image, UINT ID)    // ID 是Picture Control控件的ID号
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
void CAntimonyDlg::showVedio()
{
	//VideoCapture capture("E:\\毕设\\锑粗选视频\\1\\20140608115045Sb.avi");
	
	// 	for (int i = 0; i < 100; i++)
	// 	{
	// 		capture >> frame;
	CvSize ImgSize;
	IplImage *theimg;
	ImgSize.width = picrect.Width();
	ImgSize.height = picrect.Height();
	theimg = cvCreateImage(ImgSize, IPL_DEPTH_8U, 3);
	IplImage image = vedioframe;
	resize_image(&image, theimg);
	showImage(theimg, IDC_SHOWAVIS);
	// 		waitKey(30);
	// 	}
}

void CAntimonyDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	//TODO:  在此处添加消息处理程序代码
// 	 	CDialog::OnPaint();
// 	 	CDialog::UpdateWindow();				// 更新windows窗口，如果无这步调用，图片显示还会出现问题
		//showVedio();	// 重绘图片函数
	// 不为绘图消息调用 CDialog::OnPaint()
}
void CAntimonyDlg::resize_image(IplImage* img, IplImage *theimg)
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
	if (a > b)
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


void CAntimonyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	if (5 == nIDEvent)
	{
		m_chartSize.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartSize.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartSize.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xxa, yya, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第一条线"));//SetName的作用将在后面讲到 
		m_chartSize.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yya[i - 1] = yya[i];
// 		}
// 		yya[99] = rand() % 2 - 1;
	}
	if (6 == nIDEvent)
	{
		m_chartSpeed.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartSpeed.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartSpeed.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xxb, yyb, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第二条线"));//SetName的作用将在后面讲到 
		m_chartSpeed.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yyb[i - 1] = yyb[i];
// 		}
// 		yyb[99] = rand() % 20;
	}
	if (7 == nIDEvent)
	{
		m_chartTexture.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartTexture.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartTexture.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xxc, yyc, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第三条线"));//SetName的作用将在后面讲到 
		m_chartTexture.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yyc[i - 1] = yyc[i];
// 		}
// 		yyc[99] = rand() % 10;
	}
	if (8 == nIDEvent)
	{
		m_chartColor.EnableRefresh(false);

		//////////////////////////////////////////////////////////////////////////  
		//画图测试  
		//////////////////////////////////////////////////////////////////////////  

		CChartLineSerie *pLineSerie1;
		m_chartColor.RemoveAllSeries();//先清空  
		pLineSerie1 = m_chartColor.CreateLineSerie();
		pLineSerie1->SetSeriesOrdering(poNoOrdering);//设置为无序  
		pLineSerie1->AddPoints(xxd, yyd, 100);
		pLineSerie1->SetName(_T("这是IDC_ChartCtrl1的第四条线"));//SetName的作用将在后面讲到 
		m_chartColor.EnableRefresh(true);
// 		int i;
// 		for (i = 1; i < 100; ++i)
// 		{
// 			//x[i - 1] = x[i];
// 			yyd[i - 1] = yyd[i];
// 		}
// 		yyd[99] = rand() % 5;
	}
	CDialog::OnTimer(nIDEvent);
}

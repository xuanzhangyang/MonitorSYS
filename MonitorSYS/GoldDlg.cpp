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
}


BEGIN_MESSAGE_MAP(CGoldDlg, CDialog)
	ON_WM_CTLCOLOR()

	ON_WM_PAINT()
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
			bt->SetWindowText(str);
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
	setbtColor(&m_workCondition, RGB(232, 76, 61));
	m_workCondition.SetFont(&m_font1);
	m_workCondition.setfalseColor(RGB(255, 255, 255));
	setbtColor(&m_btworkCondition, RGB(232, 76, 61));
	m_btworkCondition.SetFont(&m_font3);
	m_btworkCondition.setfalseColor(RGB(255, 255, 255));
	
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

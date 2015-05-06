// AntimonyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MonitorSYS.h"
#include "AntimonyDlg.h"
#include "afxdialogex.h"


// CAntimonyDlg �Ի���

IMPLEMENT_DYNAMIC(CAntimonyDlg, CDialog)


UINT __cdecl threadVedio(LPVOID lpParameter)
{
	while (TRUE)
	{
		CAntimonyDlg *dlg = (CAntimonyDlg *)lpParameter;
		//dlg->vedioframe = imread("E:\\����\\���ѡ��Ƶ\\1\\20140608115045Sb\\2.jpg");
		VideoCapture capture("D:\\Desktop\\����\\20140608115045Sb.avi");
		Mat frame;
		IplImage image1;
		if (!capture.isOpened())
		{ 
			MessageBox(NULL, _T("����"), _T("��Ƶ����ʧ�ܣ�"), 1);
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
			bt->SetWindowText(str);
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
}


BEGIN_MESSAGE_MAP(CAntimonyDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CAntimonyDlg ��Ϣ�������


HBRUSH CAntimonyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (nCtlColor == CTLCOLOR_DLG)  //���Ի����ˢ����ɫ�������Ի������ñ�����ɫ
		return   m_brush;
	if (nCtlColor == CTLCOLOR_STATIC) //���þ�̬�ı���ı���Ϊ͸��
	{
		pDC->SetBkMode(TRANSPARENT);

		pDC->SetTextColor(RGB(255, 255, 255));
		pDC->SelectObject(&m_font);
		return   (HBRUSH)::GetStockObject(NULL_BRUSH);
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_brush.CreateSolidBrush(RGB(0, 122, 204));
	m_font.CreatePointFont(120, L"΢���ź�");
	m_font1.CreatePointFont(150, L"΢���ź�");
	m_font2.CreatePointFont(200, L"΢���ź�");
	m_font3.CreatePointFont(170, L"΢���ź�");
	m_font4.CreatePointFont(240, L"΢���ź�");
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
	GetDlgItem(IDC_SHOWAVIS)->GetClientRect(&picrect);
	//showVedio();
	AfxBeginThread(threadVedio,this);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CAntimonyDlg::OnCancel()
{
	// TODO:  �ڴ����ר�ô����/����û���

	DestroyWindow();
}

void CAntimonyDlg::showImage(IplImage *image, UINT ID)    // ID ��Picture Control�ؼ���ID��
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
	cimg.CopyOf(theimg); // ����ͼƬ
	cimg.DrawToHDC(hDC, &picrect); // ��ͼƬ���Ƶ���ʾ�ؼ���ָ��������
	ReleaseDC(pDC);
}
void CAntimonyDlg::showVedio()
{
	//VideoCapture capture("E:\\����\\���ѡ��Ƶ\\1\\20140608115045Sb.avi");
	
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
	//TODO:  �ڴ˴������Ϣ����������
// 	 	CDialog::OnPaint();
// 	 	CDialog::UpdateWindow();				// ����windows���ڣ�������ⲽ���ã�ͼƬ��ʾ�����������
		//showVedio();	// �ػ�ͼƬ����
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
}
void CAntimonyDlg::resize_image(IplImage* img, IplImage *theimg)
{
	// ��ȡͼƬ�Ŀ�͸�
	int w = img->width;
	int h = img->height;

	// �ҳ���͸��еĽϴ�ֵ��
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
	// ���㽫ͼƬ���ŵ�TheImage��������ı�������

	// ���ź�ͼƬ�Ŀ�͸�
	int nw = (int)(w / scale);
	int nh = (int)(h / scale);

	// Ϊ�˽����ź��ͼƬ���� TheImage �����в�λ�������ͼƬ�� TheImage ���Ͻǵ���������ֵ
	int tlx = (nw > nh) ? 0 : (int)(x - nw) / 2;
	int tly = (nw > nh) ? (int)(y - nh) / 2 : 0;
	// ���� TheImage �� ROI ������������ͼƬ img
	cvSetImageROI(theimg, cvRect(tlx, tly, nw, nh));

	// ��ͼƬ img �������ţ������뵽 TheImage ��
	cvResize(img, theimg);

	// ���� TheImage �� ROI ׼��������һ��ͼƬ
	cvResetImageROI(theimg);
}

#pragma once


// COptimizeCtrDlg 对话框

class COptimizeCtrDlg : public CDialog
{
	DECLARE_DYNAMIC(COptimizeCtrDlg)

public:
	COptimizeCtrDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COptimizeCtrDlg();
	virtual void OnCancel();
// 对话框数据
	enum { IDD = IDD_OPTIMIZECTRDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
};

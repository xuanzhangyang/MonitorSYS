#pragma once


// CConditionDlg 对话框

class CConditionDlg : public CDialog
{
	DECLARE_DYNAMIC(CConditionDlg)

public:
	CConditionDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConditionDlg();
	virtual void OnCancel();
// 对话框数据
	enum { IDD = IDD_CONDITIONDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	
};

#pragma once
#include "MyBaseDlg.h"



class MainDlg :
    public MyBaseDlg
{
public:
	MainDlg(
		CWnd* pParent = nullptr
	);


	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedX();
	afx_msg void OnBnClickedMin();
	afx_msg void OnBnClickedAbout();
	CEdit EditResult;
};
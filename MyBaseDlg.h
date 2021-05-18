// PGENDlg.h: 头文件
//

#pragma once
#include "PGenerator.h"



// CPGENDlg 对话框


class MyBaseDlg : public CDialogEx
{
private:
	CPoint mousePosition;
	bool mouseIsMoving;
	LPCTSTR title;

protected:
	static PGenerator& iGener;

// 构造
public:
	// 标准构造函数
	MyBaseDlg(
		LPCTSTR inTitle,
		UINT nID_DLG,
		UINT nID_ICON,
		CWnd* pParent = nullptr
	);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
};
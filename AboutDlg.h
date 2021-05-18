#pragma once
#include "MyBaseDlg.h"



class AboutDlg :
    public MyBaseDlg
{
public:
    AboutDlg(
        CWnd* pParent = nullptr);


    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUT };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedAx();
};


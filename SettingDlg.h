#pragma once
#include "MyBaseDlg.h"



class SettingDlg :
    public MyBaseDlg
{
public:
    SettingDlg(
        CWnd* pParent = nullptr);


    // 对话框数据
#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_SETTING };
#endif
    
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();
    DECLARE_MESSAGE_MAP()

public:

    afx_msg void OnBnClickedSx();
    CButton CheckNum;
    CButton CheckLowCase;
    CButton CheckUpCase;
    CButton CheckSymbol;
    CButton CheckCopy;
    CButton CheckLog;
    CSpinButtonCtrl SpinDigit;
    CEdit EditDigit;
    afx_msg void OnBnClickedCheckNum();
    afx_msg void OnBnClickedCheckLowcase();
    afx_msg void OnBnClickedCheckUpcase();
    afx_msg void OnBnClickedCheckSymbol();
    afx_msg void OnBnClickedCheckCopy();
    afx_msg void OnBnClickedCheckLog();
    afx_msg void OnEnChangeEditDigit();
};


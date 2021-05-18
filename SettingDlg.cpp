#include "pch.h"
#include "HeadBundle.h"
#include "SettingDlg.h"



//全局常量区
static const int DIGIT_MAX = 5;



//名称空间区



SettingDlg::SettingDlg(
	CWnd* pParent/* = nullptr*/)
	:MyBaseDlg(
		L"Setting",
		IDD_SETTING,
		IDR_MAINFRAME
	)
{

}

void SettingDlg::DoDataExchange(CDataExchange* pDX)
{
	MyBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_NUM, CheckNum);
	DDX_Control(pDX, IDC_CHECK_LOWCASE, CheckLowCase);
	DDX_Control(pDX, IDC_CHECK_UPCASE, CheckUpCase);
	DDX_Control(pDX, IDC_CHECK_SYMBOL, CheckSymbol);
	DDX_Control(pDX, IDC_CHECK_COPY, CheckCopy);
	DDX_Control(pDX, IDC_CHECK_LOG, CheckLog);
	DDX_Control(pDX, IDC_SPIN_DIGIT, SpinDigit);
	DDX_Control(pDX, IDC_EDIT_DIGIT, EditDigit);
}

BOOL SettingDlg::OnInitDialog()
{
	MyBaseDlg::OnInitDialog();

	//initialize editbox 
	EditDigit.SetLimitText(5);


	//initialize spincontorl
	//buddy must be first
	SpinDigit.SetBuddy(GetDlgItem(IDC_EDIT_DIGIT));
	//range must be there,otherwish set pos will be truncate
	SpinDigit.SetRange32(2, 256);
	//set post must be above set base 
	//because set base will contact event onchange
	SpinDigit.SetPos(iGener.getDigit());
	SpinDigit.SetBase(10);
	
	

	//initialize check box
	CheckNum.SetCheck(iGener.getNumState());
	CheckLowCase.SetCheck(iGener.getLowCaseStata());
	CheckUpCase.SetCheck(iGener.getUpCaseState());
	CheckSymbol.SetCheck(iGener.getSymbolState());
	CheckCopy.SetCheck(iGener.getCopyState());
	CheckLog.SetCheck(iGener.getLogState());
	

	return 0;
}

BEGIN_MESSAGE_MAP(SettingDlg, MyBaseDlg)
	ON_BN_CLICKED(ID_SX, &SettingDlg::OnBnClickedSx)
	ON_BN_CLICKED(IDC_CHECK_NUM, &SettingDlg::OnBnClickedCheckNum)
	ON_BN_CLICKED(IDC_CHECK_LOWCASE, &SettingDlg::OnBnClickedCheckLowcase)
	ON_BN_CLICKED(IDC_CHECK_UPCASE, &SettingDlg::OnBnClickedCheckUpcase)
	ON_BN_CLICKED(IDC_CHECK_SYMBOL, &SettingDlg::OnBnClickedCheckSymbol)
	ON_BN_CLICKED(IDC_CHECK_COPY, &SettingDlg::OnBnClickedCheckCopy)
	ON_BN_CLICKED(IDC_CHECK_LOG, &SettingDlg::OnBnClickedCheckLog)
	ON_EN_CHANGE(IDC_EDIT_DIGIT, &SettingDlg::OnEnChangeEditDigit)
END_MESSAGE_MAP()


void SettingDlg::OnBnClickedSx()
{
	// TODO: 在此添加控件通知处理程序代码

	//if (iGener.IsDirt())
	//{
	//	iGener.SaveConfigToFile();
	//}
	
	this->OnOK();
}


void SettingDlg::OnBnClickedCheckNum()
{
	// TODO: 在此添加控件通知处理程序代码
	iGener.setNumState(CheckNum.GetCheck());
}


void SettingDlg::OnBnClickedCheckLowcase()
{
	// TODO: 在此添加控件通知处理程序代码
	iGener.setLowCaseState(CheckLowCase.GetCheck());
}


void SettingDlg::OnBnClickedCheckUpcase()
{
	// TODO: 在此添加控件通知处理程序代码
	iGener.setUpCaseState(CheckUpCase.GetCheck());
}


void SettingDlg::OnBnClickedCheckSymbol()
{
	// TODO: 在此添加控件通知处理程序代码
	iGener.setSymbolState(CheckSymbol.GetCheck());
}


void SettingDlg::OnBnClickedCheckCopy()
{
	// TODO: 在此添加控件通知处理程序代码
	iGener.setCopyState(CheckCopy.GetCheck());
}


void SettingDlg::OnBnClickedCheckLog()
{
	// TODO: 在此添加控件通知处理程序代码
	iGener.setLogState(CheckLog.GetCheck());
}


void SettingDlg::OnEnChangeEditDigit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 MyBaseDlg::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	
	// TODO:  在此添加控件通知处理程序代码

	wchar_t digitTW[DIGIT_MAX]{ L"0000" };

	EditDigit.GetWindowTextW(digitTW, DIGIT_MAX);
	int digitT = iGener.getDigit(),
		digitN = _wtoi(digitTW);

	if (digitT != digitN)//exception
	{
		iGener.setDigit(digitN);
	}

}

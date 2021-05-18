#include "pch.h"
#include "HeadBundle.h"
#include "MainDlg.h"



MainDlg::MainDlg(
	CWnd* pParent/* = nullptr*/)
	:MyBaseDlg(
		L"Password Generator",
		IDD_MAIN,
		IDR_MAINFRAME
	)
{

}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	MyBaseDlg::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_RESULT, EditResult);
}

//可能需要将自己的消息映射
BEGIN_MESSAGE_MAP(MainDlg, MyBaseDlg)
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(ID_X, &MainDlg::OnBnClickedX)
	ON_BN_CLICKED(ID_MIN, &MainDlg::OnBnClickedMin)
	ON_BN_CLICKED(IDC_ABOUT, &MainDlg::OnBnClickedAbout)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	MyBaseDlg::OnInitDialog();

	EditResult.SetLimitText(PATH_MAX);//260

	return 0;
}


void MainDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 鼠标右键双击
	// 打开设置窗口

	SettingDlg dlg;
	dlg.DoModal();

	MyBaseDlg::OnRButtonDblClk(nFlags, point);
}


void MainDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	// 鼠标左键双击
	// 生成密码

	EditResult.SetWindowTextW(iGener.GenAPass());

	MyBaseDlg::OnLButtonDblClk(nFlags, point);
}


void MainDlg::OnBnClickedX()
{
	// TODO: 在此添加控件通知处理程序代码
	this->OnOK();
}


void MainDlg::OnBnClickedMin()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_MINIMIZE);
}


void MainDlg::OnBnClickedAbout()
{
	// TODO: 在此添加控件通知处理程序代码
	AboutDlg dlg;
	dlg.DoModal();
}

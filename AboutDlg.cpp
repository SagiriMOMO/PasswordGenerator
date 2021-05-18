#include "pch.h"
#include "HeadBundle.h"
#include "AboutDlg.h"



AboutDlg::AboutDlg(
	CWnd* pParent/* = nullptr*/)
	:MyBaseDlg(
		/*pGener,*/
		L"About",
		IDD_ABOUT,
		IDR_MAINFRAME
	)
{

}

void AboutDlg::DoDataExchange(CDataExchange* pDX)
{
	MyBaseDlg::DoDataExchange(pDX);
}

BOOL AboutDlg::OnInitDialog()
{
	MyBaseDlg::OnInitDialog();
	return 0;
}

BEGIN_MESSAGE_MAP(AboutDlg, MyBaseDlg)
	ON_BN_CLICKED(ID_AX, &AboutDlg::OnBnClickedAx)
END_MESSAGE_MAP()


void AboutDlg::OnBnClickedAx()
{
	// TODO: 在此添加控件通知处理程序代码

	this->OnOK();
	
}

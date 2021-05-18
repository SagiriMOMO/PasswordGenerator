// PGENDlg.cpp: 实现文件
//

#include "pch.h"
#include "MyBaseDlg.h"
#include "resource.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#endif


PGenerator GEN;
PGenerator& MyBaseDlg::iGener = GEN;
// CPGENDlg 对话框



MyBaseDlg::MyBaseDlg(
	LPCTSTR inTitle,
	UINT nID_DLG,
	UINT nID_ICON,
	CWnd* pParent/*=nullptr*/)
	: CDialogEx(nID_DLG, pParent)
{
	mousePosition = 0;
	mouseIsMoving = false;
	title = inTitle;

//	LoadLibrary(_T("RICHED32.DLL"));

	m_hIcon = AfxGetApp()->LoadIcon(nID_ICON);
}

void MyBaseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(MyBaseDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ACTIVATE()
END_MESSAGE_MAP()


// CPGENDlg 消息处理程序

BOOL MyBaseDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowTextW(title);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void MyBaseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND,
			reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR MyBaseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void MyBaseDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	mouseIsMoving = true;
	SetCapture();
	mousePosition = point;

	CDialogEx::OnLButtonDown(nFlags, point);
}

void MyBaseDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (mouseIsMoving)
	{
		mouseIsMoving = false;
		ReleaseCapture();
	}

	CDialogEx::OnLButtonUp(nFlags, point);
}

void MyBaseDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (mouseIsMoving
		&& mousePosition.x > 0
		&& mousePosition.y > 0
		&& mousePosition.y < 30)
	{
		CPoint dynamic;
		dynamic.x = point.x - mousePosition.x;
		dynamic.y = point.y - mousePosition.y;

		if (abs(dynamic.x) > 1 || abs(dynamic.y) > 1)
		{
			CRect rect(0, 0, 0, 0);
			GetWindowRect(&rect);

			//整个窗口偏移
			OffsetRect(&rect, dynamic.x, dynamic.y);

			//移动窗口
			MoveWindow(&rect);
		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}

void MyBaseDlg::OnActivate(
	UINT nState, 
	CWnd* pWndOther, 
	BOOL bMinimized)
{
	CDialogEx::OnActivate(nState, pWndOther, bMinimized);

	// TODO: 在此处添加消息处理程序代码
	if (nState == WA_INACTIVE && mouseIsMoving)
	{
		mouseIsMoving = false;
		ReleaseCapture();
	}
}
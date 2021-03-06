
// Chap9Exa8Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Chap9Exa8.h"
#include "Chap9Exa8Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChap9Exa8Dlg 对话框



CChap9Exa8Dlg::CChap9Exa8Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHAP9EXA8_DIALOG, pParent)
	, m_English(0)
	, m_DateCheck(FALSE)
	, m_TimeCheck(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChap9Exa8Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_DATE_CHECK, m_DateCheck);
	//  DDX_Control(pDX, IDC_TIME_CHECK, m_TimeCheck);
	DDX_Control(pDX, IDC_DATE_EDIT, m_DateEdit);
	DDX_Control(pDX, IDC_TIME_EDIT, m_TimeEdit);
	DDX_Control(pDX, IDC_Result_EDIT, m_ResultEdit);
	DDX_Control(pDX, IDC_SHOWCOMBO_EDIT, m_ComboEdit);
	DDX_Control(pDX, IDC_RECORD_COMBO, m_Record);
	DDX_Check(pDX, IDC_DATE_CHECK, m_DateCheck);
	DDX_Check(pDX, IDC_TIME_CHECK, m_TimeCheck);
}

BEGIN_MESSAGE_MAP(CChap9Exa8Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CChap9Exa8Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_ENABLE_BUTTON, &CChap9Exa8Dlg::OnBnClickedEnableButton)
	ON_BN_CLICKED(IDC_DISABLE_BUTTON, &CChap9Exa8Dlg::OnBnClickedDisableButton)
	ON_BN_CLICKED(IDC_DATE_CHECK, &CChap9Exa8Dlg::OnBnClickedDateCheck)
	ON_BN_CLICKED(IDC_TIME_CHECK, &CChap9Exa8Dlg::OnBnClickedTimeCheck)
	ON_BN_CLICKED(IDC_SHOW_BUTTON, &CChap9Exa8Dlg::OnBnClickedShowButton)
	ON_BN_CLICKED(IDC_HIDE_BUTTON, &CChap9Exa8Dlg::OnBnClickedHideButton)
	ON_BN_CLICKED(IDC_Show_SeX_Age_BUTTON, &CChap9Exa8Dlg::OnBnClickedShowSexAgeButton)
	ON_BN_CLICKED(IDC_SHOWCOMBO_BUTTON, &CChap9Exa8Dlg::OnBnClickedShowcomboButton)
END_MESSAGE_MAP()


// CChap9Exa8Dlg 消息处理程序

BOOL CChap9Exa8Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChap9Exa8Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChap9Exa8Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChap9Exa8Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChap9Exa8Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}


void CChap9Exa8Dlg::OnBnClickedEnableButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_DATE_CHECK)->EnableWindow(TRUE);
	GetDlgItem(IDC_TIME_CHECK)->EnableWindow(TRUE);
	m_DateEdit.EnableWindow(TRUE);
	m_TimeEdit.EnableWindow(TRUE);
}


void CChap9Exa8Dlg::OnBnClickedDisableButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_DATE_CHECK)->EnableWindow(FALSE);
	GetDlgItem(IDC_TIME_CHECK)->EnableWindow(FALSE);
	m_DateEdit.EnableWindow(FALSE);
	m_TimeEdit.EnableWindow(FALSE);
}


void CChap9Exa8Dlg::OnBnClickedDateCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if(m_DateCheck==TRUE)
	{
		CTime tNow;
		tNow = CTime::GetCurrentTime();
		CString sNow = tNow.Format("%Y.%m.%d");
		m_DateEdit.SetSel(0, -1);
		m_DateEdit.ReplaceSel(sNow);
	}
	else
	{
		m_DateEdit.SetSel(0, -1);
		m_DateEdit.ReplaceSel(L"");
	}
	UpdateData(FALSE);
}


void CChap9Exa8Dlg::OnBnClickedTimeCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_TimeCheck==TRUE) 
	{
		CTime tNow;
		tNow = CTime::GetCurrentTime();
		CString sNow = tNow.Format("%I:%M:%S");
		m_TimeEdit.SetSel(0,-1);
		m_TimeEdit.ReplaceSel(sNow);
	}
	else
	{
		m_TimeEdit.SetSel(0, -1);
		m_TimeEdit.ReplaceSel(L"");
	}
	UpdateData(FALSE);
}


void CChap9Exa8Dlg::OnBnClickedShowButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_DATE_CHECK)->EnableWindow(SW_SHOW);
	GetDlgItem(IDC_TIME_CHECK)->EnableWindow(SW_SHOW);
	GetDlgItem(IDC_DATE_EDIT)->EnableWindow(SW_SHOW);
	m_DateEdit.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_TIME_EDIT)->EnableWindow(SW_SHOW);
	m_TimeEdit.ShowWindow(SW_SHOW);
}


void CChap9Exa8Dlg::OnBnClickedHideButton()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_DATE_EDIT)->EnableWindow(SW_HIDE);
	GetDlgItem(IDC_TIME_EDIT)->EnableWindow(SW_HIDE);
	m_DateEdit.ShowWindow(SW_HIDE);
	m_TimeEdit.ShowWindow(SW_HIDE);
}


void CChap9Exa8Dlg::OnBnClickedShowSexAgeButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CChap9Exa8Dlg::OnBnClickedShowcomboButton()
{
	// TODO: 在此添加控件通知处理程序代码
}

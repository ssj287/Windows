
// Chap9Exa5Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Chap9Exa5.h"
#include "Chap9Exa5Dlg.h"
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


// CChap9Exa5Dlg 对话框



CChap9Exa5Dlg::CChap9Exa5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHAP9EXA5_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChap9Exa5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}

BEGIN_MESSAGE_MAP(CChap9Exa5Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_SHOW1, &CChap9Exa5Dlg::OnBnClickedBtnShow1)
	ON_BN_CLICKED(IDC_BTN_CLEAR1, &CChap9Exa5Dlg::OnBnClickedBtnClear1)
	ON_BN_CLICKED(IDC_BTN_SHOW2, &CChap9Exa5Dlg::OnBnClickedBtnShow2)
	ON_BN_CLICKED(IDC_CLEAR2, &CChap9Exa5Dlg::OnBnClickedClear2)
	ON_BN_CLICKED(IDC_BTN_EXIT, &CChap9Exa5Dlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_BTN_TRANSFER, &CChap9Exa5Dlg::OnBnClickedBtnTransfer)
	ON_BN_CLICKED(IDC_BTN_UNDO, &CChap9Exa5Dlg::OnBnClickedBtnUndo)
END_MESSAGE_MAP()


// CChap9Exa5Dlg 消息处理程序

BOOL CChap9Exa5Dlg::OnInitDialog()
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

void CChap9Exa5Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChap9Exa5Dlg::OnPaint()
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
HCURSOR CChap9Exa5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChap9Exa5Dlg::OnBnClickedBtnShow1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetSel(0, -1);
	m_edit1.ReplaceSel(_T("This is the First Editshow"));
}


void CChap9Exa5Dlg::OnBnClickedBtnClear1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetSel(0, -1);
	m_edit1.ReplaceSel(_T(""));
}


void CChap9Exa5Dlg::OnBnClickedBtnShow2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit2.SetSel(0, -1);
	m_edit2.ReplaceSel(_T("This is the Second Editshow"));
}


void CChap9Exa5Dlg::OnBnClickedClear2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit2.SetSel(0, -1);
	m_edit2.ReplaceSel(_T(""));
}


void CChap9Exa5Dlg::OnBnClickedBtnExit()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}


void CChap9Exa5Dlg::OnBnClickedBtnTransfer()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.SetSel(0, -1);
	m_edit1.Copy();
	m_edit2.SetSel(0. - 1);
	m_edit2.ReplaceSel(_T(""));
	m_edit2.Paste();
}


void CChap9Exa5Dlg::OnBnClickedBtnUndo()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit1.Undo();
	m_edit2.Undo();
}

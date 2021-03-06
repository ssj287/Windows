
// Chap9Exa2Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Chap9Exa2.h"
#include "Chap9Exa2Dlg.h"
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


// CChap9Exa2Dlg 对话框



CChap9Exa2Dlg::CChap9Exa2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHAP9EXA2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChap9Exa2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_scrollbar);
	DDX_Control(pDX, IDC_EDIT1, m_dispinfo);
}

BEGIN_MESSAGE_MAP(CChap9Exa2Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CChap9Exa2Dlg::OnBnClickedButton4)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON1, &CChap9Exa2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CChap9Exa2Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CChap9Exa2Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CChap9Exa2Dlg 消息处理程序

BOOL CChap9Exa2Dlg::OnInitDialog()
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
	m_scrollbar.SetScrollRange(0, 20);
	m_scrollbar.SetScrollPos(10);
	ChangeDisplayInfo(m_scrollbar.GetScrollPos());
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CChap9Exa2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChap9Exa2Dlg::OnPaint()
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
HCURSOR CChap9Exa2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CChap9Exa2Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}

void CChap9Exa2Dlg::ChangeDisplayInfo(int pos)
{
	TCHAR sPos[10];
	_itow(pos, sPos, 10);
	m_dispinfo.SetSel(0, -1);
	m_dispinfo.ReplaceSel(sPos);
	UpdateData(FALSE);
}


void CChap9Exa2Dlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int iNowPos;
	switch (nSBCode)
	{
		if (pScrollBar == &m_scrollbar)
		{
	case SB_THUMBTRACK:
		m_scrollbar.SetScrollPos(nPos);
		ChangeDisplayInfo(m_scrollbar.GetScrollPos());
		}
	case SB_LINEDOWN:
		iNowPos = m_scrollbar.GetScrollPos();
		iNowPos = iNowPos + 1;
		if (iNowPos>20) 
		{
			iNowPos = 20;
		}
		m_scrollbar.SetScrollPos(iNowPos);
		ChangeDisplayInfo(m_scrollbar.GetScrollPos());
		break;
	case SB_LINEUP:
		iNowPos = m_scrollbar.GetScrollPos();
		iNowPos = iNowPos - 1;
		if (iNowPos<0)
		{
			iNowPos = 0;
		}
		m_scrollbar.SetScrollPos(iNowPos);
		ChangeDisplayInfo(m_scrollbar.GetScrollPos());
		break;
	case SB_PAGEDOWN:iNowPos = m_scrollbar.GetScrollPos();
		iNowPos = iNowPos + 3;
		if (iNowPos>20)
		{
			iNowPos = 20;
		}
		m_scrollbar.SetScrollPos(iNowPos);
		ChangeDisplayInfo(m_scrollbar.GetScrollPos());
		break;
	case SB_PAGEUP:
		iNowPos = m_scrollbar.GetScrollPos();
		iNowPos = iNowPos - 3;
		if (iNowPos<0)
		{
			iNowPos = 0;
		}
		m_scrollbar.SetScrollPos(iNowPos);
		ChangeDisplayInfo(m_scrollbar.GetScrollPos());
		break;
	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CChap9Exa2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_scrollbar.SetScrollPos(0);
	ChangeDisplayInfo(m_scrollbar.GetScrollPos());
}


void CChap9Exa2Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_scrollbar.SetScrollPos(20);
	ChangeDisplayInfo(m_scrollbar.GetScrollPos());
}


void CChap9Exa2Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_scrollbar.SetScrollPos(10);
	ChangeDisplayInfo(m_scrollbar.GetScrollPos());
}

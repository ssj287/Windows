// exer_9_17Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "exer_9_17.h"
#include "exer_9_17Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExer_9_17Dlg dialog

CExer_9_17Dlg::CExer_9_17Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CExer_9_17Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CExer_9_17Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExer_9_17Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CExer_9_17Dlg)
	DDX_Control(pDX, IDC_COMBO_BRUSHCOLOR, m_ComboBrushColor);
	DDX_Control(pDX, IDC_COMBO_PENCOLOR, m_ComboPenColor);
	DDX_Control(pDX, IDC_LIST_SHAPE, m_ListShape);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CExer_9_17Dlg, CDialog)
	//{{AFX_MSG_MAP(CExer_9_17Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_SOLID, OnRadioSolid)
	ON_BN_CLICKED(IDC_RADIO_DASH, OnRadioDash)
	ON_BN_CLICKED(IDC_RADIO_DOT, OnRadioDot)
	ON_BN_CLICKED(IDC_RADIO_DASHDOT, OnRadioDashdot)
	ON_BN_CLICKED(IDC_RADIO_SOLIDBRUSH, OnRadioSolidbrush)
	ON_BN_CLICKED(IDC_RADIO_CROSS, OnRadioCross)
	ON_BN_CLICKED(IDC_RADIO_FDIAGONAL, OnRadioFdiagonal)
	ON_BN_CLICKED(IDC_RADIO_BDIAGONAL, OnRadioBdiagonal)
	ON_CBN_SELENDOK(IDC_COMBO_PENCOLOR, OnSelendokComboPencolor)
	ON_CBN_SELENDOK(IDC_COMBO_BRUSHCOLOR, OnSelendokComboBrushcolor)
	ON_BN_CLICKED(IDC_BTN_DRAW, OnBtnDraw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CExer_9_17Dlg message handlers

BOOL CExer_9_17Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
   m_ListShape.AddString("Line");
   m_ListShape.AddString("Circle");
   m_ListShape.AddString("Rectangle");
   m_ListShape.AddString("RoundRectangle");

   m_crPenColor=RGB(255,0,0);       //默认笔颜色
   m_crBrushColor=RGB(255,0,0);       //默认刷子颜色
   m_nPenStyle=PS_SOLID;             //默认笔样式
   m_nBrushStyle=0;                  //默认刷样式为Solid
   m_ComboPenColor.SetCurSel(0);      //设置Pen组合框的当前选项
   m_ComboBrushColor.SetCurSel(0);      //设置Brush组合框的当前选项
   m_ListShape.SetCurSel(0);            //设置默认的Shape
//设置单选按钮的初始状态
CheckRadioButton(IDC_RADIO_SOLID,IDC_RADIO_DASHDOT,IDC_RADIO_SOLID);
CheckRadioButton(IDC_RADIO_SOLIDBRUSH,IDC_RADIO_BDIAGONAL,IDC_RADIO_SOLIDBRUSH);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CExer_9_17Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExer_9_17Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExer_9_17Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CExer_9_17Dlg::OnRadioSolid() 
{
	// TODO: Add your control notification handler code here
    m_nPenStyle=PS_SOLID;  
	
}

void CExer_9_17Dlg::OnRadioDash() 
{
	// TODO: Add your control notification handler code here
   m_nPenStyle=PS_DASH;       //笔样式为划线
	
}

void CExer_9_17Dlg::OnRadioDot() 
{
	// TODO: Add your control notification handler code here
   m_nPenStyle=PS_DOT;     //笔样式为点线
	
}

void CExer_9_17Dlg::OnRadioDashdot() 
{
	// TODO: Add your control notification handler code here
	m_nPenStyle=PS_DASHDOT;    //笔样式为点划线
}

void CExer_9_17Dlg::OnRadioSolidbrush() 
{
	// TODO: Add your control notification handler code here
   m_nBrushStyle=0;      //填充模式为实填充
	
}

void CExer_9_17Dlg::OnRadioCross() 
{
	// TODO: Add your control notification handler code here
	m_nBrushStyle=HS_CROSS;      //填充模式为交叉线
}

void CExer_9_17Dlg::OnRadioFdiagonal() 
{
	// TODO: Add your control notification handler code here
	m_nBrushStyle=HS_FDIAGONAL;      //填充模式为向上45度线
}

void CExer_9_17Dlg::OnRadioBdiagonal() 
{
	// TODO: Add your control notification handler code here
	m_nBrushStyle=HS_BDIAGONAL;      //填充模式为向下45度线
}

void CExer_9_17Dlg::OnSelendokComboPencolor() 
{
	// TODO: Add your control notification handler code here
   int i;
   i=m_ComboPenColor.GetCurSel();  //画笔颜色组合框的当前选项标号
   if(i==0)
   {
    	m_crPenColor=RGB(255,0,0);  //第1项为红色
   }
   else if(i==1)
   {
    	m_crPenColor=RGB(0,255,0);   //第2项为绿色
   }
   else if(i==2)
   {
 	m_crPenColor=RGB(0,0,255);   //第3项为蓝色
   }
   else if(i==3)
   {
	m_crPenColor=RGB(255,255,0);   //第4项为黄色
   }
  else if(i==4)
  {
	m_crPenColor=RGB(0,255,255);   //第5项为天蓝色
  }

	
}

void CExer_9_17Dlg::OnSelendokComboBrushcolor() 
{
	// TODO: Add your control notification handler code here
  int i;
  i=m_ComboBrushColor.GetCurSel();  //画刷颜色组合框的当前选项标号
  if(i==0)
  {
 	m_crBrushColor=RGB(255,0,0);  //第1项为红色
  }
   else if(i==1)
  {
	m_crBrushColor=RGB(100,255,255);   //第2项为绿色
  }
  else if(i==2)
  {
	m_crBrushColor=RGB(0,0,255);   //第3项为蓝色
  }
  else if(i==3)
  {
	m_crBrushColor=RGB(255,255,0);   //第4项为黄色
  }
  else if(i==4)
  {
	m_crBrushColor=RGB(0,255,255);   //第5项为天蓝色
  }
	
}

void CExer_9_17Dlg::OnBtnDraw() 
{
	// TODO: Add your control notification handler code here
    CClientDC dc(this);     //得到设备环境指针
	CPen *ppenOld,penNew;    //定义笔对象
	CBrush *pbrushOld,brushNew,brushBack;    //定义画刷对象
	CRect rectClient;       //定义用户区矩形大小
	GetClientRect(&rectClient);  //得到用户区矩形大小
	CRect rectDraw(rectClient.right-170,20,rectClient.right-20,170); //定义图形区大小
	//用白色画刷画图形区
	brushBack.CreateSolidBrush(RGB(255,255,255));
	pbrushOld=dc.SelectObject(&brushBack);
	dc.Rectangle(rectDraw);

	if(m_nBrushStyle!=0)        //定义画刷
	{
		brushNew.CreateHatchBrush(m_nBrushStyle,m_crBrushColor);
	}
	else
	{
		brushNew.CreateSolidBrush(m_crBrushColor);
	}
	
	penNew.CreatePen(m_nPenStyle,1,m_crPenColor);    //定义笔
	ppenOld=dc.SelectObject(&penNew);                //选入设备环境
	dc.SelectObject(&brushNew);
	if(m_ListShape.GetSel(0))           //画线
	{
		dc.MoveTo(rectDraw.left,(rectDraw.top+rectDraw.bottom)/2);
		dc.LineTo((rectDraw.right+rectDraw.left)/2,(rectDraw.top+rectDraw.bottom)/2);
		//dc.MoveTo((rectDraw.right+rectDraw.left)/2,(rectDraw.top+rectDraw.bottom)/2);
		dc.LineTo((rectDraw.right+rectDraw.left)/2,rectDraw.bottom);
        dc.MoveTo(rectDraw.left,(rectDraw.top+rectDraw.bottom)/2);
        dc.LineTo((rectDraw.right+rectDraw.left)/2,rectDraw.bottom);
	}
	else if(m_ListShape.GetSel(1))    //画圆
	{
		dc.Pie(rectDraw.left,rectDraw.top,rectDraw.right,rectDraw.bottom,(rectDraw.right+rectDraw.left)/2,rectDraw.top,rectDraw.left,(rectDraw.top+rectDraw.bottom)/2);
		//dc.MoveTo(rectDraw.left,(rectDraw.top+rectDraw.bottom)/2);
		//dc.LineTo((rectDraw.right+rectDraw.left)/2,(rectDraw.top+rectDraw.bottom)/2);
        //dc.MoveTo((rectDraw.right+rectDraw.left)/2,(rectDraw.top+rectDraw.bottom)/2);
		//dc.LineTo((rectDraw.right+rectDraw.left)/2,rectDraw.top);
	}
	else if(m_ListShape.GetSel(2))    //画矩形
	{
		dc.Rectangle(rectDraw);
	}
	else if(m_ListShape.GetSel(3))     //画圆角矩形
	{
		dc.RoundRect(rectDraw,CPoint(50,50));
	}
	dc.SelectObject(ppenOld);
	dc.SelectObject(pbrushOld);
}

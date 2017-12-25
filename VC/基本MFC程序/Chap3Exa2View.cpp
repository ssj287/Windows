// Chap3Exa2View.cpp : implementation of the CChap3Exa2View class
//

#include "stdafx.h"
#include "Chap3Exa2.h"

#include "Chap3Exa2Doc.h"
#include "Chap3Exa2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2View

IMPLEMENT_DYNCREATE(CChap3Exa2View, CScrollView)

BEGIN_MESSAGE_MAP(CChap3Exa2View, CScrollView)
	//{{AFX_MSG_MAP(CChap3Exa2View)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2View construction/destruction

CChap3Exa2View::CChap3Exa2View()
{
	// TODO: add construction code here

}

CChap3Exa2View::~CChap3Exa2View()
{
}

BOOL CChap3Exa2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2View drawing

void CChap3Exa2View::OnDraw(CDC* pDC)
{
	CChap3Exa2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

void CChap3Exa2View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2View printing

BOOL CChap3Exa2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChap3Exa2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChap3Exa2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2View diagnostics

#ifdef _DEBUG
void CChap3Exa2View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CChap3Exa2View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CChap3Exa2Doc* CChap3Exa2View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChap3Exa2Doc)));
	return (CChap3Exa2Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2View message handlers

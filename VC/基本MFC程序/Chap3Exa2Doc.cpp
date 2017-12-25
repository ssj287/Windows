// Chap3Exa2Doc.cpp : implementation of the CChap3Exa2Doc class
//

#include "stdafx.h"
#include "Chap3Exa2.h"

#include "Chap3Exa2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2Doc

IMPLEMENT_DYNCREATE(CChap3Exa2Doc, CDocument)

BEGIN_MESSAGE_MAP(CChap3Exa2Doc, CDocument)
	//{{AFX_MSG_MAP(CChap3Exa2Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2Doc construction/destruction

CChap3Exa2Doc::CChap3Exa2Doc()
{
	// TODO: add one-time construction code here

}

CChap3Exa2Doc::~CChap3Exa2Doc()
{
}

BOOL CChap3Exa2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2Doc serialization

void CChap3Exa2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2Doc diagnostics

#ifdef _DEBUG
void CChap3Exa2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CChap3Exa2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2Doc commands

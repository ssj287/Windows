// Chap3Exa2View.h : interface of the CChap3Exa2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAP3EXA2VIEW_H__690A5961_50F4_4C44_96ED_7FA89A6E87CC__INCLUDED_)
#define AFX_CHAP3EXA2VIEW_H__690A5961_50F4_4C44_96ED_7FA89A6E87CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChap3Exa2View : public CScrollView
{
protected: // create from serialization only
	CChap3Exa2View();
	DECLARE_DYNCREATE(CChap3Exa2View)

// Attributes
public:
	CChap3Exa2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChap3Exa2View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChap3Exa2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChap3Exa2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in Chap3Exa2View.cpp
inline CChap3Exa2Doc* CChap3Exa2View::GetDocument()
   { return (CChap3Exa2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAP3EXA2VIEW_H__690A5961_50F4_4C44_96ED_7FA89A6E87CC__INCLUDED_)

// Chap3Exa2Doc.h : interface of the CChap3Exa2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAP3EXA2DOC_H__41C156D0_8F52_469F_B420_01EC3F19383F__INCLUDED_)
#define AFX_CHAP3EXA2DOC_H__41C156D0_8F52_469F_B420_01EC3F19383F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChap3Exa2Doc : public CDocument
{
protected: // create from serialization only
	CChap3Exa2Doc();
	DECLARE_DYNCREATE(CChap3Exa2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChap3Exa2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChap3Exa2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChap3Exa2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAP3EXA2DOC_H__41C156D0_8F52_469F_B420_01EC3F19383F__INCLUDED_)

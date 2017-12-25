// Chap3Exa2.h : main header file for the CHAP3EXA2 application
//

#if !defined(AFX_CHAP3EXA2_H__488C5605_0266_49B4_A06F_992606252D56__INCLUDED_)
#define AFX_CHAP3EXA2_H__488C5605_0266_49B4_A06F_992606252D56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CChap3Exa2App:
// See Chap3Exa2.cpp for the implementation of this class
//

class CChap3Exa2App : public CWinApp
{
public:
	CChap3Exa2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChap3Exa2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CChap3Exa2App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAP3EXA2_H__488C5605_0266_49B4_A06F_992606252D56__INCLUDED_)

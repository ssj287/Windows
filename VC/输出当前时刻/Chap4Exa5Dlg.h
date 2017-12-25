// Chap4Exa5Dlg.h : header file
//

#if !defined(AFX_CHAP4EXA5DLG_H__FC51A1DA_1BE0_4C92_876F_C04CEA11802B__INCLUDED_)
#define AFX_CHAP4EXA5DLG_H__FC51A1DA_1BE0_4C92_876F_C04CEA11802B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChap4Exa5Dlg dialog

class CChap4Exa5Dlg : public CDialog
{
// Construction
public:
	CChap4Exa5Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChap4Exa5Dlg)
	enum { IDD = IDD_CHAP4EXA5_DIALOG };
	CString	m_CurTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChap4Exa5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChap4Exa5Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnExit();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAP4EXA5DLG_H__FC51A1DA_1BE0_4C92_876F_C04CEA11802B__INCLUDED_)

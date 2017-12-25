
// Chap9Exa8Dlg.h: 头文件
//

#pragma once
#include "afxwin.h"


// CChap9Exa8Dlg 对话框
class CChap9Exa8Dlg : public CDialog
{
// 构造
public:
	CChap9Exa8Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAP9EXA8_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CButton m_DateCheck;
//	CButton m_TimeCheck;
	CEdit m_DateEdit;
	CEdit m_TimeEdit;
//	bool m_SexRadio;
//	bool m_AgeRadio;
	CEdit m_ResultEdit;
//	int m_English;
	CEdit m_ComboEdit;
	CComboBox m_Record;
	afx_msg void OnBnClickedEnableButton();
	afx_msg void OnBnClickedDisableButton();
	afx_msg void OnBnClickedDateCheck();
	afx_msg void OnBnClickedTimeCheck();
	afx_msg void OnBnClickedShowButton();
	afx_msg void OnBnClickedHideButton();
	afx_msg void OnBnClickedShowSexAgeButton();
	afx_msg void OnBnClickedShowcomboButton();
//	bool m_DateCheck;
	BOOL m_DateCheck;
	BOOL m_TimeCheck;
	int m_English;
};

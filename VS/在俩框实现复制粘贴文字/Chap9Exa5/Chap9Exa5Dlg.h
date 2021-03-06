
// Chap9Exa5Dlg.h: 头文件
//

#pragma once
#include "afxwin.h"


// CChap9Exa5Dlg 对话框
class CChap9Exa5Dlg : public CDialog
{
// 构造
public:
	CChap9Exa5Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAP9EXA5_DIALOG };
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
	CEdit m_edit1;
	CEdit m_edit2;
	afx_msg void OnBnClickedBtnShow1();
	afx_msg void OnBnClickedBtnClear1();
	afx_msg void OnBnClickedBtnShow2();
	afx_msg void OnBnClickedClear2();
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBtnTransfer();
	afx_msg void OnBnClickedBtnUndo();
};

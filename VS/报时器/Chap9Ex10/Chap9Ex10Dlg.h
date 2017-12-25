
// Chap9Ex10Dlg.h: 头文件
//

#pragma once
#include "afxcmn.h"


// CChap9Ex10Dlg 对话框
class CChap9Ex10Dlg : public CDialog
{
// 构造
public:
	CChap9Ex10Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAP9EX10_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CImageList m_imageList;
	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
//	CListCtrl m_imageList;
};

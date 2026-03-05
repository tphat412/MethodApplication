
// MethodApplicationDlg.h : header file
//

#pragma once

#include "MethodController.h"

// CMethodApplicationDlg dialog
class CMethodApplicationDlg : public CDialogEx, public SubscriberIf
{
// Construction
public:
	CMethodApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_METHODAPPLICATION_DIALOG };
#endif

	void Update() override;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButtonGround();
	afx_msg void OnBnClickedButtonThermal();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

private:
	MethodController m_controller;
};

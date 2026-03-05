#pragma once

#include "afxdialogex.h"
#include <memory>
#include "MethodController.h"
#include "MethodType.h"

// MethodSelectionDlg dialog

class MethodSelectionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MethodSelectionDlg)

public:
	MethodSelectionDlg(MethodController* controller, MethodType type, CWnd* pParent = nullptr);
	virtual ~MethodSelectionDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECTION_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	virtual BOOL OnInitDialog();

	afx_msg void OnOK();

	DECLARE_MESSAGE_MAP()

private:
	MethodController* m_controller;
	MethodType m_methodType;
	CComboBox m_combo;
};

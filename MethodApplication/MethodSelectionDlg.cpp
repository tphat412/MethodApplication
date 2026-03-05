// MethodSelectionDlg.cpp : implementation file
//

#include "pch.h"
#include "MethodApplication.h"
#include "afxdialogex.h"
#include "MethodSelectionDlg.h"
#include "MethodType.h"


// MethodSelectionDlg dialog

IMPLEMENT_DYNAMIC(MethodSelectionDlg, CDialogEx)

MethodSelectionDlg::MethodSelectionDlg(MethodController* controller, MethodType type, CWnd* pParent)
    : CDialogEx(IDD_SELECTION_DIALOG, pParent), m_controller(controller), m_methodType(type)
{
}


MethodSelectionDlg::~MethodSelectionDlg()
{
}

void MethodSelectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_METHOD, m_combo);
}

BOOL MethodSelectionDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    // Set dialog title
    CString title;
    title.LoadString(MethodTypeToTitleStringID(m_methodType));
    SetWindowText(title);

    // Set label text
    CString labelText;
    labelText.LoadString(MethodTypeToSelectionLabelStringID(m_methodType));
    SetDlgItemText(IDC_STATIC_METHOD, labelText);

    auto options = m_controller->GetOptions(m_methodType);
    std::string selected = m_controller->GetSelected(m_methodType);

    int selectedIndex = 0;
    int index = 0;
    for (const auto& opt : options)
    {
        m_combo.AddString(CA2W(opt.c_str()));
        if (opt == selected)
            selectedIndex = index;
        index++;
    }

    m_combo.SetCurSel(selectedIndex);

    return TRUE;
}

void MethodSelectionDlg::OnOK()
{
    CString text;
     
    m_combo.GetWindowText(text);

    m_controller->SelectMethod(m_methodType, std::string(CT2A(text)));

    CDialogEx::OnOK();
}

BEGIN_MESSAGE_MAP(MethodSelectionDlg, CDialogEx)
END_MESSAGE_MAP()


// MethodSelectionDlg message handlers


// MethodApplicationDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MethodApplication.h"
#include "MethodApplicationDlg.h"
#include "afxdialogex.h"
#include "MethodSelectionDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMethodApplicationDlg dialog



CMethodApplicationDlg::CMethodApplicationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_METHODAPPLICATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMethodApplicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMethodApplicationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMethodApplicationDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_GROUND, &CMethodApplicationDlg::OnBnClickedButtonGround)
	ON_BN_CLICKED(IDC_BUTTON_THERMAL, &CMethodApplicationDlg::OnBnClickedButtonThermal)
END_MESSAGE_MAP()


// CMethodApplicationDlg message handlers

BOOL CMethodApplicationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_controller.CreateModel(MethodType::GroundWater);
	m_controller.CreateModel(MethodType::Thermal);
	m_controller.AddSubscriber(MethodType::GroundWater, this);
	m_controller.AddSubscriber(MethodType::Thermal, this);
	Update();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMethodApplicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMethodApplicationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMethodApplicationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMethodApplicationDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CMethodApplicationDlg::Update()
{
	auto groundMethod = m_controller.GetSelected(MethodType::GroundWater);
	auto thermalMethod = m_controller.GetSelected(MethodType::Thermal);
	SetDlgItemText(IDC_STATIC_GROUND, CString(groundMethod.c_str()));
	SetDlgItemText(IDC_STATIC_THERMAL, CString(thermalMethod.c_str()));
}

void CMethodApplicationDlg::OnBnClickedButtonGround()
{
	MethodSelectionDlg dlg(&m_controller, MethodType::GroundWater);
	dlg.DoModal();
}

void CMethodApplicationDlg::OnBnClickedButtonThermal()
{
	MethodSelectionDlg dlg(&m_controller, MethodType::Thermal);
	dlg.DoModal();
}

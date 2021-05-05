
// Tester_Hardware_MCPowerSensorDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Tester_Hardware_MCPowerSensor.h"
#include "Tester_Hardware_MCPowerSensorDlg.h"
#include "afxdialogex.h"

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


// CTesterHardwareMCPowerSensorDlg dialog



CTesterHardwareMCPowerSensorDlg::CTesterHardwareMCPowerSensorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TESTER_HARDWARE_MCPOWERSENSOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTesterHardwareMCPowerSensorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_POWER, m_Text_Power);
	DDX_Control(pDX, IDC_EDIT_TEMP, m_Text_Temp);
	DDX_Control(pDX, IDC_EDIT_OFFSET, m_Text_Offset);
	DDX_Control(pDX, IDC_EDIT_FREQ, m_Text_Freq);
}

BEGIN_MESSAGE_MAP(CTesterHardwareMCPowerSensorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, &CTesterHardwareMCPowerSensorDlg::OnBnClickedButtonUpdate)
END_MESSAGE_MAP()


// CTesterHardwareMCPowerSensorDlg message handlers

BOOL CTesterHardwareMCPowerSensorDlg::OnInitDialog()
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTesterHardwareMCPowerSensorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTesterHardwareMCPowerSensorDlg::OnPaint()
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
HCURSOR CTesterHardwareMCPowerSensorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTesterHardwareMCPowerSensorDlg::OnBnClickedButtonUpdate()
{
	m_MCUsbPwrSen6GHS.ReadSensor();

	CString strTemp;

	strTemp.Format(_T("%.2f"), m_MCUsbPwrSen6GHS.m_Power);
	m_Text_Power.SetWindowTextW(LPCTSTR(strTemp));

	strTemp.Format(_T("%.2f"), m_MCUsbPwrSen6GHS.m_Temp);
	m_Text_Temp.SetWindowTextW(LPCTSTR(strTemp));

	strTemp.Format(_T("%.2f"), m_MCUsbPwrSen6GHS.m_Offset);
	m_Text_Offset.SetWindowTextW(LPCTSTR(strTemp));

	strTemp.Format(_T("%.2f"), m_MCUsbPwrSen6GHS.m_Freq);
	m_Text_Freq.SetWindowTextW(LPCTSTR(strTemp));

}


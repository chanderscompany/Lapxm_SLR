
// Tester_Hardware_PulseBlasterDlg.h : header file
//

#pragma once
#include "..\Public\Classes\PulseBlaster\PulseBlaster.h"

// CTesterHardwarePulseBlasterDlg dialog
class CTesterHardwarePulseBlasterDlg : public CDialogEx
{
// Construction
public:
	CTesterHardwarePulseBlasterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTER_HARDWARE_PULSEBLASTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	PulseBlaster PB;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStart();
};

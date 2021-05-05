
// Tester_Hardware_MCPowerSensorDlg.h : header file
//

#pragma once

#include "../Public/Classes/MCUsbPwrSen6GHS/MCUsbPwrSen6GHS.h"

// CTesterHardwareMCPowerSensorDlg dialog
class CTesterHardwareMCPowerSensorDlg : public CDialogEx
{
// Construction
public:
	CTesterHardwareMCPowerSensorDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTER_HARDWARE_MCPOWERSENSOR_DIALOG };
#endif

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

	MCUsbPwrSen6GHS m_MCUsbPwrSen6GHS;
	


public:
	afx_msg void OnBnClickedButtonUpdate();
	CEdit m_Text_Power;
	CEdit m_Text_Temp;
	CEdit m_Text_Offset;
	CEdit m_Text_Freq;
};

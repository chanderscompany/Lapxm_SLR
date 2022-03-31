
// Tester_Hardware_DDS_AD9959Dlg.h : header file
//

#pragma once


// CTesterHardwareDDSAD9959Dlg dialog
class CTesterHardwareDDSAD9959Dlg : public CDialogEx
{
// Construction
public:
	CTesterHardwareDDSAD9959Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTER_HARDWARE_DDS_AD9959_DIALOG };
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
};

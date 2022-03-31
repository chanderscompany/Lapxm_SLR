
// Tester_Hardware_DDS_AD9959.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTesterHardwareDDSAD9959App:
// See Tester_Hardware_DDS_AD9959.cpp for the implementation of this class
//

class CTesterHardwareDDSAD9959App : public CWinApp
{
public:
	CTesterHardwareDDSAD9959App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTesterHardwareDDSAD9959App theApp;

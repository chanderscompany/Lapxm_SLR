
// Tester_Hardware_MCPowerSensor.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTesterHardwareMCPowerSensorApp:
// See Tester_Hardware_MCPowerSensor.cpp for the implementation of this class
//

class CTesterHardwareMCPowerSensorApp : public CWinApp
{
public:
	CTesterHardwareMCPowerSensorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTesterHardwareMCPowerSensorApp theApp;

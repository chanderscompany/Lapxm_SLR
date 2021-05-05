#include "pch.h"
#include "MCUsbPwrSen6GHS.h"

MCUsbPwrSen6GHS::MCUsbPwrSen6GHS() {
	m_Power = -999.9;
	m_Temp = -999.9;
	m_Offset = -999.9;
	m_Freq = -999.9;
}

int MCUsbPwrSen6GHS::ReadSensor() {

	return 0;
}

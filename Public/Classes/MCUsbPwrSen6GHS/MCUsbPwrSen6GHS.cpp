#include "pch.h"
#include "MCUsbPwrSen6GHS.h"

//#include "D:\GIT\Lapxm_SLR\Tester_Hardware_MCPowerSensor\mcl_pm.dll"

MCUsbPwrSen6GHS::MCUsbPwrSen6GHS() {
	m_PowerdBm = -999.9;
	m_TemperatureC = -999.9;
	m_OffsetdBm = -999;
	m_FrequencyMHz = -999;

//	mcl_pm64::usb_pm^ MyPTE1 = gcnew mcl_pm64::usb_pm(); // Referencing 

	
}

void MCUsbPwrSen6GHS::SetFrequencyMHz(int freq) {
	m_FrequencyMHz = freq;
}

void MCUsbPwrSen6GHS::SetOffsetdBm(double offset) {
	m_OffsetdBm = offset;
}

double MCUsbPwrSen6GHS::GetPowerdBm() {
	return m_PowerdBm + m_OffsetdBm;
}

double MCUsbPwrSen6GHS::GetTempC() {
	return m_TemperatureC;
}

int MCUsbPwrSen6GHS::GetFreqMHz() {
	return m_FrequencyMHz;
}

double MCUsbPwrSen6GHS::GetOffsetdB() {
	return m_OffsetdBm;
}


int MCUsbPwrSen6GHS::ReadSensor() {

	m_PowerdBm = -999.9;
	m_TemperatureC = -999.9;
	short Status = 0;

	/*
	MyPTE1->Open_Sensor();
	if (MyPTE1->GetStatus() == 0)
	{
		return -1;
	}

	m_Power = MyPTE1->ReadPower();
	if (MyPTE1->GetStatus() == 0)
	{
		return -1;
	}

	m_Temp = MyPTE1->GetDeviceTemperature("C");
	if (MyPTE1->GetStatus() == 0)
	{
		return -1;
	}

	MyPTE1->Close_Sensor();

*/

	return 0;
}

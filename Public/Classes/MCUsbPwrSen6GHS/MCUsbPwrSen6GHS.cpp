#include "MCUsbPwrSen6GHS.h"

#import  "C:\Windows\SysWOW64\mcl_pm.dll"
using namespace mcl_pm;
_USB_PM* pm1;

MCUsbPwrSen6GHS::MCUsbPwrSen6GHS() {
	m_PowerdBm = -999.9;
	m_TemperatureC = -999.9;
	m_OffsetdBm = -999;
	m_FrequencyMHz = -999;

	HRESULT hresult;
	CLSID clsid;

	CoInitialize(NULL);
	hresult = CLSIDFromProgID(OLESTR("mcl_pm.USB_PM"), &clsid);
	hresult = CoCreateInstance(clsid, NULL, CLSCTX_INPROC_SERVER, __uuidof(_USB_PM), (LPVOID*)&pm1);
	if (FAILED(hresult))
	{
		pm1 = NULL;
	}

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

	if (pm1 == NULL)
	{
		return -1;
	}

	m_PowerdBm = -999.9;
	m_TemperatureC = -999.9;
	short Status = 0;

	pm1->Open_Sensor((_bstr_t)"");
	if (pm1->GetStatus() == 0)
	{
		return -1;
	}

	m_PowerdBm = pm1->ReadPower();
	if (pm1->GetStatus() == 0)
	{
		return -1;
	}

	m_TemperatureC = pm1->GetDeviceTemperature("C");
	if (pm1->GetStatus() == 0)
	{
		return -1;
	}

	pm1->Close_Sensor();

	return 0;
}

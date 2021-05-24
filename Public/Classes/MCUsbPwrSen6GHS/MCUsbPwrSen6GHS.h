#pragma once

#include <afxwin.h> 

class MCUsbPwrSen6GHS
{
	public:
		MCUsbPwrSen6GHS();

	public:
		int ReadSensor();

		void SetFrequencyMHz(int freq);
		void SetOffsetdBm(double offset);
		double MCUsbPwrSen6GHS::GetPowerdBm();
		double MCUsbPwrSen6GHS::GetTempC();
		int MCUsbPwrSen6GHS::GetFreqMHz();
		double MCUsbPwrSen6GHS::GetOffsetdB();

	private:
		double m_PowerdBm;
		double m_TemperatureC;
		int m_FrequencyMHz;
		double m_OffsetdBm;

};


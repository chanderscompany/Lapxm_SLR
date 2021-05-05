#pragma once
class MCUsbPwrSen6GHS
{
	public:
		MCUsbPwrSen6GHS();

	public:
		int ReadSensor();

		double m_Power;
		double m_Temp;
		double m_Offset;
		double m_Freq;
};


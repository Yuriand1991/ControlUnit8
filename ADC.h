/*
 * ADC.h
 *
 * Created: 31.01.2020 15:07:53
 *  Author: pzayv
 */ 


#ifndef ADC_H_
#define ADC_H_
class AnalogDigitConverter{
	private:
		float Volts;
	public:
		AnalogDigitConverter();
		float GetVoltage();
 };





#endif /* ADC_H_ */
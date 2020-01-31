/*
 * ADC.cpp
 *
 * Created: 31.01.2020 14:45:33
 *  Author: pzayv
 */ 
#include <avr/io.h>
#include "ADC.h"

AnalogDigitConverter::AnalogDigitConverter(){
 		ADCSRA |= (1<<ADEN) // ���������� ������������� ���
 		|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//�������� 128 = 86,400 kHz

 		ADMUX = (1<<REFS0) | (1<<REFS1);// | (0<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3);
}

float AnalogDigitConverter::GetVoltage(){
	ADCSRA |= (1<<ADSC); //�������� ��������������
	while((ADCSRA & (1<<ADSC))); //�������� ����������� �� �������-�������� ��������������
	Volts = (float)ADC / 400;
	return Volts;
}
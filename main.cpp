/*
 * ControlUnit8.cpp
 *
 * Created: 31.01.2020 8:02:22
 * Author : pzayv
 */ 
#include "ControlUnit8.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Serial.h"
#include "Comunication.h"
#include "ADC.h"


int main(void)
{
    /* Replace with your application code */
	char c;
	SerialPort SerialPort0(2400);
	SerialPort0.Init(F_CPU);
	ComunicationProtocol IOProtocol;
	AnalogDigitConverter VoltMeter;
    while (1) 
    {
		IOProtocol.Insert(VoltMeter.GetVoltage(), 0);
		c = SerialPort0.receiveUART();
		if(c == '3')
			IOProtocol.SendFrame(SerialPort0);
		_delay_ms(500);
    }
}


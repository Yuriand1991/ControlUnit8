/*
 * Serial.cpp
 *
 * Created: 31.01.2020 8:03:49
 *  Author: pzayv
 */
 #include <stdio.h>
 #include <avr/io.h>
 #include <string.h>
 #include "Serial.h"
 
 void SerialPort::Init(unsigned long FreqMCU){
	unsigned long UBRR = FreqMCU/(16*(unsigned long)BaudRate - 1);
	UBRRL = UBRR;
	UBRRH = UBRR>>8;
	UCSRB = (1<<TXEN) | (1<<RXEN);
	UCSRC = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1) | (1<<USBS);//8 bits data
 }
 
 void SerialPort::Write(char c){
	 while(!(UCSRA & (1<<UDRE)));
	 UDR = c;
 }


 void SerialPort::Write(unsigned char c){
	while(!(UCSRA & (1<<UDRE)));
	UDR = c;
 } 

 void SerialPort::Write(char *p){
	while (*p) {
		Write(*p++);//последовательно передаем байты строки
	}
 }

 void SerialPort::Write(int i){
	char Buffer[80];
	memset(Buffer, 0, sizeof(Buffer));
	sprintf(Buffer,"%i  \r\n", i);
	Write(Buffer);
  }

 void SerialPort::Write(float f){
	 char Buffer[80];
	 memset(Buffer, 0, sizeof(Buffer));
	 sprintf(Buffer,"%f  \r\n", f);
	 Write(Buffer);
 }

void SerialPort::Write(unsigned char *buf, int size){
	int i;
	for(i=0; i<size; i++)
		Write(buf[i]);
}

/************************************************************************/
/* Прием байта по UART													 */
/************************************************************************/
unsigned char SerialPort::receiveUART(){
	if ((UCSRA & (1<<RXC))){
		  return UDR;
	  }  return 0;
  }

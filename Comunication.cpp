/*
 * ComunicationProtocol.cpp
 *
 * Created: 31.01.2020 9:38:36
 *  Author: pzayv
 */
 
 #include "Serial.h"
 #include "Comunication.h"

 
 void ComunicationProtocol::SendFrame(SerialPort Port){
	Port.Write(SendBuffer, 4);
 }
 
 void ComunicationProtocol::Add(int i){
	//Объединение для преобразования байт в целое
	union IntegerToBytes{
		unsigned char bts[4];
		unsigned long uint;
	}IntToBytes;
	IntToBytes.uint = i;
	SendBuffer[index++] = IntToBytes.bts[3];
	SendBuffer[index++] = IntToBytes.bts[2];
	SendBuffer[index++] = IntToBytes.bts[1];
	SendBuffer[index++] = IntToBytes.bts[0];
 }

 void ComunicationProtocol::Add(float f){
	  //Объединение для преобразования байт в целое
	  union FltToBytes{
		  unsigned char bts[4];
		  float flt;
	  }FloatToBytes;

	  FloatToBytes.flt = f;
	  SendBuffer[index++] = FloatToBytes.bts[3];
	  SendBuffer[index++] = FloatToBytes.bts[2];
	  SendBuffer[index++] = FloatToBytes.bts[1];
	  SendBuffer[index++] = FloatToBytes.bts[0];
 }

 void ComunicationProtocol::Insert(int value, int index){
	//Объединение для преобразования байт в целое
	union IntegerToBytes{
		unsigned char bts[4];
		unsigned long uint;
	}IntToBytes;
	IntToBytes.uint = value;
	SendBuffer[index++] = IntToBytes.bts[3];
	SendBuffer[index++] = IntToBytes.bts[2];
	SendBuffer[index++] = IntToBytes.bts[1];
	SendBuffer[index++] = IntToBytes.bts[0];
 }

 void ComunicationProtocol::Insert(float value, int index){
	  //Объединение для преобразования байт в целое
	  union FltToBytes{
		  unsigned char bts[4];
		  float flt;
	  }FloatToBytes;

	  FloatToBytes.flt = value;
	  SendBuffer[index++] = FloatToBytes.bts[3];
	  SendBuffer[index++] = FloatToBytes.bts[2];
	  SendBuffer[index++] = FloatToBytes.bts[1];
	  SendBuffer[index++] = FloatToBytes.bts[0];
 }
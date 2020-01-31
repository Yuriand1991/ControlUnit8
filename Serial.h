/*
 * Serial.h
 *
 * Created: 31.01.2020 8:04:07
 *  Author: pzayv
 */ 

#ifndef SERIAL_H_
#define SERIAL_H_

class SerialPort{
	private:
		unsigned int BaudRate;
	public:
		SerialPort(unsigned long BaudRate){
			this->BaudRate = BaudRate;
		}
		void Init(unsigned long FreqMCU);
		void Write(unsigned char c);
		void Write(char c);
		void Write(char *p);
		void Write(int i);
		void Write(float f);
		void Write(unsigned char *buf, int size);
		unsigned char receiveUART();
};



#endif /* SERIAL_H_ */
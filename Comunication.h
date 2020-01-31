/*
 * ComunicationProtocol.h
 *
 * Created: 31.01.2020 9:38:21
 *  Author: pzayv
 */ 


#ifndef COMUNICATIONPROTOCOL_H_
#define COMUNICATIONPROTOCOL_H_

class ComunicationProtocol{
	private:
		unsigned char SendBuffer[4];
		int index;
	public:
		ComunicationProtocol(){
			index = 0;
		}
		void SendFrame(SerialPort Port);
		void Add(int i);
		void Add(float f);
		void Insert(int value, int index);
		void Insert(float value, int index);
};





#endif /* COMUNICATIONPROTOCOL_H_ */
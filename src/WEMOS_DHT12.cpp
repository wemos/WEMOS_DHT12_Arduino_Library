#include "WEMOS_DHT12.h"

/* 

*/
DHT12::DHT12(uint8_t address)
{
	Wire.begin();
	_address=address;
}



byte DHT12::get()
{
	unsigned int data[5];

	Wire.beginTransmission(_address);

	Wire.write(0);

	if (Wire.endTransmission()!=0) 
		return 1;  
	
	Wire.requestFrom(_address, 5);
	
	for (int i=0;i<5;i++) {
		data[i]=Wire.read();
	};
	
	delay(50);
	
	if (Wire.available()!=0) 
		return 2;
	
	if (data[4]!=(data[0]+data[1]+data[2]+data[3])) 
		return 3;
	
	else
	{
		// Convert the data
		cTemp = (data[2]+(float)data[3]/10);
		fTemp = (cTemp * 1.8) + 32;
		humidity = (data[0]+(float)data[1]/10);
		return 0;
	}

	
}

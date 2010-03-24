#include "dwengoSensors.h"
#include "adc.h"

void initializeSensors(void)
{
	//ANCON0bits.PCFG0=0;
	OpenADC(ADC_FOSC_64 & ADC_RIGHT_JUST & ADC_6_TAD, ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0b1010);
}

int readSensor(BYTE sensor)
{
	int data;
	switch(sensor)
	{
		case 0:
			SetChanADC(ADC_CH0);
		case 1:
			SetChanADC(ADC_CH1);
	}

	//delay_us(125);
	ConvertADC();
	
	while (BusyADC());
		data=ReadADC();
	
	return data;
}
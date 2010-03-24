#include "dwengoRS232.h"
#include <usart.h>
#include <capture.h>
#include <timers.h>

void initializeRS232(void)
{
	//Configure Timer3
	//OpenTimer3(TIMER_INT_OFF & T3_SOURCE_INT);

	//Configure USART
	OpenUSART(USART_TX_INT_OFF & 
			  USART_RX_INT_OFF & 
			  USART_ASYNCH_MODE & 
			  USART_BRGH_LOW &
			  USART_EIGHT_BIT & 
			  USART_CONT_RX, 
			  77);
}

void sendData(void)
{
	//void putrs1USART ( const MEM_MODEL rom char *data);
	putrsUSART((const rom char *)"HELLO WORLD OMG");
}

void closeRS232(void)
{
	CloseUSART();
}
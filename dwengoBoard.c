#include "dwengoBoard.h"

void initBoard(void) {

	// if lcd display is connected (default)
#ifndef NO_LCD
	// init the lcd display
	initLCD();
	clearLCD();
#endif
	
	// set buttons as inputs
	SW_C_DIR = INPUT;
	SW_N_DIR = INPUT;
	SW_S_DIR = INPUT;
	SW_W_DIR = INPUT;
	SW_E_DIR = INPUT;

	// enable pull-up resistors of port B (buttons)
	INTCON2bits.NOT_RBPU = 0;  
	
	// set led pins as output
	LEDS_DIR = 0;  // led pins as outputs
	LEDS = 0;   // switch leds off	
}

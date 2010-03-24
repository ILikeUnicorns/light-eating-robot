#include <p18f4550.h>
#include <delays.h>
#include <string.h>
#include <portb.h>
#include "dwengoConfig.h"
#include "dwengoBoard.h"
#include "dwengoLCD.h"
#include "dwengoMotor.h"
#include "dwengoDelay.h"
#include "dwengoSensors.h"

void YourHighPriorityISRCode();
void YourLowPriorityISRCode();
 
// interrupt handler routines DO NOT EDIT
#pragma code high_vector=0x08
void high_vector() {
	_asm
		goto YourHighPriorityISRCode
	_endasm
}
#pragma code

#pragma code low_vector=0x18
void low_vector() {
	_asm
		goto YourLowPriorityISRCode
	_endasm
}
#pragma code

// interrupt handler routines
#pragma interrupt YourHighPriorityISRCode
void YourHighPriorityISRCode() 
{
	//Interrupt to send Q table
	printStringToLCD("HIGHPRI", 1, 0);
	leftMotor(0);
	rightMotor(0);
}
 
#pragma interrupt YourLowPriorityISRCode
void YourLowPriorityISRCode() 
{
	//Interrupt to stop motors
	printStringToLCD("LOWPRI", 1, 0);
	leftMotor(0);
	rightMotor(0);		
}

//Program values
int prevSensors[2];
int curSensors[2];
int diffSens0;
int diffSens1;
int thresshold=30;
char mode=0;

char datasend = "tetn";

//Main
void main(void) {
	initBoard();
	backlightOn();

	//Configure interrupts
	//Interrupt on RB1 = SW_E
	OpenRB1INT(PORTB_CHANGE_INT_ON & FALLING_EDGE_INT & PORTB_PULLUPS_OFF & PORTB_INT_PRIO_HIGH);

	//Interrupt on RB0 = SW_W
	OpenRB0INT(PORTB_CHANGE_INT_ON & FALLING_EDGE_INT & PORTB_PULLUPS_OFF & PORTB_INT_PRIO_LOW);

	//Enable button input => not needed, see dwengoBoard.c->initBoard();
	TRISB = 0xFF;

	//Init motors
	initializeMotors();
	initializeSensors();
	
	while (TRUE) 
	{
		if(SW_N == 0)
		{
			mode = 0;
			clearLCD();
			printStringToLCD("Doing moves brah", 1, 0);
			leftMotor(700);
			rightMotor(700);
			delay_s(4);
			leftMotor(1000);
			rightMotor(700);
			delay_s(4);
			leftMotor(700);
			rightMotor(1000);
			delay_s(4);
			leftMotor(-700);
			rightMotor(700);
			delay_s(4);
		}
		else if(mode == 1)
		{
			//Light eating
			
		}
		else if(SW_S == 0)
		{
			//Start light eating
			//mode = 1;
			clearLCD();
			printStringToLCD("Going to send string", 0, 0);
			initializeRS232();
			sendData();
		}
		else
		{
			//printStringToLCD("Cool story bro", 0, 0);
		}
	}
}
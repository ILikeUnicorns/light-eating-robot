#include "dwengoMotor.h"
#include "pwm.h"
#include "timers.h"

void initializeMotors(void)
{
	//Define RC1, RC2, RB3, RA4 as output
	//RC1 == CCP1; RC2 == CCP2; generates PWM signals
	TRISAbits.TRISA4 = 0;
	TRISBbits.TRISB3 = 0;
	TRISCbits.TRISC1 = 0;
	TRISCbits.TRISC2 = 0;

	//Timer enable
	T2CON = 0b00000001;
	//Timer enable
	T2CONbits.TMR2ON = 1;
	T2CONbits.T2OUTPS0 = 0;
	T2CONbits.T2OUTPS1 = 0;
	T2CONbits.T2OUTPS2 = 0;
	T2CONbits.T2OUTPS3 = 0;
	
	//PWM Period = [(PR2)+1]*4*Tosc (48Mhz)*(TMR2 Prescale value)
	OpenPWM1(0xFF);
	//PWM Period = [(PR2)+1]*4*Tosc (48Mhz)*(TMR2 Prescale value)
	OpenPWM2(0xFF);

	//Stop motors
	SetDCPWM1(0);
	SetDCPWM2(0);
}

void leftMotor(int speed)
{
	//Check if direction is changed; if so, delay to avoid overheating of the motor driver
	if(DIR != (speed > 0))
	{
		delay_ms(50);
	}
	
	if(speed < 0)
	{
		//Negative speed
		MOTOR1_1_DIR = 0;
		SetDCPWM1(-speed); //0 is max speed in reverse
	}
	else
	{
		//Postive speed
		MOTOR1_1_DIR = 1;
		SetDCPWM1(1023-speed);
	}
	DIR = (speed > 0);
	//T2_PS_1_4 & T2_POST_1_1 
	OpenTimer2(TIMER_INT_OFF & T2_PS_1_4 & T2_POST_1_1);
}

void rightMotor(int speed)
{
	//Check if direction is changed; if so, delay to avoid overheating of the motor driver
	if(DIR != (speed > 0))
	{
		delay_ms(50);
	}

	if(speed < 0)
	{
		//Negative speed
		MOTOR2_1_DIR = 1;
		SetDCPWM2(1023 + speed); 
	}
	else
	{
		//Positive speed
		MOTOR2_1_DIR = 0;
		SetDCPWM2(speed);
	}

	//T2_PS_1_4 & T2_POST_1_1 
	OpenTimer2(TIMER_INT_OFF & T2_PS_1_4 & T2_POST_1_1);
}
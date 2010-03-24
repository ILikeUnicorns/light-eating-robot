/*
 *  dwengoBoard.h
 *  
 *
 *
 */

#ifndef DWENGO_BOARD_H
#define DWENGO_BOARD_H

// Constants
#define TRUE    1
#define FALSE   0
#define HIGH    1
#define LOW     0
#define PRESSED 0
#define INPUT   1
#define OUTPUT  0

// Data types
#define BYTE unsigned char

// Pin assignments

// leds
#define LEDS                PORTD
#define LEDS_DIR            TRISD
#define LED0                PORTDbits.RD0
#define LED1                PORTDbits.RD1
#define LED2                PORTDbits.RD2
#define LED3                PORTDbits.RD3
#define LED4                PORTDbits.RD4
#define LED5                PORTDbits.RD5
#define LED6                PORTDbits.RD6
#define LED7                PORTDbits.RD7

// buttons
#define SW_C                PORTBbits.RB2
#define SW_C_DIR            TRISBbits.TRISB2
#define SW_N                PORTBbits.RB4
#define SW_N_DIR            TRISBbits.TRISB4
#define SW_E                PORTBbits.RB1
#define SW_E_DIR            TRISBbits.TRISB1
#define SW_S                PORTBbits.RB5
#define SW_S_DIR            TRISBbits.TRISB5
#define SW_W                PORTBbits.RB0
#define SW_W_DIR            TRISBbits.TRISB0

// LCD display
#define LCD_DATA            PORTD 
#define LCD_DATA_DIR        TRISD
#define LCD_BACKLIGHT       PORTCbits.RC0
#define LCD_BACKLIGHT_DIR   TRISCbits.TRISC0
#define LCD_RW              PORTEbits.RE1
#define LCD_RW_DIR          TRISEbits.TRISE1
#define LCD_RS              PORTEbits.RE0
#define LCD_RS_DIR          TRISEbits.TRISE0
#define LCD_EN              PORTEbits.RE2
#define LCD_EN_DIR          TRISEbits.TRISE2

// servo connectors
#define SERVO1              PORTBbits.RB5
#define SERVO1_DIR          TRISBbits.TRISB5
#define SERVO2              PORTBbits.RB4
#define SERVO2_DIR          TRISBbits.TRISB4

// motor driver
#define MOTOR1_0            PORTCbits.RC2
#define MOTOR1_0_DIR        TRISCbits.TRISC2
#define MOTOR1_1            PORTAbits.RA4
#define MOTOR1_1_DIR        TRISAbits.TRISA4
#define MOTOR2_0            PORTCbits.RC1
#define MOTOR2_0_DIR        TRISCbits.TRISC1
#define MOTOR2_1            PORTBbits.RB3
#define MOTOR2_1_DIR        TRISBbits.TRISB3

// include libraries
#include <p18f4550.h>
#include "dwengoDelay.h"

#ifndef NO_LCD
#include "dwengoLCD.h"
#endif

// intialisation routine for the board
void initBoard(void);

#endif //DWENGO_BOARD_H
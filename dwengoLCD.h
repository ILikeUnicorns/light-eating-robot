/**
 * LCD Display
 * part of Dwengo library
 * 
 * Control of LCD display on the Dwengo board
 *
 * Version: 1.0.$Revision: 1567 $
 * Date: $Date: 2009-12-21 21:38:03 +0100 (ma, 21 dec 2009) $
 * (c) Dwengo vzw - http://www.dwengo.org
 */

#ifndef DWENGO_LCD_H
#define DWENGO_LCD_H

#include "dwengoBoard.h"
#include "dwengoDelay.h"

// Properties
#define LCD_WIDTH       16
#define LCD_HEIGHT      2
#define LCD_LASTLINE    (LCD_HEIGHT - 1)
#define LCD_LASTPOS     (LCD_WIDTH - 1)

// Macro's
#define backlightOn()    (LCD_BACKLIGHT = 1)
#define backlightOff()   (LCD_BACKLIGHT = 0)

#define appendStringToLCD(message)   appendStringToLCD_((const far rom char*)(message))

// Functions
void initLCD(void);
void clearLCD(void);

void commandLCD(const BYTE c);
void setCursorLCD(BYTE l, BYTE p);

void appendCharToLCD(const char c);
void printCharToLCD(const char c, BYTE l, BYTE p);

void appendStringToLCD_(const far rom char* s);
void printStringToLCD(char* s, BYTE l, BYTE p);

void appendIntToLCD(int i);
void printIntToLCD(int i, BYTE l, BYTE p);

// Structures
struct lcd_info_type {
  unsigned char line;
  unsigned char pos;
};

// Keeps track of current line number and character position.
extern struct lcd_info_type lcd_info;

#endif // DWENGO_LCD_H

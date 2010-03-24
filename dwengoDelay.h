/**
 * Delay
 * part of Dwengo library
 * 
 * Delay routines for the dwengo board.
 *
 * Version: 1.0.$Revision: 1618 $
 * Date: $Date: 2010-01-04 22:19:02 +0100 (ma, 04 jan 2010) $
 * (c) Dwengo vzw - http://www.dwengo.org
 */

#ifndef DWENGO_DELAY_H
#define DWENGO_DELAY_H

#define delay_us(n)       \
{	char a=n;  \
    _asm                  \
	MOVLW a               \
    MOVF PLUSW2, 1, 0     \
	BZ   12               \
	DECF PLUSW2, 1, 0     \
loop:                     \
	MOVLW a               \
    MOVF PLUSW2, 1, 0     \
	BZ   8                \
	NOP                   \
	NOP                   \
	NOP                   \
	NOP                   \
	NOP                   \
	NOP                   \
	DECF PLUSW2, 1, 0     \
	BRA  -11              \
end:                      \
	_endasm }

void delay_100us(int n);
void delay_ms(int n);
void delay_s(int n);

#endif // DWENGO_DELAY_H
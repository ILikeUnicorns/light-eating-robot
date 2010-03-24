/**
 * Delay
 * part of Dwengo library
 * 
 * Delay routines for the dwengo board.
 *
 * Version: 1.0.$Revision: 1556 $
 * Date: $Date: 2009-12-19 01:34:57 +0100 (za, 19 dec 2009) $
 * (c) Dwengo vzw - http://www.dwengo.org
 */

#include "dwengoDelay.h"

void delay_100us(int n) {
	int i;
	if (n != 0) {
		delay_us(95);
		for (i = 1; i<n; i++) {
			delay_us(98);
		}
	}
}

void delay_ms(int n){
	int i;
	if (n != 0) {
		delay_us(94)
		delay_100us(9);
		for (i = 1; i<n; i++) {
			delay_us(96)
			delay_100us(9);
		}
	}
}

void delay_s(int n){
    int i;
	for (i=0; i<n; i++) {
        delay_ms(1000);
    }
}
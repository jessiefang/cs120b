/*	Author: yfang038
 *  Partner(s) Name: none
 *	Lab Section:021
 *	Assignment: Lab #2  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00;  PORTA = 0xFF;
	DDRB = 0xFF;  PORTB = 0x00;
	DDRC = 0xFF;  PORTC = 0x00;

	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
    /* Insert your solution below */
    while (1) {
	unsigned char cntavail = 4;
	tmpA = PINA & 0x01;
	tmpB = PINA & 0x02;
	tmpC = PINA & 0x04;
	tmpD = PINA & 0x08;
	if (tmpA == 0x01) {
		cntavail--;
	} 
	if (tmpB == 0x02){
		cntavail--;
	}
	if (tmpC == 0x04) {
                cntavail--;
        }
	if (tmpD == 0x08) {
                cntavail--;
        }
	PORTC = cntavail;
    }
    return 0;
}

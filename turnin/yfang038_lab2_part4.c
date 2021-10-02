/*	Author: yfang038
 *  Partner(s) Name: none
 *	Lab Section:021
 *	Assignment: Lab #2  Exercise #4
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
	DDRB = 0x00;  PORTB = 0xFF;
	DDRC = 0x00;  PORTC = 0xFF;
	DDRD = 0xFF;  PORTD = 0x00;	

	unsigned char tmpB = 0x00;
	unsigned char tmpA = 0x00;
	unsigned char tmpC = 0x00;
	unsigned char tmpD = 0x00;
	unsigned char total = 0x00;


    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	tmpD = 0x00;
	if ((tmpA + tmpB + tmpC) >0x8C) {
		tmpD = tmpD | 0x01;
	} 
	if (((tmpA - tmpC) > 0x50) | ((tmpC - tmpA) > 0x50)){
		tmpD = tmpD | 0x02;
	}
	
	total = tmpA + tmpB + tmpC;
	tmpD = (total & 0xFC) | tmpD;
	PORTD = tmpD;

    }
    return 0;
}

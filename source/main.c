/*	Author: dpere048
 *  Partner(s) Name: 
 *	Lab Section: 021
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
	DDRA = 0x00; PORTA = 0xFF; //CONFIGURE PORT A 8PINS AS INPUTS
	DDRC = 0xFF; PORTC = 0x00; //CONFIGURE PORT c 8 pins as outputs, initialize to 0s
	unsigned char cntavail = 0x00; //temp var to hold spaces available
	unsigned char tmpA = 0x00; //tmp var to hold value of A
    /* Insert your solution below */
    while (1) {
	tmpA = PINA;
	if (tmpA == 0x00){
		cntavail =  0x04; //no cars parked = 4 available spaces
					//clears rightmost 2 bits, sets to 01
	}
	else if(tmpA == 0x01 || 0x02 || 0x04 || 0x08){//1 car parked
		cntavail = 0x03; //3 available spots
	}
	else if(tmpA == 0x0C || 0x0A || 0x09 || 0x06 || 0x05 || 0x03){//2parked
		cntavail = 0x02; //2 available spots
	}
 	else if(tmpA == 0x0E || 0x0D || 0x0C || 0x07){//3parked
		cntavail = 0x01; //1 available spot
	}
	else if(tmpA == 0x0F){//4parked
		cntavail = 0x00; //no available spots
	}
	else{
		cntavail = 0x00;
	}
	PORTC = cntavail;
    }
    return 1;
}



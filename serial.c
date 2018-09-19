/****************************************************************************
Write a code to establish a serial communication between two systems 
(Personal Computer and Freedom KL25Z) via UART ( Universal Asynchronous 
Receiver and Transmitter) protocol implemented with the help of a USB 
with Baud rate 9600, Stop bit 1, Parity None and Flow Control None to 
transmit a character from Host ( Personal Computer) to FRDM KL25Z and 
receive it back at the host and view the character at the terminal utility.
****************************************************************************/

#include "mbed.h"              

Serial pc(USBTX, USBRX);

int main() {
	pc.printf("Transmit a character from Host to FRDM KL25Z and receive it back at the host and view the character at the terminal utility.\n");
	while(1) {
		pc.putc(pc.getc());
	}
}

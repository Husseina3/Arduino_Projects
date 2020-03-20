#include <msp430.h>

/* 
*File: main.c For Simple blink on MSP430F5529
*Created On: 9/14/2018
*Last Edited: 9/15/2018
*Autor: Anwar Hussein
*/

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // This line of code deactivates the Watch Dog Timer. The WDT is an electronic timer that
                                            // that resets the system whenever it detects a computer malfunction. Since this project is
                                            // made to blink a single LED the WTD is not necessary.

  P4SEL &= ~BIT0;                           // BIT0 = 00000001. ~BIT0=11111110. Whenever a number is ANDed with ~BIT0, all bits of the number will remain
                                            // unchanged except the least significant bit. Therefore, port 1 selection will only alter the LSB.

  P4DIR |= BIT7 ;                         // This line of code sets the port 4.0 direction register to be 1. Which means that port is an output port.


  /*This block of code creates an infinite while loop. The ^= is an XOR operator which is used to toggle Port 4 pin 7(P4.7).*/
while(1)

  {
    P4OUT ^= BIT7;             // The bitwise XOR is used to toggle the Green LED. P4OUT is a register by which the value is assigned to the corresponding pin.
    _delay_cycles(200000);     // This line of code delays the toggle speed to be 0.5sec
  }
return 0;
}

#include <msp430.h>
/* 
*File: main.c For Simple blink on MSP430G2553
*Created On: 9/14/2018
*Last Edited: 9/15/2018
*Autor: Anwar Hussein
*/
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // This line of code deactivates the Watch Dog Timer. The WDT is an electronic timer that
                                            // that resets the system whenever it detects a computer malfunction. Since this project is
                                            // made to blink a single LED the WTD is not necessary.

  P1SEL &= ~BIT0;                           // BIT0 = 00000001. ~BIT0=11111110. Whenever a number is ANDed with ~BIT0, all bits of the number will remain
                                            // unchanged except the least significant bit. Therefore, port 1 selection will only alter the LSB.

  P1DIR |= BIT0 ;                         // This line of code sets the port 1.0 direction register to output 1


  /*This block of code creates an infinite while loop. The ^= is an XOR operator which is used to toggle Port 1 pin 0(P1.0).*/
while(1)

  {
    P1OUT ^= BIT0;             // The bitwise XOR is used to toggle the Green LED
    _delay_cycles(500000);     // This line of code delays the toggle speed to be 0.5sec
  }
return 0;
}

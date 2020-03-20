#include <msp430.h> 


/**
 * File: main.c for Off Board Blink MSP430G2553
 * Created On: 9/14/2018
 * Last Edited: 9/20/2018
 * Author: Anwar Hussein
 */
int main(void)
{
	

    WDTCTL = WDTPW + WDTHOLD;                 // This line of code deactivates the Watch Dog Timer. The WDT is an electronic timer that
                                              // that resets the system whenever it detects a computer malfunction. Since this project is
                                              // made to blink a single LED the WTD is not necessary.

    P1DIR |= BIT0;                             // The Direction Register for port 1 is set to 1 on Pin0. Since BIT1 = 00000001, when a number
                                               //is ORed with it only the least significant bit get altered.  As a result P1.0 is set to be an
                                               //OUTPUT pin.
    P1DIR |= (BIT6 | BIT2 | BIT1 | BIT4);      // The Direction Register for port 1 is set to 1 on Pin6, 2, 1, & 4. 


    /*This block of code creates an infinite while loop. The ^= is an XOR operator
     *which is used to toggle Port the 5 LEDs that are found on the bread board.
     */

    while(1)
    {
        P1OUT ^= (BIT0);   // Toggles P1.6

        _delay_cycles(90000); // The Delay Between the Toggle is 0.2

      P1OUT ^= BIT1;
        _delay_cycles(80000); // The Delay Between the Toggle is 0.3

        P1OUT ^= BIT2;
         _delay_cycles(0000); // The Delay Between the Toggle is 0.3

         P1OUT ^= BIT4;
          _delay_cycles(40000); // The Delay Between the Toggle is 0.3

          P1OUT ^= BIT6;
           _delay_cycles(300000); // The Delay Between the Toggle is 0.3


    }
    return 0;
}

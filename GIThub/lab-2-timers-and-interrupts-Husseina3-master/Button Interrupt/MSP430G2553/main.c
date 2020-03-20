/*File: main.c for MSP430G2553 Button Interrupt
 * Author: Anwar Hussein
 * Created on: 9/29/2018
 * Last Edited: 9/30/2018
 */
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Disable the WatchDog Timer

  P2SEL  = 0;                                //Set port 2 as an Input/Output port
  P2DIR |= (BIT3|BIT5|BIT1);                 //Set Pin 2.5 and 2.3 as output pins.
  P2OUT |= BIT3;


  P1OUT |= BIT3;                            // Set Pin 1.3 Pull up register

  P1IE  |=  BIT3;                            // P1.3 interrupt enabled
  P1IES |= BIT3;                            // set P1.3 as falling Edge
  P1REN |= BIT3;                            // P1.3 Pull up/down register Enabled
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared
                                            //BIT3 on Port 1 can be used as Switch2

  __bis_SR_register(LPM4_bits + GIE);       // Enter LOW POWER MODE (LPM4) with interrupt
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{


   P2OUT ^= BIT3;                            // P2.3, Green LED,  will toggle
   P1IFG &= ~BIT3;                        // P1.3 IFG cleared

   P2OUT ^= BIT5;                           // P2.5, Blue LED, Will toggle
   P1IFG &= ~BIT3;                          // P1.3 IFG cleared

}

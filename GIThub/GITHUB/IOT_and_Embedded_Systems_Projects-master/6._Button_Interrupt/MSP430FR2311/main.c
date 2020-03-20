/*File: main.c for MSP430FR2311 Button Interrupt
 * Author: Anwar Hussein
 * Created on: 9/29/2018
 * Last Edited: 9/30/2018
 */
#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Disable the WatchDog Timer


  P1DIR |= (BIT0|~BIT1);                             //Set Pin 1.0 as output pin
  P1OUT |= (BIT0|~BIT1);

  P1DIR |= BIT1;                             //Set Pin 1.0 as output pin

  P1IE  |= BIT1;                            // P1.1 interrupt enabled
  P1IES |= BIT1;                            // set P1.1 as falling Edge
  P1REN |= BIT1;                            // P1.1 Pull up/down register Enabled
  P1IFG &= ~BIT1;                           // P1.1 IFG cleared
                                            //BIT1 on Port 1 can be used as Switch2

  __bis_SR_register(LPM4_bits + GIE);       // Enter LOW POWER MODE (LPM4) with interrupt
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
   P2OUT ^= BIT0;                            // P1.0 will toggle
   P1IFG &= ~BIT1;                        // P1.1 IFG cleared
}

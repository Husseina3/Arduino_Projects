#include <msp430.h> 


/**
 * File main.c for Timer A Blink for MSP430G2553
 * Author: Anwar Hussein
 * Created: 9/30/2018
 * Last Edited: 10/01/2018
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Disables the WatchDog Timer


      P1DIR |= (BIT0|BIT6);            // This line of code sets Pin 1.0 to be an output
      P1OUT &= ~BIT0;                  // Initial state of the first LED is turned off
      P1OUT &= ~BIT6;                  // Initial state of the second LED is turned off

      TA0CCR0 = 10000;                 // Timer A Capture/Compare Register 0 Count up to.
      TA0CCTL0 = 0x10;                 // Enable Timer A0 interrupts, bit 4=1
      TA0CTL = TASSEL_1 + MC_1;        // Timer A0 with ACLK UP Mode

      TA1CCR0 = 50000;                 // Timer A1 Capture/Compare Register 0 Count up to.
      TA1CCTL0 = 0x10;                 // Enable Timer A1 interrupts, bit 4=1
      TA1CTL = TASSEL_1 + MC_1;        // Timer A1 with ACLK set to UP Mode

      _BIS_SR(LPM0_bits + GIE);        // Low Power Mode (LPM)
    }

    #pragma vector=TIMER1_A0_VECTOR // Interrupt service routine

      __interrupt void Timer1_A0 (void) {

       P1OUT ^= BIT0;                  // The LED connected to Pin 1.0 is toggled
    }

    #pragma vector=TIMER0_A0_VECTOR    // Interrupt service routine

      __interrupt void Timer0_A0 (void) {

       P1OUT ^= BIT6;                  // The LED connected to Pin 1.6 is toggled
    }

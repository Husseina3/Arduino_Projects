/*
 *File: main.c for MSP430F5529 Debouncing
 *Author: Anwar Hussein
 *Created on: 10/01/2018
 *Last Edited: 10/06/2018
 */

#include <msp430.h> 

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;           //Disable the WatchDog Timer

    P1DIR  |= BIT0;                    // Port1's Direction Register is set to one at Pin0 (Pin1.0 is output Pin)
    P1REN  |= BIT1;                   // Port1's resistor is enabled at PIN1.1
    P1OUT  = BIT1;                    // The enabled resistor is set to be a pullup resister

    P1IE |= BIT1;                     // Button connected to Pin1.1 enables the Interrupt
    P1IES |= ~BIT1;                     // Button press interrupts on a Rising edge
    P1IFG &= ~BIT1;                   // Clear interrupt flag

    TA0CCTL0 = 0x0010;                  // Enables Capture/compare register for interrupt of timer A0
    TA0CCR0 = 60000;                    // Timer A's Capture/Compare Register counts upto 0.6sec
    TA0CTL = TASSEL_2 + MC_0;           // configure and start timer

    __enable_interrupt();

    __bis_SR_register(LPM0 + GIE);      // This line of code sets the Low Energy Mode and The General Purpose Interrupt Enable

}

#pragma vector = PORT1_VECTOR           // ISR (Interrupt Service Routine)
__interrupt void Interrupt_1(void)
{
    P1OUT ^= BIT0;                      // The LED connected to pin1.0(RED) Toggles
    P1IE &= ~BIT1;                      // reset interrupt
    TA0CTL = TASSEL_2 + MC_1;           // configure and start timer
}


#pragma vector=TIMER0_A0_VECTOR         // ISR (Interrupt Service Routine)
__interrupt void Interrupt_2(void)
{
    TA0CTL = MC_0;                      // Timer A stops counting
    P1IE |= BIT1;                       // After the timer stops counting, this line of code fires the interrupts
    P1IFG &= ~BIT1;                     // Clear interrupt flag
}

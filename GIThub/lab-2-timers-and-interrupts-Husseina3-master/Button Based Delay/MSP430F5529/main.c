
/*
 * File: main.c For MSP430F5529 Button Based Delay
 * Author: Anwar Hussein
 * Created on: 09/28/2018
 * Last Edited: 10/01/2018
 */

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Disable the good old WatchDog Timer


       P1DIR |= BIT0; //This line of code sets Pin1.0 and Pin1.6 as out pins
       P4DIR |= BIT7; //This line of code sets Pin2.0 and Pin1.6 as out pins
       P1OUT |= BIT0; //Initialize the LEDs connected to Pin1.0 as 1(on)
       P4OUT |= BIT7; //Initialize the LEDs connected to Pin2.0 as 1(on)


       P1REN |= BIT1; //Port 1's Resister enable is set to one at Pin 1.1

       P1OUT |= BIT1; //The Resistor at Pin 1.1 is set as Pull Up.


       P1IE |= BIT1; //Interrupt enable at Pin 1.1
       P1IES |= BIT1; //This line of code sets the interrupt on Falling edge
       TA0CCTL0 = CCIE; //Enables interrupts


       TA0CCR0 =  103;  //The Capture/Compare register 0 frequency is set to 10HZ.


       TA0CTL = TASSEL_1 + MC_1 + ID_3;// ACLK selected, Up-Count Enabled, Divider = 8

    __enable_interrupt(); //Enables Interrupts


       while (1) //Infinite while loop
       {       }   }

    #pragma vector = TIMER0_A0_VECTOR //The interrupt is fired after the timer A counts up to CCR0


       __interrupt void Timer_A ()
       {
          P1OUT  ^= BIT0; //The LEDs connected to Pin1.0 toggles
          P4OUT ^= BIT7; // The LEDs connected to Pin4.7 toggles

       }

    #pragma vector=PORT1_VECTOR //Port 1 Interrupt that is triggered when Pin 1.3 (BUTTON) changes from high to low

    __interrupt void Port_1(void)

    {
       if (P1IES & BIT1) //IF the port1 IE is on falling edge and if BIT1, the following condition occurs


       {

           TA0CTL = TACLR; //Clears any former values that were stored in Timer A's register
           TA0CTL = TASSEL_1 + MC_2 + ID_3;  //Changes clock mode to Continuous mode
           P1IES &= ~BIT1; //The Interrupt enable is set to be fired on the rising edge

       }
       else
       {

           TA0CCR0 = TA0R; //Sets the value in CCR0 register to the value in Timer A's register
           TA0CTL = TASSEL_1 + MC_1 + ID_3;  //Reverts clock mode back to UP mode
           P1IES |= BIT1; //The Interrupt enable is set to be fired on the falling edge

       }


       P1IFG &= ~BIT1; //Clears the interrupt flag

    }


/*
 * File: main.c For MSP430G2553 Button Based Delay
 * Author: Anwar Hussein
 * Created on: 09/28/2018
 * Last Edited: 10/01/2018
 */

#include <msp430.h>

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // Disable the good old WatchDog Timer

       BCSCTL3 = LFXT1S_2; //Enables crystal

       P1DIR |= (BIT0|BIT6); //This line of code sets Pin1.0 and Pin1.6 as out pins
       P1OUT |= (BIT0|BIT6); //Initialize the LEDs connected to Pin1.0 and Pin 1.6 as 1(on).


       P1REN |= BIT3; //Port 1's Resister enable is set to one at Pin 1.3
       P1OUT |= BIT3; //The Resistor at Pin 1.3 is set as Pull Up.


       P1IE |= BIT3; //Interrupt enable at Pin 1.3
       P1IES |= BIT3; //This line of code sets the interrupt on Falling edge
       CCTL0 = CCIE; //Enables interrupts


       CCR0 =  103;  //The Capture/Compare register 0 frequency is set to 10HZ.


       TACTL = TASSEL_1 + MC_1 + ID_3;// ACLK selected, Up-Count Enabled, Divider = 8

    __enable_interrupt(); //Enables Interrupts


       while (1) //Infinite while loop
       {       }   }

    #pragma vector = TIMER0_A0_VECTOR //The interrupt is fired after the timer A counts up to CCR0


       __interrupt void Timer_A ()
       {
           P1OUT ^= (BIT0|BIT6); //The LEDs connected to Pin

       }

    #pragma vector=PORT1_VECTOR //Port 1 Interrupt that is triggered when Pin 1.3 (BUTTON) changes from high to low

    __interrupt void Port_1(void)

    {
       if (P1IES & BIT3) //IF the port1 IE is on falling edge and if BIT3, the following condition occurs


       {

           TACTL = TACLR; //Clears any former values that were stored in Timer A's register
           TACTL = TASSEL_1 + MC_2 + ID_3;  //Changes clock mode to Continuous mode
           P1IES &= ~BIT3; //The Interrupt enable is set to be fired on the rising edge

       }
       else
       {

           CCR0 = TA0R; //Sets the value in CCR0 register to the value in Timer A's register
           TACTL = TASSEL_1 + MC_1 + ID_3;  //Reverts clock mode back to UP mode
           P1IES |= BIT3; //The Interrupt enable is set to be fired on the falling edge

       }


       P1IFG &= ~BIT3; //Clears the interrupt flag

    }

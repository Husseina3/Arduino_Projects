
/*File: main for button blink LED on MSP430G2553
 * Created on: 9/14/2018
 * Last Edited: 9/16/2018
 * Author: Anwar Hussein
 */

 void main(void)
 {
  WDTCTL = WDTPW|WDTHOLD; // Set the watchDog Timer off, since we are performing
                          //a relatively simple task of blinking an LED.


  P1DIR |= BIT0;     // This line of code sets P1.0 as an output pin.
  P1REN |= BIT3;     // The Resistor Enable bit will be determined by the Button P1.3.
  P1OUT |= BIT3;     // This line of code sets the resistance to a pullup resistor

  while(1){

      _delay_cycles(200000);        // This line of code will set the toggle delay of the green light to 0.2seconds.
                                    //if the button is hold, it starts to blink.

  if((P1IN & BIT3 ) == 0x00){       // This line of code defines the condition at which the LED changes state.
  P1OUT ^= BIT0;

  while((P1IN & BIT3) == BIT3);
  }}}

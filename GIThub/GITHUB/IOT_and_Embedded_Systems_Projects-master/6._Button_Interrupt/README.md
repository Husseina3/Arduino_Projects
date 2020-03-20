# Button Interrupt
For this part of the lab the MSP430G22553 and MSP430FR2311 microprocessors were used. 
On the previous project a Polling method was used to detect a button press, where the 
processor constantly checks if a button is pressed or not every time. Since our objective is 
to run the microprosessor on Low Power Mode, we want the processor to go to sleep unless 
there is an event to be executed. 

# A little bit about Interrupts
Interrupts play a major role in making our computer systems fast, efficient and less power consuming. 
Instead of the processor checking for events, interrupts alarm and interrupt the processor from its idle state
or whatever state.

| Term |Description |
|----|--------------|
|PxIE |Interupt Enable|
|PxIES|Interupt Enable select sets a falling or rising edge interrupt|
|IFG| Interrupt flag is set after the processor has been interrupted|
|ISR| Interrupt Service Routine|
|LPM| Low Power Mode|

# Implementation 
## MSP430G2553
Pin1.0 was set to interrput the processor. This microcontroller has RGB LED and in the Interrupt service routine,
the Green and Blue colors were set to be toggled. 
## MSP430FR2311
In this Microprocessor Pin1.1 was the button that was dedicated for interrupting the processor. In the Interupt service routine,
the LED that was connected to Pin1.0 is set to be toggled.
### Errata 
In toggling the RGB LED on the MSP430G2553, I was not successful in independently toggling the Red LED.

# Simple Blink MSP430G2553 and MSP430f5529

In this project the Green LED on the two MSP430 launchpad families will be blincked on certaini time interval. In approching the implementaion of this this project the Watch Dog Timer (WDT) has been devactivated. The watch dog timer is an electronic timer that is capable of reseting the system when there is a computer malfunction. Since this project is to only blink an LED we're better off deactivating it. 

## MSP430G2553
In simple Blinkin the LEDs on the lunchpads, figuring out the exact pin assignment was the first step. In MSP430G2553, the green led is connected to P1.0.
### Special Function Registers

||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P1 **In**|||||||||
|P1 **OUT**||||||||0/1|
|P1 **DIR**||||||||1|

**figure** *Special Function Registers* 

In the approach to blinking the green LED on MSP430G2553, the Direction register was set to 1. Which sets the pin to be an output pin. The **P1OUT** register is **XOR**ed inorder to get the toggle effect. The togle interval was set to delay 0.5seconds and the blinking was implemented using infinite while loop. 

## MSP430F5529
In MSP430F5529, the green led is connected to P4.7.
### Special Function Registers

||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P4 **In**|||||||||
|P4 **OUT**||||||||0/1|
|P4 **DIR**|1||||||||

**figure** *Special Function Registers* 

In the approach to blinking the green LED on MSP430F5529, the Direction register was set to 1. Which sets the pin to be an output pin. The **P4OUT** register is **XOR**ed inorder to get the toggle effect. The togle interval was set to delay 0.2seconds and the blinking was implemented using infinite while loop.

## Resources Used
* TI wikipedia 
* TI Resource Explorer

## Code Editor
* The One and Only **Code Composer Studio** By TI Instrunments 

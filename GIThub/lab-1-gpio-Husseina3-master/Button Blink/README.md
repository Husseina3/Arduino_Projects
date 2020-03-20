# Button Blink
In this part of the lab a button that is on the two dev boards was used to blink and LED. What makes this part of the lab slightly different is that we use the Input port Special Funciton Register since one of the pins will be the pin that the button is attached to. In the Direction Registor the pin to which the button is attached gets a value of 0 to indicate that the pin is an input pin. 

In addtion, a registor enable (REN) SFRegister will be used inorder to control the pullup and the pulldown resistors. 
The special Function Registors are shown in the table below. 

## MSP430G2553
||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P1 **In**|||||1||||
|P1 **OUT**|||||1|||1/0|
|P1 **DIR**|||||0|||1|
|P1 **REN**|||||1|||0|

**Special Funciton registors for Button Blink.**

## MSP430F5529
||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P1 **In**|||||||1||
|P1 **OUT**|||||1|||1|
|P1 **DIR**|||||||0|1|
|P1 **REN**|||||||1|0|

# Multiple Blink MSP430G2553 and MSP430f5529

In this project the Green and the Red LEDs on MSP430G2553 and MSP430f5529 dev boards will be toggled with different delays. While  implementing this project the Watch Dog Timer (WDT) has also been devactivated. The watch dog timer is an electronic timer that is capable of reseting the system when there is a computer malfunction. Since this project is to only blink an LED we're better off deactivating it. 

# Implementation
## MSP430G2553
In multiple Blinking the Red and Green LEDs on the lunchpads an infinite while loop was used where the itteration through the code in the loop makes the green and red LEDs to blink in different speeds.  
### Special Function Registers

||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P1 **In**||||||||1/0|
|P1 **OUT**||||||||1|
|P1 **DIR**||||||||1|

**Table** green LED's SFR P1.0.

||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P1 **In**||1/0|||||||
|P1 **OUT**||1|||||||
|P1 **DIR**||1|||||||

**Table** *Special Function Registers for the RED LED P1.6* 

The above table shows the two different states of the green LED and RED LED in the infinite while loop. The Speed of the Red Light is 0.2 seconds and the speed of the green is 0.3 seconds.

## MSP430F5529

||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P1 **In**||||||||1/0|
|P1 **OUT**||||||||1|
|P1 **DIR**||||||||1|

**Table** green LED's SFR P1.0.

||7|6|5|4|3|2|1|0|
|---------|--|--|--|--|--|--|--|--|
|P4 **In**|1/0||||||||
|P4 **OUT**|1||||||||
|P4 **DIR**|1||||||||

**Table** *Special Function Registers for the RED LED P4.7* 

The above table shows the two different states of the green LED and RED LED in the infinite while loop. The Speed of the Red Light is 0.2 seconds and the speed of the green is 0.3 seconds.

# Resources Used
* TI wikipedia 
* TI Resource Explorer

# Code Editor
* The One and Only **Code Composer Studio** By TI Instrunments 

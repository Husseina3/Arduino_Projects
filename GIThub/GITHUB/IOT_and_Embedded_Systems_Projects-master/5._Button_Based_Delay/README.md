# Button Based Delay
In this lab we have taken things up a natch. When it start or on reset the LED that is connected to Pin 1.0 and Pin 1.6 Blinks at 10hz. This is done by setting the timer to interrupt one the capture and compare register count up to 0.1 seconds. SO the main goal of this part of the lab is to control the speed of the blinking LEDs by using the amount of time we press and hold the button. 

## Capture and Compare Registers

|Mode|Description|
|-----|----------|
|Capture Mode| Records the counter value when a certain input changes. used to measure time intervals, like the frequency of a wave form|
|Compare Mode| Performs an operation when the counter value reaches a certain vale. Used to generate periodic interrupts and generate PWM signals|

### Demo Video
https://www.youtube.com/watch?v=L8D_Fzg-Icg&feature=youtu.be

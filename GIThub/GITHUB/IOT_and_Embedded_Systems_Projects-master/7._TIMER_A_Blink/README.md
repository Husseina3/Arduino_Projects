# TIMER A Blink
In this lab we have taken a very effective and something that would save us from an unnecessary power consumption on our microcontroller. 
## Using Timer A to Blink LED on MSP430G2553 and MSP430F5529
Unlike the previous lab were our processor checks for a buttons input to be an interrupt, the Timer A was used to inturrput the processor. Since the the processor doesn't have to continously check for a buttons input, it can go to sleep and save power. That is what we call Low Power Mode(LPM). 
Timer A has a capture and compare register. In this lab we have set the timer to fire an interrupt once it has counter for 1 and 5 seconds for the 2 different LEDs. Setting the timer to count upto a certain number and come back to down is called **up mode** . The following are the different modes the timer can be in. 

|Mode | Description|
|-----|-------------|
|up/down| timer counts up to set max count and back to zero.|
|Continous| timer counts up to the full count of timer.|

### Demo Video

https://youtu.be/pceTxReICxQ


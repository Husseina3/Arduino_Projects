/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

  int TrigPin = 5;         // Trigger of the Sonic Sensor
  int EchoPin = 4;         // Echo of the Sonic Sensor
  int Distance_Sonic = 50;          // Distance measured by Sonic Sensor 
  int echotime = 0;        // The time the reflected sound wave is recieved by the reciever end of the 
                           // sonic sensor. This value is used in the distance equation.
  
void setup() {
  Serial.begin(9600);
  pinMode (TrigPin, OUTPUT);        // The TrigPin is set as an Output pin
  pinMode (EchoPin, INPUT);         // The EcoPin is  set as an Input Pin
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}
void loop() {
   // Calculate distance based on the duration 

    digitalWrite (TrigPin, LOW);                // Send 0 through to the sensor through the Trigpin 
    delay (5);                               // 2 second delay

  
    digitalWrite (TrigPin, HIGH);               // Send an output high signal for 10 microseconds;
    delayMicroseconds(10);
    
    digitalWrite (TrigPin, LOW);                // Set the trigpin to 0 after being high for 10 microseconds.

    // Time to read the time the propagated soundwave took to bounce back and recieved by the reciever

    echotime = pulseIn (EchoPin, INPUT); // Reads the amount of time the recieved signal is on and outputs the time in Microseconds
    Distance_Sonic = (echotime*0.0343)/2;   // The calculated distance based on the equation, Distance = Time X Speed of sound/2

    
   radio.write(&Distance_Sonic, sizeof(Distance_Sonic));  
   Serial.println(Distance_Sonic);
   delay (100); 


}

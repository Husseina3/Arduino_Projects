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
bool IRState = false;
int IR = A3;
int i = 0;
int IR_Distance = 0;
int count = 0;
int LED1 = 9;
int flag = 10;
int val = 0;
int cm =0;

const byte address[6] = "00001";
void setup() {
  Serial.begin (9600);
  pinMode(IR, INPUT);
  pinMode(LED1, OUTPUT); 
  pinMode(flag, OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
 
  val =  analogRead (IR);   // turn the LED on (HIGH is the voltage level)
  cm = (5461 / (val - 17)) - 2;
/********************** IR Trigger *****************/
  if (cm <=35 && cm >= 0 && i == 0){
  digitalWrite(LED1, HIGH);
    count++;
    i++;
   delay (200);
   digitalWrite(LED1, LOW);
   delay (1000);
  }
  else if (cm >= 35){
    i = 0;
  }
/**************** Periodic update on count *****************/
   static unsigned long timer = millis();
  if (millis() >= timer) {
    int IR_Distance = count;
       radio.write(&IR_Distance, sizeof(IR_Distance));
       
       Serial.println(cm);
       digitalWrite(flag, HIGH);
       timer += 1000;
  }
  digitalWrite(flag, LOW);


 /***************** Lights OFF ****************/

}

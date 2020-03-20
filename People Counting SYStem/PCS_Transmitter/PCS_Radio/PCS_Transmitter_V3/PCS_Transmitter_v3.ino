/*
 * Pepole Counter System (PCS)Project V3
 * Author: Anwar Hussein
 * Location: DSC Rowan University Library
 * date: 3/1/2019
 * Last Update: 
 * 
*/

/******* Libraries for communication Protocols ********/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN

/******** Pin assignments and variable decalartions *******/

int IRA = A3; // Sensor A pin assignment 
int IRB = 6;

int i = 0;
int j = 0;

int IR_Distance = 0;
unsigned int count = 0;


int LED_A = 9;  // Object detection light for sensor A
int LED_B = 10; // Object detection light for sensor B

int val_A = 0; // Analog read value of sensor A

int cm_A =0; // Distance reading of Sensor A in cm
int cm_B =0; // Distance reading of Sensor B in cm

const byte address[6] = "00001";
void setup() {
  Serial.begin (9600);
  pinMode(IRA, INPUT);
  pinMode(IRB, INPUT_PULLUP);
  pinMode(LED_A, OUTPUT); 
  pinMode(LED_B, OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  /********************** IRA READ********************************/
 
  val_A =  analogRead (IRA);   // turn the LED on (HIGH is the voltage level)
  cm_A = (5461 / (val_A - 17)) - 2;

  val_A = digitalRead(IRB);

/********************** Walk IN (Increament) *****************/
  if (cm_A <=30 && cm_A >= 0 && i == 0 && j == 0){
        digitalWrite(LED_A, HIGH);
              i++;  
              count++;
             delay (1000);
             digitalWrite(LED_A, LOW);
             delay (2000);
  }
  
   if (val_A == HIGH && j==0 && i==0){
      digitalWrite(LED_B, HIGH);
        count--;
         j++;
         delay (1000);
         digitalWrite(LED_B, LOW);
         delay (2000);
   }
  
if (cm_A >=30 || cm_A <= 0){
  i=0;
}
if(val_A == LOW){
  j = 0;
}

    
/**************** Periodic update on count *****************/
   static unsigned long timer = millis();
  if (millis() >= timer) {
   unsigned int IR_Distance = count;
    radio.write(&IR_Distance, sizeof(IR_Distance));
       

       timer += 1000;
  }



}

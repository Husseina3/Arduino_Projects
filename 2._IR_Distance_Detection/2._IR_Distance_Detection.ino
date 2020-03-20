 /*
 * Project 2: Distance Detection 
 * Author: Anwar Hussein
 * Date: 12/5/2018
 * Last Updated: 1/10/2019
 */


/*
 * This project uses Sharp Infrared Sensor ( Sharp GP2Y0A02YK0F) to detect the object coming close and will count 
 * the number of times the IR sensor is crossed and the count will be displayed on the serial monitor. 
 */

// Declaring Variables

  int IRA = A13;                 // IR Analog input
  int IRB = A15;                 // IR Analog input
  int IRC = A12;
  int count = 0;                 // The counted values by the IRSensor
  int val_A = 0;                  // The variable storing value of the IR analog Input
  int val_B = 0;
  int val_C = 0;                  // The variable storing value of the IR analog Input
  int cm_A = 0;                   // Distance in CM
  int cm_B = 0;                   // Distance in CM
  int cm_C = 0;
  

void setup() {
  // Pin assignment and serial connection declaration

  pinMode (IRA, INPUT);          // Pin A0 (declared as "IRA") is set to be an input pin 
  pinMode (IRB, INPUT);          // Pin A0 (declared as "IRA") is set to be an input pin 
  pinMode (IRC, INPUT);
  Serial.begin (9600);           //The baud rate of the serial is 9600

 
}



void loop() {
      // This code will be run repeatedly
    
      val_A = analogRead (IRA);         
      //cm_A = 10*(4800/(val_A - 20));        
      cm_A = (5461 / (val_A - 17)) - 2;
      //cm= 13*pow(val, -1);
      
      //cm_A = 9462/(val_A - 16.92);
  
  //  Serial.print ("Sensor A = ");  
    Serial.println (cm_A);
         
   delay (100);
  

}

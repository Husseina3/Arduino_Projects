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

  int IRA = A0;                 // IR Analog input
  int count = 0;                 // The counted values by the IRSensor
  int val = 0;                  // The variable storing value of the IR analog Input
  int cm = 0;                   // Distance in CM
  int green = 7;                // Green LED connects to pin 7
  int yellow = 8;               // Yellow LED connects to pin 8
  int red = 12;                // red LED connects to pin 12
  
void setup() {
  // Pin assignment and serial connection declaration

  pinMode (IRA, INPUT);          // Pin A0 (declared as "IRA") is set to be an input pin 
  Serial.begin (9600);           //The baud rate of the serial is 9600

  pinMode ( green ,OUTPUT);      // Pin 7 (declared as "green") is set to be an output pin
  pinMode ( yellow  ,OUTPUT);    // Pin 8 (declared as "yellow") is set to be an output pin
  pinMode (  red ,OUTPUT);      // Pin 12 (declared as "red") is set to be an output pin

}



void loop() {
  // This code will be run repeatedly

  val = analogRead (IRA);          // The analog reading of the IR is stored to val
  //cm = 10*(4800/(val-20));        // Equation that relates distance in CM and the analog read of the ADC
  cm = (5461 / (val - 17)) - 2;

  
  Serial.print ("Object distance = ");  // Every other line on the serial monitor begins with the string "Object Distance"
  Serial.println (cm);                  // The distance of the object in relation to the IR sensor will be displace next to the above string.
   
  delay (100);                          // delay of half second after distance measured
  //Serial.print ("cout = ");             // Every other line on the serial monitor begins with the string "Count"
  //Serial.println (count);               // The number of times the IR sensor is crossed will be counted
  
/*
if (cm < 20 ) {                         // If the object distance to the sensor is less than 20 cm ...

   digitalWrite (green, HIGH);          // The Green LED light Turns ON 
   digitalWrite (yellow, LOW);          // The Yellow LED light Turns OFF 

   count ++;                            // The count increaments by 1
      delay (100);
  
   digitalWrite (green, LOW);           // after tenth of a second the Green LED turns off
  
  
   } 

if ( cm > 21 ) {                        // If the object distance to the sensor is greater than 21 cm ...

    if ( cm < 70) {                     // and if the distance is less than 70 cm ( 21 < distance < 70 ) 
  digitalWrite (yellow, HIGH);          // Yellow ON
  digitalWrite (green, LOW);           // Green OFF
  digitalWrite (red, LOW);             // Red OFF
  delay (100);                         // After tenth of a second ....
  
  digitalWrite (yellow, LOW);          // Yellow OFF
    }
     if ( cm > 71) {                  // and if the distance is greater than 70 cm (  distance > 70 )
  digitalWrite (red, HIGH);           // Red ON
  digitalWrite (green, LOW);          // Green OFF
  digitalWrite (yellow, LOW);         // Yellow OFF
  
  delay (100);                        // After tenth of a second ....
  
  digitalWrite (red, LOW);           // Red off
    }
}
  */
}

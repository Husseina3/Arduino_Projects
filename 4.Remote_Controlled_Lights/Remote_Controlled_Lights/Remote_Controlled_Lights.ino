 /*
 * Project Title: Remote Controlled Lights\
 * Platform: Arduino Uno * Arduino Pro mini
 * Autor: Anwar Hussein
 * Date Created:12/25/2018
 * Last Updated: 
 */

/***************************Remote Controlled Lights******************************\
 * This project implements an easy control of a house or office light using
 * a remote control. It can be applied in smart homes where a person can control
 * lights with out the need to physically go to the swiches on the wall. It can also
 * be used in offices in situations where a confrence room lights need to be dimmed or
 * turned off for presentations that involve projector use. 
 */

 /***************************System Installation***********************************/ /*
  * This system is designed to be flexiable and to easily fit into a pre-existing light 
  * system. the following list of methods explain the different ways the end product of 
  * this project is can be used.
  *               Method 1: The first way the end product of this project is made is as
  *                         a socket that will be pluged into outlets. Therefore, tabel
  *                         lamps and other electonic componets will be pluged on the 
  *                         socket and can be controlled by using a remote controller 
  *                         which controlls the socket. 
  *               Method 2: This method involves directly connecting the power line that 
  *                         goes to light bulbs, flourecent lights and diffeferent devices 
  *                         directly to the product.                           
  *                         
  */
#include "IRremote.h"


int LED = 10;      // Pin 10 is assigned the variable "LED"
int Remote = 11;   // Pin 11 is assigned the variable "Remote"
int count = 0;     // This variable is toggled by the power button of mini remote

IRrecv irrecv(Remote); 
decode_results results; // decode_results class is defined in IRremote.h

void setup() { 
  Serial.begin(9600);    //Baud rate of Serial communication is set to 9600
  pinMode (LED, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver 
} 

void loop() { 
  if (count == 1)  // if the power button is pressed turn on LED
        {
          digitalWrite(LED, HIGH);
        }
  else if (count == 0)   // if the power button is pressed while the light was on , turn off LED
        { digitalWrite(LED, LOW);
        }
  if (results.value == 1474556174)   // Decimal value of Volume Up button from universal remote 
     {
          digitalWrite(LED, HIGH);   // Turn on LED on volume up remote click
        }
  else  if (results.value == 1474497014) // Decimal value of Volume down button from universal remote 
      {
          digitalWrite(LED, LOW);    // Decimal value of Volume down button from universal remote 
        }
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); 
    if (results.value == 16753245 ){
      count ^= 1; 
    }
    Serial.println(count);
    irrecv.resume(); // Receive the next value 
  }
  delay (100); // small delay to prevent reading errors
}

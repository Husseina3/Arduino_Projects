  /*
 * Project Title: Remote and wifi Controlled Lights\
 * Platform: Arduino Uno * Arduino Pro mini *Esp8266 wifi module
 * Autor: Anwar Hussein
 * Date Created:12/25/2018
 * Last Updated: 1/8/2019
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
    
    
    int LED = 9;      // Pin 10 is assigned the variable "LED"
    int Remote = 8;   // Pin 11 is assigned the variable "Remote"
    
    int count = 0;     // This variable is toggled by the power button of mini remote
    char mqtt;         // MQTT controlled switch variable for wireless controling of the LED
    
    int sub = 0;       // subscribe status
    int sub_LED = 8;   // status LED
    
    unsigned long time; // time for first subscription on start
    int i = 0;

    // variables for subscribing to a topic on an interval. 
    unsigned long previousMillis = 0;        // will store last time LED was updated
    
    // constants won't change:
    const long interval = 10000;              // interval at which to blink (milliseconds)
    
    IRrecv irrecv(Remote); 
    decode_results results; // decode_results class is defined in IRremote.h


/************************************ setup **************************************/
void setup() { 
  Serial.begin(115200);    //Baud rate of Serial communication is set to 115200
  pinMode (LED, OUTPUT);
  pinMode (Remote, INPUT_PULLUP);
  pinMode (sub_LED, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver 
} 

void loop() { 

  /**************** MQTT Controller ****************/

   /****************** On button click Subscription ********************/
          
          if((results.value == 16712445) & (sub == 0) )    // if play button on mini remote is pressed
              {
              Serial.write("$livingroom\n");               // Subscribe to the "livingroom" topic
              digitalWrite (sub_LED, HIGH);
              sub = 1;      
              }
          if(results.value == 16769565)                    // Subscribe status LED turn off on Fun/stop button press
                {
              digitalWrite (sub_LED, LOW); 
              sub = 0;     
              }

  /**************************Subscribe on an interval *******************/
  
         unsigned long currentMillis = millis();
  
        if ( currentMillis - previousMillis  >= interval){ 
               previousMillis = currentMillis;
                     
              Serial.write("$livingroom\n");
          }
  
        if (Serial.available() > 0) {
       // read the incoming byte:
                mqtt = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(mqtt, DEC);
                
                 if ( byte(mqtt) == 49){   // if the "1" is recived 
                  count = 1;
                }
                  if ( byte(mqtt) == 48){   // if the "0" is recived 
                 count = 0;
                }
          }


/*****************************Remote Control *****************************************/
     
  if (count == 1)  // if the power button is pressed turn on LED
        {
          digitalWrite(LED, HIGH);
        }
  else if (count == 0)               
        { digitalWrite(LED, LOW);
        }
  if (results.value == 1474556174)      // Decimal value of Volume Up button from universal remote 
     {
          digitalWrite(LED, HIGH);      // Turn on LED
        }
  else  if (results.value == 1474497014)  // Decimal value of Volume down button from universal remote 
      {
          digitalWrite(LED, LOW);    // Turn LED off
        }

        
  if (irrecv.decode(&results)) {         //  On Power On remote button press
    if (results.value == 16753245 ){
      count ^= 1; 
    }
    irrecv.resume(); // Receive the next value 
  }
  delay (100); // small delay to prevent reading errors


  
}

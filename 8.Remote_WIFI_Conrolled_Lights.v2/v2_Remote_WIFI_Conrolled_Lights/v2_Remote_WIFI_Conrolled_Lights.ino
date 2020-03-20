 /*
 * Project Title: Remote and wifi Controlled Lights\
 * Platform: Arduino Uno * Arduino Pro mini *Esp8266 wifi module
 * Autor: Anwar Hussein
 * Date Created:12/25/2018
 * Last Updated: 1/4/2019
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
    char mqtt;         // MQTT controlled switch variable for wireless controling of the LED
    
    int sub = 0;       // subscribe status
    int sub_LED = 9;   // status LED
    
    unsigned long time; // time for first subscription on start
    int i = 0;

    // variables for subscribing to a topic on an interval. 
    unsigned long previousMillis = 0;        // will store last time of Subscription
    unsigned long previousMillis_p = 0;      // will store last time of Publish
    
    // constants won't change:
    const long interval = 30000;              // interval at which to Subscribe (milliseconds)
    const long interval_p = 30000;             // interval at which to Publish(milliseconds)
    
    IRrecv irrecv(Remote); 
    decode_results results; // decode_results class is defined in IRremote.h


  /************************************ setup **************************************/
  void setup() { 
    Serial.begin(115200);    //Baud rate of Serial communication is set to 115200
    pinMode (LED, OUTPUT);
   // pinMode (sub_LED, OUTPUT);
    irrecv.enableIRIn(); // Start the receiver 
  } 
  
  void loop() { 
      /**************************** MQTT Controller *************************/
              /***************************** Light Control *******************************/
         
             if (count == 1)  // if the power button is pressed turn on LED
                    {
                      digitalWrite(LED, HIGH);
                    }
              else if (count == 0)                  
                    { digitalWrite(LED, LOW);
                    }
  
     
      /**************************Subscribe on an interval *******************/
              /* unsigned long currentMillis = millis();
        
                if ( currentMillis - previousMillis  >= interval){ 
                       previousMillis = currentMillis;
                             
                      Serial.write("$livingroom\n");
                  }*/
      /**************************Publish on an interval *******************/
               unsigned long currentMillis_p = millis();
        
                if ( currentMillis_p - previousMillis_p  >= interval_p){ 
                       previousMillis_p = currentMillis_p;
                  //Publish LED OFF
                    if (count == 0){         
                      Serial.write("#livingroom Livingroom_OFF\n");
                        }
                        
                  //Publish LED ON
                    if (count == 1){         
                      Serial.write("#livingroom LivingRoom_ON\n");
                        }  
                }     
       /**************************** MQTT recieve 0 and 1 *************************/                         
                if (Serial.available() > 0) {
                  
               // read the incoming byte:
                        mqtt = Serial.read();                
                         if ( byte(mqtt) == 49){   // if the "1" is recived 
                          count = 1;
                          Serial.write("#livingroom LivingRoom_ON\n");
                        }
                          if ( byte(mqtt) == 48){   // if the "0" is recived 
                         count = 0;
                         Serial.write("#livingroom Livingroom_OFF\n");
                        }
                    }
            

     /****************** On button click Subscription ********************/
            
            if(results.value == 16712445)    // if play button on mini remote is pressed
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
  
      /*****************************Remote Control *****************************************/
            // Volume UP button
              if (results.value == 1474556174)      // Decimal value of Volume Up button from universal remote 
                 {
                      count = 1;      // Turn on LED
                    }
             // Volume Down button
              else  if (results.value == 1474497014)  // Decimal value of Volume down button from universal remote 
                  {
                     count = 0;    // Turn LED off
                    }
            
              // Power button      
              if (irrecv.decode(&results)) {         //  On Power On remote button press
                if (results.value == 16753245 ){
                  count ^= 1; 
                }
                irrecv.resume(); // Receive the next value 
              }
              delay (100); // small delay to prevent reading errors
  
  
    
  }

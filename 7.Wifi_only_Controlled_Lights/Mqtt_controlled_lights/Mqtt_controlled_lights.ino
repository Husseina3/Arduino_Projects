
 /*
 * Project Title: Mqtt Controlled Lights\
 * Platform: Arduino Uno * Arduino Pro mini *Esp8266 wifi module
 * Autor: Anwar Hussein
 * Date Created:1/5/2018
 * Last Updated: 1/5/2019
 */

 /*
  * This code implements a wifi controlled lights through an mqtt broker by using an
  * arduino pro mini and an esp8266 wifi module. 
  */
  int  Light = 9;
  int incomingByte = 0;                // The data that is recieved through the RX terminal
  const int interval = 30000;           // the interval by whcich the UART subscribes to the topic "bedroom"
  unsigned long previousMillis = 0;    // The last time of subscribtion
  int state = 0;   // state of light
  int button = 0;   // status of the button
  unsigned long time; // time for first subscription on start
  int i = 0;
    
  void setup() {
    
    Serial.begin (115200); // Initiallize UART at 115200 baud rate
    pinMode (Light, OUTPUT);        // Pin9 is initialized as an output pin
  
  }
  
  void loop() {
        time = millis();
  
        if (time == 10000 & i == 0){
          Serial.write("$bedroom\n");
          i = 1;
          
        }
    
  
 //*************************Subscribe on an interval ************************/
    unsigned long currentMillis = millis();
    
      if ( currentMillis - previousMillis  >= interval){ 
        previousMillis = currentMillis;
        
          Serial.write("$bedroom\n");
      }
          // Serially contlling the light 
            if (Serial.available() > 0) {
                  // read the incoming byte:
                  incomingByte = Serial.read();
                  
                   if ( byte(incomingByte) == 49){          // if the "1" is recived 
                    digitalWrite(Light, HIGH);             // turn of LED
                    Serial.write ("#bedroom Bedroom_ON\n");   // Publish Light is in ON
                  }
                    if ( byte(incomingByte) == 48){   // if the "0" is recived 
                    digitalWrite(Light, LOW);        // turn off LED
                   Serial.write ("#bedroom Bedroom_OFF\n");   // Publish Light is in ON
                  }
            }
              
          }
  
         
      
  
  

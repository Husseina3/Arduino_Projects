  /*
 * Project 2: Distance Detection 
 * Author: Anwar Hussein
 * Date: 12/5/2018
 * 
 */

// IR sensor 
 int IR_Sig = A0;       // connect A0 pin to the signal terminal of IR sensor
 int IR_Distance = 0;   // Initialize Ir sensor's distance
 int adc = 0;           // Initialize analog voltage read of IR sensor

 //int LED = 10;  // LED to indicate object detection

// Radio SPI
   // Libraries
  #include <SPI.h>
  #include <nRF24L01.h>
  #include <RF24.h>

  
  RF24 radio(7, 8); // CE, CSN
  const byte address[6] = "00001";     // byte address 
 
void setup() {
  pinMode (IR_Sig, INPUT);    // Initialize pin A0 as an inputput pin
 // pinMode (LED, OUTPUT);      // Initialize LED 
  Serial.begin (9600);           //The baud rate of the serial is 9600

  // Radio SPI
  radio.begin();      // Initiallize the radio object
  radio.openWritingPipe(address);    // set the address to the defined address
                                     // nrf mdoule suppors 121 chanells 
  radio.setPALevel(RF24_PA_MAX);     // set power amplifier to max for max_range
                                     // Use bypass caps for voltage stability
  radio.stopListening();
 
}

void loop() {


/***************************************IR Sensor Implementaion ****************************************************/


      adc = analogRead (IR_Sig);             // The analog reading of the IR       
      IR_Distance = 5461 / (adc - 17) - 2;   // Equation that relates distance in CM and the analog read of the ADC
          
           
           
  /****************************************** Radio transmitter ********************************/
     // if (IR_Distance <= 10){
      radio.write(&IR_Distance, sizeof(IR_Distance));  // "&" indicates that the variable"text"                                       
      delay (100);
     // }
       
}

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
int Relay = 9;
const byte address[6] = "00001";
void setup() {
  //Serial.begin(9600);
  pinMode (Relay, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {

  if (radio.available()) {
    //char text[32] = "";
    bool PIRState = false;
    radio.read(&PIRState, sizeof(PIRState));
    
      if (PIRState == true){
  // Serial.println(PIRState);
   digitalWrite (Relay, HIGH);
   delay (15000);
  // Serial.println("Enough, LIGHTS off!");
   
   digitalWrite (Relay, LOW); 
   PIRState == false;
  }
  else {
    digitalWrite (Relay, LOW);
  }
  }
  
}

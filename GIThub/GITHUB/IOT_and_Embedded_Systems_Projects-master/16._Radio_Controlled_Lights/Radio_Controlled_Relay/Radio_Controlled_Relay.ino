#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

int Relay = 9;
int cm = 0;
void setup() {
  Serial.begin(9600);
  pinMode (Relay, OUTPUT);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate( RF24_250KBPS );
  radio.startListening();
}
void loop() {
  
 if (radio.available()) {
    int state = 0; 
    radio.read(&state, sizeof(state));  
    Serial.print(state);

    if (state == 1){
      digitalWrite (Relay, HIGH);
      Serial.print("LIGHTS ON");
    }
     if (state == 0){
      digitalWrite (Relay, LOW);
      Serial.print("LIGHTS Off");
    }
    
      
      
  } 
    
    
    }

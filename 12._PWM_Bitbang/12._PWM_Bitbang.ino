/*void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delayMicroseconds(100); // Approximately 10% duty cycle @ 1KHz
  digitalWrite(13, LOW);
  delayMicroseconds(1000 - 100);
}*/

float analogPin = A7; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
float val = 0.0;  // variable to store the value read
float Vin = 0.0;
float D = 0.0;

void setup() {
  pinMode (A7, INPUT);
  Serial.begin(9600);           //  setup serial
}

void loop() {
  val = analogRead(analogPin);  // read the input pin
  val = (val * 5.0) / 1024.0; 
  //val = map(val, 0, 1023, 0.00,4.99);
  
  D = (3.3/val)*100;
  Serial.print("V_in= ");
  Serial.println(val);          // debug value
  Serial.print("Duty Cycle = ");
  Serial.println(D);          // debug value
  delay (500);
}

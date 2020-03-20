
/* UltraSonic Distance sensor and Display
 *  Author: Anwar Hussein
 *  Date: 12/7/2018
 */

  /*Working Principle 
   * 
   * The Ultrasound sensor has 4 pins, VCC, TRIGER, ECHO & GND. The sound wave that is 
   * propagated through the transmitter of the sensor will reflect back to the transmitter 
   * end of the sensor after bouncing back from an object.
   * 
   * Distance is calculated as,  Distance = Time X (Speed of Sound)/2
   * 
   * To measure distance First: The triger must be high for a minimum of 10 microseconds.  
   *                     Second: The sensor sends 8 sonic bursts from the module of ultrasound at 40 KHZ
   *                     Third: The echopin will recieve the beam and output the time in microseconds. 
   */
// Library

#include <LiquidCrystal.h> 


 /* Pin assignment of the LCD to the board 
  *  On the upright lcd where the pins lie on the top, the left most pin of the LCD is 
  *  connected to the right most port of the REDBOARD
  */
 LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 
                              


// Variable Diclaration
  
  int TrigPin = 7;         // Trigger of the Sonic Sensor
  int EchoPin = 6;         // Echo of the Sonic Sensor
  int LED = 6;            // Status LED: Blinks on action
  int MSP = A0;            // Connects of MSP430 G2553 Microcontroller for IR sensor result
                          // This pin signals High when IR sensor is broken by an object
  
  int Distance_Sonic = 0;        // Distance measured by Sonic Sensor        
  int Distance_IR = 0;
  int echotime = 0;        // The time the reflected sound wave is recieved by the reciever end of the 
                           // sonic sensor. This value is used in the distance equation.
  int val = 0;
  int count = 0;           // Number of counted people will be saved in this variable. 

  int i = 0;               // i - a variable that serves as a precondiction in if statements which 
                           // is connected to the IR sensor input
  int J = 0;               // J - is a variable that serves as a precondition in if statements which
                           // is connected to the sonic sensor input 

  
  void setup() {

    /*------------- Crystal Display -------------*/
    
     lcd.begin(16 , 2);              // LCD we're using has 16 colums and 2 rows.
    lcd.clear();                     // Clears the display
    
    // Pin assignment and Serial Communication initialization
  
   pinMode (TrigPin, OUTPUT);        // The TrigPin is set as an Output pin
   pinMode (EchoPin, INPUT);         // The EcoPin is  set as an Input Pin
   pinMode (LED, OUTPUT);            // The action indicating LED
   pinMode (MSP, INPUT_PULLUP);       // Input from MSP430 G2553 microconroller 
   
   Serial.begin (9600);           // Serial Communication initiallized with 9600 Baud rate 
   
  
  }
  
  void loop() {
    
    // Calculate distance based on the duration 

    digitalWrite (TrigPin, LOW);                // Send 0 through to the sensor through the Trigpin 
    delay (300);                               // 2 second delay

  
    digitalWrite (TrigPin, HIGH);               // Send an output high signal for 10 microseconds;
    delayMicroseconds(10);
    
    digitalWrite (TrigPin, LOW);                // Set the trigpin to 0 after being high for 10 microseconds.

    // Time to read the time the propagated soundwave took to bounce back and recieved by the reciever

    echotime = pulseIn (EchoPin, HIGH); // Reads the abmount of time the recieved signal is on and outputs the time in Microseconds
    Distance_Sonic = echotime*0.034/2;   // The calculated distance based on the equation, Distance = Time X Speed of sound/2

    Serial.print ("Distance_Sonic = ");       // Each line on the serial monitor will display the string "Distance = "
    Serial.println (Distance_Sonic);          // After the string, the measured and calculate distance value will be dispalyed

    
    val = analogRead(MSP);
    Distance_IR = 4800/(val-20); 
    

    
    Serial.print ("Distance-IR = ");       // Each line on the serial monitor will display the string "Distance = "
    Serial.println (Distance_IR);          // After the string, the measured and calculate distance value will be dispalyed
     
     lcd.setCursor(0,0);                // The cursor begins at (0,0) position or top left
     lcd.print("Number of People");      // The string "Number of People" will be displayed on the lcd top row.

     lcd.setCursor (0,2);               // The cursor begins on the boton left corner
     lcd.print(count);

    // Counter implementation
 
  }
  
 

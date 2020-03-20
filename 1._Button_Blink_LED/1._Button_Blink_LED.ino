

/*Project 1: Button Blink LED
 * Author: Anwar Hussein
 * Date: 12/5/2018
 */

/* 
 * This is project was programed on Arduino IDE by using sparkfun REDboard. 
 * In this project a LEDs will be controlled by a button press. A 9600 baud rate 
 * serial communication was implemented to monitor the status of the LEDs. When a
 * button is pressed the LEDS will blink in a pattern and the color that is blinking
 * will be displayed on a serial monitor.
 * 
 * 
 */


 //declaring Variables 
int yellow = 12;
int red = 13;
int green = 7;
int button = 8;
int i=0;


// Pin assignment adn serial connection declaration
void setup() {
  // start Serial connection 9600 buad rate
  Serial.begin(9600);

  //set pins as input and output pins
  pinMode (yellow, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (green, OUTPUT);
  
  // set pin as input and connect to internal pullup resistor
  pinMode (button, INPUT_PULLUP); 
  
}

void loop(){

// On Button press the Green LED Blinks and The variable I = 1

if( digitalRead(button) == LOW)  {
  digitalWrite(green, HIGH);
  Serial.println("Blinking Green - G0"); // Text "Blinking Green-GO" willbe 
  i++;                                   //dispalyed on the serial monitor
  delay(1000);   

   digitalWrite(green, LOW); // After a second the green led will be off
  }
  
/*   After the Red LED turns off the value of i=1 therefore the next instruction will execute
 * The yellow LED will Trun on and the text "Blinking Yellow - Caution" will be displyed 
*/ 

 if( i == 1)
 {
  digitalWrite(yellow, HIGH);
  Serial.println("Blinking Yellow - Caution ");
  delay(1000);

  digitalWrite(yellow, LOW); // The yelllow LED will turn off after a second.

  i++ ; // The value of i = 2, increaments by one.
 }

 /* 
 * The next instruction will execute since the value of i = 2.
 * The Red Led will turn on and the text "Blinking RED - STOP" will be displayed.
 */
 
 if (i == 2) {
  digitalWrite(red, HIGH);
   Serial.println("Blinking RED - STOP");
  i = 0;
  delay(1000);
  
  digitalWrite(red, LOW);
 }
}

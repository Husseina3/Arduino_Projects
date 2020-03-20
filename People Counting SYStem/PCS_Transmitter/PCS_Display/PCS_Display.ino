
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int IR = A3;
int val = 0;
int cm = 0;
int i = 0;
int count = 0;
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("# of people *_*");
}

void loop() {
 //  val = analogRead (IR);          // The analog reading of the IR is stored to val
  //cm = (4800/(val-20));        // Equation that relates distance in CM and the analog read of the ADC
  cm = (5461 / (val - 17)) - 2;

/***************count Algorithm *********************/
  /*  if (cm <= 20 & i == 0){
      count++;
      i++;
      delay (1000);}
      else if(cm >= 21){
        i =0;} */
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // lcd.print(count);
   lcd.print (cm);
   delay (1000);
 //  lcd.print("  "); 
   // lcd.print(cm);
   
 /* // print the number of seconds since reset:
    static unsigned long timer = millis();
  if (millis() >= timer) {
    timer += 1000;
     lcd.print(count);
  }*/
 
}

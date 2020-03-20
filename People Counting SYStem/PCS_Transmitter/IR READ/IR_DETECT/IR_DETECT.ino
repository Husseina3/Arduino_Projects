/*PCS
 * Author: Anwar Hussein
 * Date: 3/2/2019
 */

 int IR = 0;
 int LED = 9;
 int FLAG = 8;
 int val = 0;
 int cm =  0;
 int i = 0;
 
 

 void setup(){
   pinMode (IR, INPUT);
   pinMode (LED, OUTPUT);
   pinMode (FLAG, OUTPUT);
   Serial.begin (9600);  
  }

  void loop(){

  /************ IR READ ************/
  val =  analogRead (IR);   // turn the LED on (HIGH is the voltage level)
  cm = (5461 / (val - 17)) - 2;

  /************** Action *****************/
  if (cm <= 30 && i == 0) {
    i++;
    digitalWrite (LED, HIGH);
    digitalWrite (FLAG, HIGH);

    delay (1000);
    digitalWrite (LED, LOW);
    digitalWrite (FLAG, LOW);
    
  
  }

  else if (cm >= 25 || cm <= 0){
    i=0;
    }
    
    Serial.print("Distance = ");
    Serial.println(cm);
  
    }

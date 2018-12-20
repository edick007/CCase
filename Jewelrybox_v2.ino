//by ed d for minda cruz

#include <Servo.h>

 Servo myservo;  // create servo object to control a servo
 Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards
  unsigned char LED1 = 11;
  unsigned char LED2 = 12;
  unsigned char LED3 = 13;
  unsigned char buttonOn = A0;
  int pos = 0;    // variable to store the servo position
  enum button_states {start, baseOn, baseOff, on, off};
  enum button_states state;
void setup() {
  pinMode(buttonOn, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
  delay(1000);
    state = start;
   
}


enum tester {start1, on1, off1};


unsigned char button1state = digitalRead(buttonOn);
  
void test(){
  
  
}
  unsigned char FLAG =0;
void loop() {

switch(tester){
     case start1:
       stater = on1;
     break;
     case on1:
      if (button1state == HIGH){
        stater = on1;
       }
      else 
       {
        stater = off1;
       }
     break;
     case off1:
      if (button1state == HIGH){
        stater = off1;
       }
      else 
       {
        stater = on1;
       }
     break;
     default:
       stater = start1;
     break;
  }
  switch(stater){
     case start1:
     digitalWrite(LED3, HIGH);
     break;
     case on1:
      digitalWrite(LED1, HIGH);
     break;
     case off1:
      digitalWrite(LED1, LOW);
     break;
  }
  

}





/* ------- Code that might just work -------
 *  
 *  
  unsigned char button1state = digitalRead(buttonOn);
  switch(state){
    case start:
      state = off;
    break;
    case off:
      if (button1state == HIGH) // if button is pressed 
      {
        state = baseOff; // go to the state to wait for button release
      }
      else {
        state = off;     // stay in the off state
      }
    break;
    case baseOff:
      if (button1state == HIGH) //if the button is still pressed 
      {
        state = baseOff;  // stay here
      }
      else{
        state = on;  //else go to on
      }
      
    break;
    case on:
      if (button1state == HIGH)
      {
        state = baseOn;
      }
      else {
        state = on;
      }
    break;
    case baseOn:
      if (button1state == HIGH)
        {
          state = baseOn;
        }
        else {
          state = off;
        }
    break;
    default:
      state = start;
    break;
  }
  switch(state){
    case start:
      //do nothing
    break;
    case off:
       digitalWrite(LED1, LOW);  
      myservo.write(10);              // tell servos to close box
      myservo2.write(180); 
      delay(1000);  
          
    break;
    case baseOff:
      //wait for button release
      digitalWrite(LED3, HIGH);
    break;
    case on:
      digitalWrite(LED2, HIGH);
      myservo.write(100);              // tell servos to open box
      myservo2.write(65); 
      delay(1000);    
      
    break;
    case baseOn:
      // wait for button release
    break;
  }


  */


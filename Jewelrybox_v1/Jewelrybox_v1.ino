//by ed d for minda cruz

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
// twelve servo objects can be created on most boards
unsigned char buttonOn = A0;
int pos = 0;    // variable to store the servo position
enum button_states {start, baseOn, baseOff, on, off};
enum button_states state;
void setup() {
  pinMode(buttonOn, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);  // attaches the servo on pin 9 to the servo object
  delay(1000);
    state = start;
   
}




  unsigned char FLAG =0;
void loop() {
  switch(state){
    case start:
      state = off;
    break;
    case off:
      if (digitalRead(buttonOn) == LOW)
      {
        state = baseOff;
      }
      else {
        state = off;
      }
    break;
    case baseOff:
      if (digitalRead(buttonOn) == LOW)
      {
        state = baseOff;
      }
      else{
        state = on;
      }
      
    break;
    case on:
      if (digitalRead(buttonOn) == LOW)
      {
        state = baseOn;
      }
      else {
        state = on;
      }
    break;
    case baseOn:
      if (digitalRead(buttonOn) == LOW)
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
      myservo.write(10);              // tell servos to close box
      myservo2.write(180); 
      delay(1000);           
    break;
    case baseOff:
      //wait for button release
    break;
    case on:
      myservo.write(100);              // tell servos to open box
      myservo2.write(65); 
      delay(1000);    
    break;
    case baseOn:
      // wait for button release
    break;
  }

  

}


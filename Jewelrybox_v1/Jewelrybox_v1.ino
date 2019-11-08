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
// Variables for CCase
  //for opening and closing
unsigned char divisions = 10; // In Function: caseOpen and caseClose, sets the smoothness of the opening and closing
unsigned char s1_min = 10;
unsigned char s1_max = 100;
unsigned char s2_min = 65;
unsigned char s2_max = 180;

void caseOpen_fast(){
  myservo.write(100);              // tell servos to close box
  myservo2.write(65); 
}

void caseClose_fast(){
  myservo.write(10);              // tell servos to close box
  myservo2.write(180); 
}


void caseOpen(){
  change_angle_s1 = s1_max - s1_min;
  change_angle_s2 = s2_max - s1_min;
  for(unsigned char i = 1; i < divisions; i ++){
    myservo.write(s1_min + (change_angle_s1 / i));
    myservo2.write(s2_max - (change_angle_s2 / i));

  }
}

void caseClose(){
  myservo.write(10);              // tell servos to close box
  myservo2.write(180); 
}



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




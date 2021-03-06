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
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(6);  // attaches the servo on pin 9 to the servo object
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
  unsigned char change_angle_s1 = s1_max - s1_min;
  unsigned char change_angle_s2 = s2_max - s2_min;
  for(unsigned char i = 1; i < divisions; i++){  //function that takes the difference between the diference of angel from open and closed
    myservo.write(s1_min + (change_angle_s1 / i));//  then breaks up the close and open animation to 10 intervals to slow it dwn
    myservo2.write(s2_max - (change_angle_s2 / i));
    delay(200);
  }
}

void caseClose(){
  unsigned char change_angle_s1 = s1_max - s1_min;
  unsigned char change_angle_s2 = s2_max - s2_min;
  for(unsigned char i; i < divisions; i++){
    myservo.write(s1_max - (change_angle_s1/i));              // tell servos to close box slower than fast
    myservo2.write(s2_min + (change_angle_s2/i)); 
    delay(500);
  }
}

void loop() {
  switch(state){
    case start:
     // state = off;
     state = on;
    break;
    case off:
      if (digitalRead(buttonOn) == LOW)
      {
        //state = baseOff;
        state = on;
        delay(10000);
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
        //state = baseOn;
        state = off;
        delay(10000);
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
     caseClose();        
    break;
    case baseOff:
      //wait for button release
    break;
    case on:
      caseOpen();    
    break;
    case baseOn:
      // wait for button release
    break;
  }

  

}




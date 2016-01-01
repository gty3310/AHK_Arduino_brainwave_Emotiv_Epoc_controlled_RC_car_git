/*
 * http://spacetinkerer.blogspot.ca/2011/02/arduino-control-over-serial-port.html
 */

#include <Servo.h>
Servo turningservo;
Servo drivemotor;

int input = 0;       // variable to keep the data from the serial port

void setup() {
  pinMode(13,OUTPUT);    // declare the LED's pin as output
//  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  turningservo.attach(9); 
  drivemotor.attach(12);
  Serial.begin(9600);        // connect to the serial port
}

void motor(int val) {
  drivemotor.write(val+90);
  //Serial.println (val+90);
}

void loop () {
  input = Serial.read();  
  if (input == 'R' ) {
    digitalWrite(13,HIGH);
    turningservo.write(122);
    delay(100);
    digitalWrite(13,LOW);
    
    Serial.println("right:blink");
  } 
  if (input == 'L'){
    turningservo.write(73);
//    digitalWrite(12,HIGH);
    delay(100);
//    digitalWrite(12,LOW);
    Serial.println("left:raise brow");
  } 
    if (input == 'S'){
    digitalWrite(11,HIGH);
     motor(5);
    delay(100);
    digitalWrite(11,LOW);
    Serial.println("front:smile");
  } 
      if (input == 'B'){
    motor(-5);
    delay(100);
    Serial.println("back:smile");
  } 
}

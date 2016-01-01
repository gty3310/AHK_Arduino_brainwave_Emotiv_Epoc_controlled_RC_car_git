/*
 * http://spacetinkerer.blogspot.ca/2011/02/arduino-control-over-serial-port.html
 */



int input = 0;       // variable to keep the data from the serial port

void setup() {
  pinMode(13,OUTPUT);    // declare the LED's pin as output
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);        // connect to the serial port
}

void loop () {
  input = Serial.read();      // read the serial port

  // if the input is '1' turn the LED ON, if '0' turn it OFF
  if (input == 'R' ) {
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    Serial.println("13:blink");
  } 
  if (input == 'L'){
    digitalWrite(12,HIGH);
    delay(100);
    digitalWrite(12,LOW);
    Serial.println("12:raise brow");
  } 
    if (input == 'S'){
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(11,LOW);
    Serial.println("11:smile");
  } 
}

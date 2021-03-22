#include<SoftwareSerial.h>
#include <Servo.h>
Servo myservo;
SoftwareSerial BTserial(6, 7); //rx,tx

int pos=0;
int state;
int servoPin = 9;
void setup() {
  pinMode(servoPin,OUTPUT);
  myservo.attach(9);
  BTserial.begin(9600);
  Serial.begin(9600); 
  BTserial.println("Bluetooth On please press f or g blink LED ..");
}

void loop() {
  
  if (BTserial.available() > 0) { // Checks whether data is comming from the serial port
                  state = BTserial.read(); // Reads the data from the serial port
                       //Read the incoming data and store it into variable data
                    
                   
                
              
                if(state == 'g'){
                  
                    for (pos = 4; pos < 80; pos ++) { // goes from 0 degrees to 180 degrees
                    // in steps of 1 degree
                    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                                          // waits 15ms for the servo to reach the position
                    }
                    Serial.println("g");
                }
                else if(state == 'f'){
                    for (pos = 80; pos >= 4; pos --) { // goes from 180 degrees to 0 degrees
                    // in steps of 1 degree
                    myservo.write(pos);              // tell servo to go to position in variable 'pos'
                                          // waits 15ms for the servo to reach the position
                  }
                Serial.println("f");
               }
               else{
                digitalWrite(servoPin,LOW);
               }
 }
  

}

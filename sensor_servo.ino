// M.Wolak        //
// ENME351        //
// S19 Mitchel    //
// Final Project  //
// Lab 9          //



//  The following code was based on a project done by Anas Siddiqui  //
//  see project @ arduino project hub                         //
//   https://create.arduino.cc/projecthub/Anas/control-a-servo-with-a-force-resistive-sensor-on-arduino-91ef61  //

          #include <Servo.h>        // inculdes servo library
           Servo servo0;            // names 1st servo
           int reading0;            // declares reading from sensor
           
           Servo servo1;            // names 2nd servo
           int reading1;            // declares reading from sensor (there is a 2 sensor option)
           
          void setup(void) {
           Serial.begin(9600);      // baud rate
           servo0.attach(10);       //servo at digital pin 10 w/ PWM
           servo0.write(0);        //initial point for servo

           servo1.attach(11);      //servo #2 at digital pin 11 w/ PWM
           servo1.write(0);       //initial point for servo
          
          }
           
          void loop(void) {

//FSR0 and servo0
            reading0 = analogRead(A5);                  //attached to analog 5
            //Serial.print("Sensor value 0 = ");          //prints label
              //  Serial.println(reading0);                   //prints FSR0 reading in line
          int value0 = map(reading0, 0, 600, 60, -60);   // maps FSR0 reading from 0-600 onto servo0 angle 0-180
            servo0.write(value0);                       //write servo

//FSR1 and servo1
            reading1 = analogRead(A5);                  //attached to analog 4
            //Serial.print("Sensor value 1 = ");          //prints label below sensor value 0
              //Serial.println(reading1);                   //prints FSR1 reading in line
              if (reading1 > 100){                        // if sensor value is greater than 100
                Serial.println("Curb Your Enthusiasm");   // print this to monitor
              }
              else 
                  Serial.println("Seinfeld");             // if sensor value is less than 100, print this
          int value1 = map(reading1, 0, 600, -60, 60);   // maps FSR1 reading from 0-600 onto servo1 angle 0-180 
                    servo1.write(value1);               //write servo1 to angle based on FSR1

            
            delay(3500);                                //delay of 4 seconds to account for golf ball rolling back and fourth and to sync servos
            
                      }

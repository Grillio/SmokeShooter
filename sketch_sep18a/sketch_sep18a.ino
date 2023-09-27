#include <AccelStepper.h>

AccelStepper horizontal(1, 2, 3);
AccelStepper vertical(1, 4, 5);
AccelStepper shooter(1, 6, 7);

void setup() {
    Serial.begin(4800);

    horizontal.setAcceleration(100);
    horizontal.setMaxSpeed(200);

    vertical.setMaxSpeed(200);
    vertical.setAcceleration(100);

    shooter.setAcceleration(100);
    shooter.setMaxSpeed(200);
    delay(200);
}

//int horizontalPos = 0;

void loop() {

  while(Serial.available()){
      const char Identifier = (char) Serial.read();
      switch(Identifier){
        case ('H'):
          //Serial.println("Message Received");
        //wait until there are 2 bytes in the serial before executing reading functions
          while(Serial.available() < 1){

          }
          //Serial.println("Executing command");
          horizontal.moveTo((long) Serial.read());
          break;
        case ('V'):
          while(Serial.available() < 1){

          }
          vertical.move((long) Serial.read());
          break;
        case ('S'):
          while(Serial.available() < 1){

          }
          break;
        
      }
  }
  horizontal.run();
}

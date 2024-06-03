#ifndef INCLUDED_CAR_H
#define INCLUDED_CAR_H

#include "Arduino.h"
#include "UltrasonicSensor.h" // Include the UltrasonicSensor header
#include <Servo.h>

class Car {
private:
  int direction_;
  int speed_;
  int angle_;

public:
  Car();
  Car(int direction, int speed);

  // Modifiers
  void change_drive(int dir);  // FORWARD or BACKWARD
  void change_speed(int spd);
  void change_direction(Servo& s, short angle);  // Axle change

  // Accessors
  int direction();
  int speed();
  void run();
  void run(Servo& s, UltrasonicSensor& us);
};

#endif  // INCLUDED_CAR_H
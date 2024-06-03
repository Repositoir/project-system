#include "config.h"
#include "Car.h"

Car::Car() {
  direction_ = FORWARD;
  speed_ = 0;
}

Car::Car(int direction, int speed) {
  direction_ = direction;
  speed_ = speed;
}

// Modifiers

void Car::change_drive(int dir) {
  direction_ = dir;
}

void Car::change_speed(int spd) {
  speed_ = spd;
}

void Car::change_direction(Servo& s, short angle) {
  s.write(angle);
}

// Accessors

int Car::direction() {
  return direction_;
}

int Car::speed() {
  return speed_;
}

// Run function
void Car::run() {
  digitalWrite(MOTOR_ENABLE, HIGH);
  if (direction_ == FORWARD) {
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
    // if (speed_ > 40) speed_ = 40;
    analogWrite(SPEED_CTRL, speed_);
  } else if (direction_ == REVERSE) {
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
    // if (speed_ > 40) speed_ = 40;
    analogWrite(SPEED_CTRL, speed_);
  }
}



void Car::run(Servo& s, UltrasonicSensor& us) {
  if (us.detected_object()) {
    speed_ = 0;
    // s.write(60);
    // speed_ = 40;
  } 
  digitalWrite(MOTOR_ENABLE, HIGH);
  if (direction_ == FORWARD) {
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
    // if (speed_ > 40) speed_ = 40;
    analogWrite(SPEED_CTRL, speed_);
  } else if (direction_ == REVERSE) {
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);

    // if (speed_ > 40) speed_ = 40;
    analogWrite(SPEED_CTRL, speed_);
  }
}
#include "Arduino.h"
#include "UltrasonicSensor.h"
#include "config.h"
#include "Car.h"
#include "InfraredSensor.h"

// Functions declared in test.ino
extern void setShiftRegisterBit(int bit, bool value);

UltrasonicSensor::UltrasonicSensor(int echoPin, int trigPin)
  : echoPin_(echoPin), trigPin_(trigPin), objectDetected_(false) {
  pinMode(trigPin_, OUTPUT);
  pinMode(echoPin_, INPUT);
}

long UltrasonicSensor::read_sensor() {
  // Clear the trigger pin (set bit to LOW)
  // digitalWrite(trigPin_, LOW);
  setShiftRegisterBit(trigPin_, LOW);
  delayMicroseconds(2);

  // Send a 10 microsecond pulse to the trigger pin (set bit to HIGH)
  setShiftRegisterBit(trigPin_, HIGH);
  // digitalWrite(trigPin_, HIGH);

  delayMicroseconds(10);

  // Clear the trigger pin (set bit to LOW)
  setShiftRegisterBit(trigPin_, LOW);
  // digitalWrite(trigPin_, LOW);


  // Read the echo pin
  long duration = pulseIn(echoPin_, HIGH);

  // Calculate the distance in centimeters
  long distance = microsecondsToCentimeters(duration);

  // Update the object detected status
  objectDetected_ = (distance < 30);  // Example threshold for object detection

  return distance;
}

bool UltrasonicSensor::detected_object() {
  return objectDetected_;
}

long UltrasonicSensor::microsecondsToCentimeters(long microseconds) {
  // Sound travels at 343 meters per second, or 29.1 microseconds per centimeter.
  // The round trip time is twice the distance.
  return microseconds / 29 / 2;
}

void UltrasonicSensor::avoid_obstacle(Car& car){
  if (!detected_object()) return;

  while (!detected_object()) {
    car.change_speed(0);
    car.change_drive(REVERSE); // This part didnt work when we tested Dung check it again

    car.change_speed(35);

    delay(1000);

    car.change_speed(0);
    car.change_drive(FORWARD);
    car.change_direction(120); // Or whichever is right maybe 120 or 60

    car.change_speed(35);

    car.change_direction(90); // Correct after turning right

    delay(1000);

    car.change_direction(60); // Or whichever angle is left;
  }

  /// TODO: Add more code here if required to find the line again.

  /* NOTE: Pass a Car class to this function as an argument.
   * The values need to be modified becuase I dont rmbr many of them
   * Add modifications to the delays as per required
  */
}

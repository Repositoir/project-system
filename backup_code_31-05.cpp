#include "config.h"
#include <QTRSensors.h>
#include <Servo.h>
#include "UltrasonicSensor.h"
// #include "GyroscopeSensor.h"
#include "Car.h"

QTRSensors qtr;
Servo s1;
// GyroscopeSensor gs();

const uint8_t SensorCount = 5;
uint16_t sensorValues[SensorCount];

// Variable to hold the current state of the shift register
// byte shiftRegisterState = 0;
UltrasonicSensor us(ECHO_PIN, TRIG_PIN);
// Declare classes
Car testCar = { FORWARD, 38 };

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // // Set control pins as outputs
  // pinMode(latchPin, OUTPUT);
  // pinMode(clockPin, OUTPUT);
  // pinMode(dataPin, OUTPUT);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // turn on Arduino's LED to indicate we are in calibration mode

  s1.attach(10);
  // configure the sensors
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ A0, A1, A2, A3, 3 }, SensorCount);
  qtr.setEmitterPin(2);

  delay(50);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // turn on Arduino's LED to indicate we are in calibration mode

  // analogRead() takes about 0.1 ms on an AVR.
  // 0.1 ms per sensor * 4 samples per sensor read (default) * 6 sensors
  // * 10 reads per calibrate() call = ~24 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 100; i++) {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);  // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SensorCount; i++) {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(100);
}

void loop() {

  long distance = us.read_sensor();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(50);  // Wait for 1 second before the next reading
  testCar.run(s1, us);
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000 (for a white line, use readLineWhite() instead)
  uint16_t position = qtr.readLineWhite(sensorValues);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum
  // reflectance and 1000 means minimum reflectance, followed by the line

  Serial.print(sensorValues[0]);
  Serial.print('\t');
  Serial.print(sensorValues[1]);
  Serial.print('\t');
  Serial.print(sensorValues[2]);
  Serial.print('\t');
  Serial.print(sensorValues[3]);
  Serial.print('\t');
  Serial.print(sensorValues[4]);
  Serial.print('\t');
  // position
  Serial.print(position);
  Serial.println();
  
  // TODO: Find the right
  if (sensorValues[0] <= 550) {
    // Serial.println("Car turn right: 60");
    s1.write(60);
    testCar.change_speed(45);  //
  }
  if ( sensorValues[1] <= 550) {
    // Serial.println("Car turn right: 60");
    s1.write(80);
    testCar.change_speed(40);  //
  }
  if ( sensorValues[2] <= 550) {
    // Serial.println("Car turn right: 60");
    s1.write(90);
    testCar.change_speed(38);  //
  }
  if ( sensorValues[3] <= 550) {
    // Serial.println("Car turn right: 60");
    s1.write(110);
    testCar.change_speed(38);  //
  }
  if ( sensorValues[4] <= 550) {
    // Serial.println("Car turn right: 60");
    s1.write(120);
    testCar.change_speed(45);  //
  }
  // if (sensorValues[4] <= 550) {
  //   // Serial.println("Car turn right: 60");
  //   s1.write(120);
  //   testCar.change_speed(45);  //
  // }
  // bool condition1 = (sensorValues[0] > 900 && sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3] > 900);
  // bool condition2 = (sensorValues[0] < 200 && sensorValues[1] < 200 && sensorValues[2] < 200 && sensorValues[3] < 200);
  // if (condition1 || condition2) {
  //   testCar.change_speed(0);
  // }

  delay(45);
}

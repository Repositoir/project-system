#include <QTRSensors.h>
#include <Servo.h>
#include "config.h"
#include "Car.h"
#include "UltrasonicSensor.h"

Servo carServo;
QTRSensors qtr;
UltrasonicSensor us(ECHO_PIN, TRIG_PIN);
Car testCar = { FORWARD, 48 };

uint16_t sensorValues[SENSOR_COUNT];

unsigned char carState = FOLLOW_LINE;  // What the car is doing at any given moment.

CAR_STATE state = CAR_STATE::FOLLOW_LINE;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  carServo.attach(SERVO_PIN);
  carServo.write(SERVO_CENTER);

  // configure the sensors
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ QTA_IR_1_PIN, QTA_IR_2_PIN, QTA_IR_3_PIN, QTA_IR_4_PIN }, SENSOR_COUNT);
  qtr.setEmitterPin(2);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // turn on Arduino's LED to indicate we are in calibration mode

  // analogRead() takes about 0.1 ms on an AVR.
  // 0.1 ms per sensor * 4 samples per sensor read (default) * 6 sensors
  // * 10 reads per calibrate() call = ~24 ms per calibrate() call.
  // Call calibrate() 400 times to make calibration take about 10 seconds.
  for (uint16_t i = 0; i < 400; i++) {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);  // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  static bool isStop = false;
  testCar.run();
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 3000 (for a white line, use readLineWhite() instead)
  uint16_t position = qtr.readLineWhite(sensorValues);
  // Find the right angle to make the car manueve
  testCar.change_speed(45);
  if (sensorValues[0] <= 550) {
    carServo.write(60);
    testCar.change_speed(50);
  }
  if (sensorValues[0] && sensorValues[1] <= 550) {
    carServo.write(70);
  }
  if (sensorValues[1] <= 550) {
    carServo.write(90);
  }
  if (sensorValues[1] && sensorValues[2] <= 550) {
    carServo.write(105);
  }
  if (sensorValues[2] && sensorValues[3] <= 550) {
    carServo.write(110);
  }
  if (sensorValues[3] <= 550) {
    carServo.write(120);
    testCar.change_speed(50);  
  }
  bool isValidStop = (sensorValues[0] < 100 && sensorValues[3] < 100);
  if (isValidStop) {
    isStop = true;
  }
  if (isStop) {
    testCar.change_speed(0);
    carServo.write(SERVO_CENTER);
  }
}
#include <Servo.h>
#include <QTRSensors.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
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

// int getPosition(QTRSensors &qtr, bool &atFinish) {
//     uint16_t array[SENSOR_COUNT];
//     uint16_t position = qtr.readLineWhite(array);
//     if (array[0] == 0 && array[7] == 0) {
//         atFinish = true;
//     }
//     return position;
// }



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  carServo.attach(SERVO_PIN);
  carServo.write(SERVO_CENTER);

  // configure the sensors
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ A0, A1, A2, A3 }, SENSOR_COUNT);
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
  static bool isStop = false;
  // put your main code here, to run repeatedly:
  // static bool finishDetected = false;
  testCar.run();
  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 3000 (for a white line, use readLineWhite() instead)
  uint16_t position = qtr.readLineWhite(sensorValues);
  // uint16_t new_position = map(position, 0, 3000, 60, 120);
  // degree = new_position;
  // TODO: Find the right angle to make the car manueve
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
    // Serial.println("Car turn right: 60");
    carServo.write(120);
    testCar.change_speed(50);  //
  }
  // delay(45);
  // print the sensor values as numbers from 0 to 1000, where 0 means maximum
  // reflectance and 1000 means minimum reflectance, followed by the line
  // position
  // for (uint8_t i = 0; i < SENSOR_COUNT; i++) {
  //   Serial.print(sensorValues[i]);
  //   Serial.print('\t');
  // }
  // Serial.println(position);
  // double degree = SERVO_CENTER + new_position;  // -30 to 30 degree
  // auto penul = constrain(new_position, 60, 120);

  // int ulti = constrain(map(penul, 60, 120, 1, 6), 1, 6);


  // if (ulti == 1 || ulti == 6) {
  //   testCar.change_speed(45);
  // }

  // if (ulti == 2 || ulti == 5) {
  //   testCar.change_speed(37);
  // }

  // if (ulti == 3 || ulti == 4) {
  //   testCar.change_speed(38);
  // }

  // Serial.println(ulti);

  // // Serial.println(new_position);
  // carServo.write(penul);

  // bool condition1 = (sensorValues[0] > 900 && sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3]);
  // if (condition1) {
  //   isRun = true;
  //   carServo.write(60);
  // }
  // if (isRun) {
  //   testCar.change_speed(42);
  // }
  bool condition2 = (sensorValues[0] < 100 && sensorValues[3] < 100);
  if (condition2) {
    isStop = true;
  }
  if (isStop) {
    testCar.change_speed(0);
    carServo.write(SERVO_CENTER);
  }
  // long distance = us.read_sensor();
  // Serial.print("Distance: ");
  // Serial.print(distance);
  // Serial.println(" cm");

  // delay(50); // Wait for 1 second before the next reading
}

double getTurnDeg(const int position) {
  const double Kp = 0.01221;
  // const double Kp = 0.65;
  const double Ki = 0.0000000;
  //    const double Ki = 0.000007;
  const double Kd = 0.0085;
  const int midPosition = 1500;

  static double previous_error = 50;
  static double integral = 0;
  double derivative = 0;
  double correction = 0;
  int error = 45;
  error = position - midPosition;

  integral += error;
  derivative = error - previous_error;
  correction = Kp * error + Ki * integral + Kd * derivative;
  previous_error = error;
  return correction;
}
// #include "config.h"
// #include <QTRSensors.h>
// #include <Servo.h>
// #include "UltrasonicSensor.h"
// #include <Adafruit_MPU6050.h>
// #include <Adafruit_Sensor.h>
// #include <Wire.h>
// #include "Car.h"

// QTRSensors qtr;
// Servo s1;
// Adafruit_MPU6050 mpu;

// const uint8_t SensorCount = 4;
// uint16_t sensorValues[SensorCount];



// void setup()
// {
//   // Initialize serial communication
//   Serial.begin(9600);
//   delay(500);
//   pinMode(LED_BUILTIN, OUTPUT);

//   s1.attach(13);
//   // configure the sensors
//   qtr.setTypeAnalog();
//   qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3}, SensorCount);
//   qtr.setEmitterPin(2);

//   delay(50);
//   pinMode(LED_BUILTIN, OUTPUT);
//   digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode
//   // analogRead() takes about 0.1 ms on an AVR.
//   // 0.1 ms per sensor * 4 samples per sensor read (default) * 6 sensors
//   // * 10 reads per calibrate() call = ~24 ms per calibrate() call.
//   // Call calibrate() 400 times to make calibration take about 10 seconds.
//   for (uint16_t i = 0; i < 400; i++)
//   {
//     qtr.calibrate();
//   }
//   digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration

//   // print the calibration minimum values measured when emitters were on
//   Serial.begin(9600);
//   for (uint8_t i = 0; i < SensorCount; i++)
//   {
//     Serial.print(qtr.calibrationOn.minimum[i]);
//     Serial.print(' ');
//   }
//   Serial.println();

//   // print the calibration maximum values measured when emitters were on
//   for (uint8_t i = 0; i < SensorCount; i++)
//   {
//     Serial.print(qtr.calibrationOn.maximum[i]);
//     Serial.print(' ');
//   }
//   Serial.println();
//   Serial.println();
//   delay(100);
// }

// void loop()
// {

//   bool condition1 = (sensorValues[0] > 900 && sensorValues[1] > 900 && sensorValues[2] > 900 && sensorValues[3] > 900);
//   bool condition2 = (sensorValues[0] < 200 && sensorValues[1] < 200 && sensorValues[2] < 200 && sensorValues[3] < 200);
//   switch (state)
//   {
//   case CAR_STATE::FOLLOW_LINE:
//     // TODO: Find the right angle to make the car manueve
//     if (sensorValues[0] <= 550)
//     {
//       // Serial.println("Car turn right: 60");
//       s1.write(60);
//       testCar.change_speed(38); //
//     }
//     if (sensorValues[0] && sensorValues[1] <= 550)
//     {
//       // Serial.println("Car turn right: 60");
//       s1.write(70);
//       testCar.change_speed(40); //
//     }
//     if (sensorValues[1] <= 550)
//     {
//       // Serial.println("Car turn right: 60");
//       s1.write(90);
//       testCar.change_speed(40); //
//     }
//     if (sensorValues[1] && sensorValues[2] <= 550)
//     {
//       // Serial.println("Car turn right: 60");
//       s1.write(105);
//       testCar.change_speed(40); //
//     }
//     if (sensorValues[2] && sensorValues[3] <= 550)
//     {
//       // Serial.println("Car turn right: 60");
//       s1.write(110);
//       testCar.change_speed(40); //
//     }
//     if (sensorValues[3] <= 550)
//     {
//       // Serial.println("Car turn right: 60");
//       s1.write(120);
//       testCar.change_speed(45); //
//     }
//     if (condition2 || condition1)
//     {
//       state = CAR_STATE::STOP;
//     }
//     delay(45);
//     break;
//   case CAR_STATE::STOP:
//     testCar.change_speed(0);
//     break;
//   default:
//     state = CAR_STATE::STOP;
//     break;
//   }

//   if (sensorValues[0] > 800 && sensorValues[1] > 800 && sensorValues[2] > 800 && sensorValues[3] > 800){
//     while(true){
//       testCar.change_speed(0);
//     }
//   }

//   delay(54);
// }

// // Function to set or clear a specific bit in the shift register
// void setShiftRegisterBit(int bit, bool value) {
//   if (value) {
//     shiftRegisterState |= (1 << bit);  // Set the bit
//   } else {
//     shiftRegisterState &= ~(1 << bit);  // Clear the bit
//   }
//   updateShiftRegister();  // Update the shift register with the new state
// }

// // Function to shift out the current state to the shift register
// void updateShiftRegister() {
//   digitalWrite(latchPin, LOW);  // Set latch pin low to start

//   // Shift out the state byte (MSB first)
//   for (int i = 7; i >= 0; i--) {
//     digitalWrite(clockPin, LOW);
//     digitalWrite(dataPin, (shiftRegisterState & (1 << i)) ? HIGH : LOW);
//     digitalWrite(clockPin, HIGH);
//   }

//   digitalWrite(latchPin, HIGH);  // Latch the data
// =======
// >>>>>>> 1f8734eeca39aab078ab29577fe08923353a0511
// }


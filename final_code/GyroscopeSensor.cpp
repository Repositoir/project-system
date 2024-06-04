// #include "GyroscopeSensor.h"

// GyroscopeSensor::GyroscopeSensor(){
//   if (!mpu.begin()) {
//     Serial.println("Failed to find MPU6050 chip");
//     while (1) {
//       delay(10);
//     }
//   }

//   mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
//   mpu.setGyroRange(MPU6050_RANGE_500_DEG);
//   mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
// }

// bool GyroscopeSensor::detected_slope(){
//   sensors_event_t a, g, temp;
//   mpu.getEvent(&a, &g, &temp);

//   float ay = a.acceleration.y;

//   if (ay > 2.0) {
//     return false;
//   } else if (ay < -2.0) {
//     return true;
//   }
// }
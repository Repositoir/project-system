#ifndef INCLUDED_GYROSCOPE_SENSOR_H
#define INCLUDED_GYROSCOPE_SENSOR_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

namespace project_system {
    class GyroscopeSensor
    {
    private:
        int sclPin_;
        int sdaPin_;

    public:
        GyroscopeSensor();

        bool detected_slope();
    };
    
}
#endif // INCLUDED_GYROSCOPE_SENSOR_H
#ifndef INCLUDED_ULTRASONIC_SENSOR_H
#define INCLUDED_ULTRASONIC_SENSOR_H

#include "Arduino.h"
namespace project_system
{
    class UltrasonicSensor
    {
    private:
        int echoPin_;
        int trigPin_;
        bool objectDetected_;

    public:
        UltrasonicSensor(int echoPin, int trigPin);
        ~UltrasonicSensor();
        long read_sensor();      // Reads sensor and sets objectDetected_ private member
        bool detected_object();  // Simply returns if object is detected.
        static long microsecondsToCentimeters(long microseconds);
    };
}

#endif // INCLUDED_ULTRASONIC_SENSOR_H

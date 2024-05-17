#ifndef INCLUDED_ULTRASONIC_SENSOR_H
#define INCLUDED_ULTRASONIC_SENSOR_H

#include "Sensor.h"
namespace project_system
{

    class UltrasonicSensor : public Sensor
    {
    private:
        bool objectDetected_;

    public:
        UltrasonicSensor(int sensorPin, bool objectDetected);
        ~UltrasonicSensor();
        int read_sensor_digital(int sensorPin); // Reads sensor and sets objectDetected_ private member
        bool detected_object();                 // Simply returns if object is detected.
    };
}
#endif // INCLUDED_ULTRASONIC_SENSOR_H
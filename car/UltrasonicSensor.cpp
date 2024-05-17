#include "UltrasonicSensor.h"

namespace project_system
{
    UltrasonicSensor::UltrasonicSensor(int sensorPin, bool objectDetected)
        : objectDetected_{false}
    {
        set_sensor_pin(sensorPin);
    }
    UltrasonicSensor::~UltrasonicSensor()
    {
    }

    int UltrasonicSensor::read_sensor_digital(int sensorPin)
    {
        return 0;
    }

    bool UltrasonicSensor::detected_object()
    {
        return false;
    }
}
#include "InfraredSensor.h"

InfraredSensor::InfraredSensor()
{
}

float InfraredSensor::read_sensor()
{
    /// Sensor code in void loop()
}

bool InfraredSensor::detected_line()
{
    return lineDetected_;
}

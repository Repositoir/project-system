#include "InfraredSensor.h"

namespace project_system
{
    InfraredSensor::InfraredSensor()
    {
    }

    float InfraredSensor::read_sensor()
    {
        // TODO: Add sensor code here
    }

    bool InfraredSensor::detected_line()
    {
        return lineDetected_;
    }
}

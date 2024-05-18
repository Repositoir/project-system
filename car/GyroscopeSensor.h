#ifndef INCLUDED_GYROSCOPE_SENSOR_H
#define INCLUDED_GYROSCOPE_SENSOR_H

#include "Sensor.h"

namespace project_system {
    class GyroscopeSensor : Sensor
    {
    private:
        /* data */
    public:
        GyroscopeSensor(/* args */);
        ~GyroscopeSensor();
    };
    
    GyroscopeSensor::GyroscopeSensor(/* args */)
    {
    }
    
    GyroscopeSensor::~GyroscopeSensor()
    {
    }
    
}
#endif // INCLUDED_GYROSCOPE_SENSOR_H
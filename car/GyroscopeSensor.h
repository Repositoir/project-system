#ifndef INCLUDED_GYROSCOPE_SENSOR_H
#define INCLUDED_GYROSCOPE_SENSOR_H

namespace project_system {
    class GyroscopeSensor
    {
    private:
        int sclPin_;
        int sdaPin_;

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
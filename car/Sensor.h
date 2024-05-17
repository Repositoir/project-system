#ifndef INCLUDED_SENSOR_H
#define INCLUDED_SENSOR_H

namespace project_system
{
    class Sensor
    {
    private:
        int sensorPin_;
    public:
        int get_sensor_pin();
        void set_sensor_pin(int sensorPin);
        int read_sensor_digital(int sensorPin);
        float read_sensor_analog(int sensorPin);
    };
}
#endif // INCLUDED_SENSOR_H

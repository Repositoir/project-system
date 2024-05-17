#include "Sensor.h"

namespace project_system
{
  int Sensor::get_sensor_pin()
  {
      return sensorPin_;
  }

  void Sensor::set_sensor_pin(int sensorPin)
  {
    this->sensorPin_ = sensorPin;
  }

  float Sensor::read_sensor_analog(int sensorPin)
  {
    return 0.0f;
  }

  int Sensor::read_sensor_digital(int sensorPin)
  {
    return 0;
  }
}
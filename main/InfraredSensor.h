#ifndef INCLUDED_INFRARED_SENSOR_H
#define INCLUDED_INFRARED_SENSOR_H

class InfraredSensor {
  float sensorValue_;
  bool lineDetected_;
public:
  InfraredSensor();
  float read_sensor();
  bool detected_line();
};

#endif // INCLUDED_INFRARED_SENSOR_H
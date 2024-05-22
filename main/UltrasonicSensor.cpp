#include "UltrasonicSensor.h"
#include "config.h"

// Functions declared in test.ino
extern void setShiftRegisterBit(int bit, bool value);

namespace project_system
{
    UltrasonicSensor::UltrasonicSensor(int echoPin, int trigPin)
        : echoPin_(echoPin), trigPin_(trigPin), objectDetected_(false)
    {
        pinMode(trigPin_, OUTPUT);
        pinMode(echoPin_, INPUT);
    }

    UltrasonicSensor::~UltrasonicSensor()
    {
    }

    // float UltrasonicSensor::read_sensor()
    // {
    //     // Clear the trigger pin
    //     digitalWrite(trigPin_, LOW);
    //     delayMicroseconds(2);

    //     // Send a 10 microsecond pulse to trigger pin
    //     digitalWrite(trigPin_, HIGH);
    //     delayMicroseconds(10);
    //     digitalWrite(trigPin_, LOW);

    //     // Read the echo pin
    //     long duration = pulseIn(echoPin_, HIGH);

    //     // Calculate the distance in centimeters
    //     long distance = microsecondsToCentimeters(duration);

    //     // Update the object detected status
    //     objectDetected_ = (distance < OBJECT_DETECTED_DISTANCE); // Example threshold for object detection

    //     return distance;
    // }
    long UltrasonicSensor::read_sensor()
    {
        // Clear the trigger pin (set bit to LOW)
        setShiftRegisterBit(trigPin_, LOW);
        delayMicroseconds(2);

        // Send a 10 microsecond pulse to the trigger pin (set bit to HIGH)
        setShiftRegisterBit(trigPin_, HIGH);
        delayMicroseconds(10);

        // Clear the trigger pin (set bit to LOW)
        setShiftRegisterBit(trigPin_, LOW);

        // Read the echo pin
        long duration = pulseIn(echoPin_, HIGH);

        // Calculate the distance in centimeters
        long distance = microsecondsToCentimeters(duration);

        // Update the object detected status
        objectDetected_ = (distance < OBJECT_DETECTED_DISTANCE); // Example threshold for object detection

        return distance;
    }

    bool UltrasonicSensor::detected_object()
    {
        return objectDetected_;
    }

    long UltrasonicSensor::microsecondsToCentimeters(long microseconds)
    {
        // Sound travels at 343 meters per second, or 29.1 microseconds per centimeter.
        // The round trip time is twice the distance.
        return microseconds / 29 / 2;
    }
}

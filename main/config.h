#define OBJECT_DETECTED_DISTANCE 15
#define BRAKE 0
#define FORWARD 1
#define REVERSE   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 5
#define SPEED_CTRL 6
#define MOTOR_ENABLE 7
// Define the control pins for the shift register
const int latchPin = 12;  // ST_CP
const int clockPin = 11;  // SH_CP
const int dataPin = 13;   // DS



// Define the bit positions for the trigger and echo pins
const int triggerBit = 0; // Q0 of the shift register
const int echoPin = 8;    // Directly connected to microcontroller pin

#define BRAKE 0
#define FORWARD 1
#define REVERSE   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 5
#define SPEED_CTRL 6
#define MOTOR_ENABLE 7
// // Define the control pins for the shift register
// const int latchPin = 12;  // ST_CP
// const int clockPin = 11;  // SH_CP
// const int dataPin = 13;   // DS

// Define the bit positions for the trigger and echo pins
#define TRIG_PIN 9 // Trigger pin of ultrasonic sensor
#define ECHO_PIN 8 // Echo pin ultrasonic sensor
#define OBJECT_DETECTED_DISTANCE 40
enum CAR_STATE {CALIBRATE, FOLLOW_LINE, OBJECT_DETECTION, RAMP_DETECTION, STOP};

// FOLLOW_LINE 
// - QTR8-A return the value
// - Servo (Axle) - depend on the value of QTR - turn a specific angle 
// - Motor - depend on the value of QTR - change the speed of the car
// - Gyro - keep track the direction of the car
// OBJECT_DETECTION
// - QTR8-A - ignore value of this component until speed == 45 && sensorValues[3] && sensorValues[2] <= 550
// - Motor - speed == 0 -> Servo.write(60) -> speed == 45
// - Gyro -  
// RAMP_DETECTION
// - QTR8-A - ignore value of this component
// - Servo (Axle) -
// - Motor - speed == 0 -> Servo.write(90) -> speed == 80
// - Gyro - detectup_hill, down_hill
// STOP (quiet similar to FOLLOW_LINE need condition here)
// - QTR8-A - return the value
// - Servo (Axle) - depend on the value of QTR - turn a specific angle. After, speed == 0 -> Servo.write(90);
// - Motor - depend on the value of QTR if (all return black -> stop || all return white -> stop)
// - Gyro - check it is ground or not -> yes, stop

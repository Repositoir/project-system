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
#define TRIG_PIN 12 // Trigger pin of ultrasonic sensor
#define ECHO_PIN 11 // Echo pin ultrasonic sensor
#define OBJECT_DETECTED_DISTANCE 30
enum CAR_STATE {CALIBRATE, FOLLOW_LINE, OBJECT_DETECTION, RAMP_DETECTION, STOP};
// Servo
#define SERVO_PIN 13
// QTR
#define QTA_IR_1_PIN A0
#define QTA_IR_2_PIN A1
#define QTA_IR_3_PIN A2
#define QTA_IR_4_PIN A3

#define SERVO_PIN 8
#define SERVO_CENTER 90
#define SENSOR_COUNT 4

// FOLLOW_LINE 
// - QTR8-A return the value
// - Servo (Axle) - depend on the value of QTR - turn a specific angle 
// - Motor - depend on the value of QTR - change the speed of the car
// - Gyro - check if it on the slope or not
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

// Tuning Process
// Proportional Control (Kp):

// Start with Kp = 1.0. If the car oscillates around the line, reduce Kp. If the car responds too slowly, increase Kp gradually until you see consistent tracking.
// Integral Control (Ki):

// With Ki = 0.1, observe if there's any drift or steady-state error. If the car consistently drifts away from the line, increase Ki slightly. If the car starts to oscillate or becomes unstable, reduce Ki.
// Derivative Control (Kd):

// With Kd = 0.5, you should see damping of oscillations. If the car overshoots and oscillates, increase Kd. If the car becomes sluggish, reduce Kd.
// Fine-Tuning Tips
// Adjust one parameter at a time and observe the behavior.
// Make small adjustments (e.g., increments of 0.1 for Kp and Ki, 0.05 for Kd).
// Test the car on a straight and curved line to ensure robustness.
// If the car consistently tracks the line well but oscillates on curves, increase Kd slightly.
// With this approach, you should be able to fine-tune the PID values for your specific setup and achieve reliable line-following performance.

/*
  RULES AND INTRO

  In the code writing process of this project we are going to follow some standard naming conventions and rules

  1. All variable names must be in camel case (for eg. thisIsCamelCase)
  2. All function parameter names must also be in camel case.
  3. All classes or structs names must be a single word that is capitalised.
  4. All private data members must end with an underscore if not a function.
  5. Comment what each function does and specify return types with @returns and params with @params
  6. All global constants and pin definitions must be just below any included libraries, they must be in all capital letters.
  7. All function names must be in 
  
  In this code we want to use a single function already mentioned below of the CAr class which is Car::run(). This will be the only function in the void loop() function.

*/


#define BRAKE 0
#define FORWARD 1
#define REVERSE   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9
#define SPEED_CTRL 6
#define MOTOR_ENABLE A1
#define MOTOR_2 1

class Car{
private:
  int direction_;
  int speed_;
  int angle_;

public:
  Car();
  Car(int direction, int speed);

  // Modifiers
  void change_drive(int dir); // FORWARD or BACKWARD
  void change_speed(int spd);
  void change_direction(short angle); // Axle change


  // Accessors

  int direction();
  int speed();

  void run();
};


class UltraSound {
 bool objectDetected_;
 int sensorValue_;
public:
  UltraSound();
  int read_sensor(); // Reads sensor and sets objectDetected_ private member
  bool detected_object(); // Simply returns if object is detected.
};


class InfraredSensor {
  float sensorValue_;
  bool lineDetected_;
public:
  InfraredSensor();
  float read_sensor();
  bool detected_line();
};


class Gyroscope {
  float sensorValue_;
  bool rampDetcted_;
public:

  Gyroscope();
  float read_sensor();
  bool detected_ramp();
}

// GYRO CLASS

float Gyroscope::read_sensor(){
  /// TODO: add sensor code here
}

bool Gyroscope::detected_ramp(){
  return rampDetected_;
}

/// ULTRASOUND CLASS

int UltraSound::read_sensor(){
  /// TODO: Add sensor code here
}

bool UltraSound::detected_object(){
  return objectDetected_;
}



/// INFRA CLASS

float InfraredSensor::read_sensor(){
  /// TODO: Add sensor code here
}

bool InfraredSensor::detected_line(){
  return lineDetected_;
}



/// CAR CLASS

// Constructors

Car::Car(){
  direction_ = FORWARD;
  speed_ = 0;
}

Car::Car(int direction, int speed){
  direction_ = direction;
  speed_ = speed;
}

// Modifiers

void Car::change_drive(int dir){
  direction_ = dir;
}

void Car::change_speed(int spd){
  speed_ = spd;
}

void Car::change_direction(short angle){
  angle_ = angle;
}

// Accessors

int Car::direction(){
  return direction_;
}

int Car::speed(){
  return speed_;
}

// Run function

void Car::run(){
  UltraSound frontSensor;
  InfraredSensor infra;
  Gyroscope gyro;

  if (frontSensor.detected_object()) speed_ = STOP;

  digitalWrite(MOTOR_ENABLE, HIGH);

  if (direction_ == FORWARD){
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);

    // if (speed_ > 40) speed_ = 40;

    analogWrite(SPEED_CTRL, speed_);
  } else if (direction_ == REVERSE){
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);

    // if (speed_ > 40) speed_ = 40;

    analogWrite(SPEED_CTRL, speed_);
  }

  
}
 
void setup()                         
{

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  // pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(SPEED_CTRL, OUTPUT);

  // pinMode(CURRENT_SEN_1, OUTPUT);
  // pinMode(CURRENT_SEN_2, OUTPUT);  

  pinMode(MOTOR_ENABLE, OUTPUT);

  Serial.begin(9600);              // Initiates the serial to do the monitoring 

}

// Declare classes
Car testCar = {FORWARD, 65};

void loop() 
{
  testCar.run();
}



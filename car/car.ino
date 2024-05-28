#include "config.h"

using namespace project_system;


 
void setup()                         
{

  Serial.begin(9600);

  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);

  // pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(SPEED_CTRL, OUTPUT);

  // pinMode(CURRENT_SEN_1, OUTPUT);
  // pinMode(CURRENT_SEN_2, OUTPUT);  

  pinMode(MOTOR_ENABLE, OUTPUT);

  GyroscopeSensor();

}

// Declare classes
Car testCar = {FORWARD, 65};

void loop() 
{
  testCar.run();
}


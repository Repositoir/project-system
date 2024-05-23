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
#define MOTOR_A2_PIN 2
#define MOTOR_B2_PIN 3
#define SPEED_CTRL 4
#define MOTOR_ENABLE 5
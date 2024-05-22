#include "config.h"

#include "UltrasonicSensor.h"

// using namespace project_system;

// // create a global shift register object
// // parameters: <number of shift registers> (data pin, clock pin, latch pin)
// UltrasonicSensor us(7, 8);

// void setup()
// {
//     Serial.begin(9600);
// }

// void loop()
// {
//     long distance = us.read_sensor();
//     Serial.print("Distance: ");
//     Serial.print(distance);
//     Serial.print(" cm, ");
//     Serial.print("Object detected: ");
//     Serial.println(us.detected_object() ? "true" : "false");
//     delay(500); // Wait for 1 second before the next reading
// }

// Define the control pins for the shift register
const int latchPin = 12;  // ST_CP
const int clockPin = 11;  // SH_CP
const int dataPin = 13;   // DS

// Variable to hold the current state of the shift register
byte shiftRegisterState = 0;

// Define the bit positions for the trigger and echo pins
const int triggerBit = 0; // Q0 of the shift register
const int echoPin = 7;    // Directly connected to microcontroller pin

using namespace project_system;

UltrasonicSensor us(echoPin, triggerBit);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set control pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  // Initialize the shift register to zero
  updateShiftRegister();
}

void loop() {
  long distance = us.read_sensor();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000); // Wait for 1 second before the next reading
}

// Function to set or clear a specific bit in the shift register
void setShiftRegisterBit(int bit, bool value) {
  if (value) {
    shiftRegisterState |= (1 << bit); // Set the bit
  } else {
    shiftRegisterState &= ~(1 << bit); // Clear the bit
  }
  updateShiftRegister(); // Update the shift register with the new state
}

// Function to shift out the current state to the shift register
void updateShiftRegister() {
  digitalWrite(latchPin, LOW); // Set latch pin low to start
  
  // Shift out the state byte (MSB first)
  for (int i = 7; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, (shiftRegisterState & (1 << i)) ? HIGH : LOW);
    digitalWrite(clockPin, HIGH);
  }
  
  digitalWrite(latchPin, HIGH); // Latch the data
}

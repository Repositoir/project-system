#include "config.h"

#include "UltrasonicSensor.h"
#include "Car.h"

// Variable to hold the current state of the shift register
byte shiftRegisterState = 0;


UltrasonicSensor us(echoPin, triggerBit);
// Declare classes
Car testCar = { FORWARD, 40 };

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
  delay(100);  // Wait for 1 second before the next reading
  testCar.run(us);
}

// Function to set or clear a specific bit in the shift register
void setShiftRegisterBit(int bit, bool value) {
  if (value) {
    shiftRegisterState |= (1 << bit);  // Set the bit
  } else {
    shiftRegisterState &= ~(1 << bit);  // Clear the bit
  }
  updateShiftRegister();  // Update the shift register with the new state
}

// Function to shift out the current state to the shift register
void updateShiftRegister() {
  digitalWrite(latchPin, LOW);  // Set latch pin low to start

  // Shift out the state byte (MSB first)
  for (int i = 7; i >= 0; i--) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, (shiftRegisterState & (1 << i)) ? HIGH : LOW);
    digitalWrite(clockPin, HIGH);
  }

  digitalWrite(latchPin, HIGH);  // Latch the data
}

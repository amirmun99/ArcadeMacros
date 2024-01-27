#include "Keyboard.h"

// Define the pins for the buttons
const int buttonPins[] = {2, 3, 4, 5};
const int numberOfButtons = 4;

// Variables to hold the current and previous button states
bool currentButtonStates[numberOfButtons];
bool previousButtonStates[numberOfButtons];

void setup() {
  // Initialize the Keyboard library
  Keyboard.begin();

  // Configure the button pins as inputs
  for (int i = 0; i < numberOfButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    // Initialize the previous states
    previousButtonStates[i] = digitalRead(buttonPins[i]);
  }
}

void loop() {
  // Read the state of the buttons
  for (int i = 0; i < numberOfButtons; i++) {
    currentButtonStates[i] = digitalRead(buttonPins[i]);

    // If the button state changed from HIGH to LOW (button press)
    if (previousButtonStates[i] == HIGH && currentButtonStates[i] == LOW) {
      // Call the function to handle the button press
      handleButtonPress(i);
      // Debounce delay
      delay(50);
    }

    // Update the previous state
    previousButtonStates[i] = currentButtonStates[i];
  }
}

void handleButtonPress(int buttonIndex) {
  // Based on the button pressed, send a different macro
  switch (buttonIndex) {
    case 0:
      // Example: CTRL+ALT+DELETE
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_DELETE);
      delay(100); // Short delay to ensure the key press is registered
      Keyboard.releaseAll(); // Release all keys
      break;
    case 1:
      // Example: Windows Game Bar
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('g');
      delay(100);
      Keyboard.releaseAll();
      break;
    case 2:
      // Example: Custom macro or a single key
      Keyboard.println("Your custom text or command here");
      break;
    case 3:
      // Example: Launch calculator (Windows)
      Keyboard.press(KEY_LEFT_GUI); // Windows Key
      Keyboard.press('r');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.println("calc");
      break;
  }
}

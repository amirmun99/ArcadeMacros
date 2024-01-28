# ArcadeMacros
A simple 4 button macro keypad utilizing arcade style pushbuttons.
![IMG_3910-2](https://github.com/potatoworld/ArcadeMacros/assets/37276609/b9dd44df-40e4-4200-94f2-20c6da19f9d4)

## What is this?

This is a simple 4 button macro pad that runs on an Arduino Pro Micro, the case is 3D printed and the entire project is doable for under $20CAD.

Each button is mappable to a keystroke or combination of keystrokes. by Default, they are mapped to CTRL+ALT+DEL, Windows Calculator, Xbox Game Bar and a string of text.

---

### List of Required Hardware

- Arduino Pro Micro
- 3D Printed case
- 8x 6mm*3mm magnets
- 4 30mm Arcade style push buttons
- 2 Large 1/2in washers (optional)

---

# Printing/Case assembly

The case is avaible in this repo and also on this printables page: https://www.printables.com/model/742282-arcade-button-macro-pad

The case prints in 2 parts, the base has cutouts for both the pro micro as well as 2 washers for weight. The washers arent needed, but might be helpful if your pushbuttons are stiff and require more force to push on. 

The magnets can be superglued into their holes, be careful to not reverse the polarity.

The Pro micro can be hot glued or 3M Taped onto the platform and aligned with the cutout for the USB Port.

---
![IMG_3908](https://github.com/potatoworld/ArcadeMacros/assets/37276609/fea93631-041d-4204-a7bd-30dac002a8c5)

# Wiring

The wiring for this macropad is extremely simple:

Connect each switch to ground.
Connect the other connection of each switch to a GPIO pin, by default: 2, 3, 4, 5.

# Basic Script Install Guide

**NOTE: Depending on your board, the default included Arduino Leonardo or Arduino Micro board libraries may work.** 

Open Arduino IDE, go to File > Preferences (on Windows) or Arduino > Preferences (on Mac).

In the Additional Board Manager URLs field, add the following URL to manage the Pro Micro board definitions:
~~~
https://raw.githubusercontent.com/sparkfun/Arduino_Boards/master/IDE_Board_Manager/package_sparkfun_index.json
~~~

Click OK to close the Preferences window.

Go to Tools > Board > Boards Manager..., search for "SparkFun AVR Boards", and install it.

After installation, select your board by going to Tools > Board and choosing "SparkFun Pro Micro". Make sure to select the correct operating voltage (3.3V or 5V) and processor speed (8MHz or 16MHz) for your board.

Paste the code provided in this repo into a new sketch window.

Select the Correct Port: Go to Tools > Port and select the port that corresponds to your Pro Micro.

Upload the Code: Click the upload button (right arrow icon) in the Arduino IDE. The IDE will compile the sketch and upload it to the Pro Micro. You might see blinking lights on the Pro Micro during the upload process.

# Modifying macros

**Understanding the 'sendMacro' Function**

The 'sendMacro' function is where the macros are defined and sent when a button is pressed. Each case within the switch statement corresponds to a different button press, determined by the 'buttonNumber' parameter.

**Modifying Macros**

To modify a macro, locate the 'sendMacro' function in your code. Inside this function, you'll see a switch statement with cases for each button. Here's the structure you'll be working with:

~~~
cpp
Copy code
void sendMacro(int buttonNumber) {
  switch (buttonNumber) {
    case 0:
      // Macro for button 1
      break;
    case 1:
      // Macro for button 2
      break;
    case 2:
      // Macro for button 3
      break;
    case 3:
      // Macro for button 4
      break;
  }
}
~~~

**Examples of Macros**
1. Sending Text

To send a simple text string when a button is pressed:
~~~
cpp
Copy code
Keyboard.print("Hello, World!");
~~~

2. Opening a Webpage (Combination of Keys)

To open a browser and go to a specific URL (e.g., opening Google), you might simulate pressing the Windows key + R, typing the URL, and then hitting enter. This example is Windows-specific:
~~~
cpp
Copy code
Keyboard.press(KEY_LEFT_GUI); // Windows key
Keyboard.press('r');
Keyboard.releaseAll(); // Release all keys to type the next part
delay(500); // Wait for the Run dialog to open
Keyboard.print("http://www.google.com");
Keyboard.press(KEY_RETURN); // Press Enter
Keyboard.releaseAll();
~~~

3. Media Control

To play/pause media, if your Teensy board and the Keyboard library support media keys:
~~~
cpp
Copy code
Keyboard.press(MEDIA_PLAY_PAUSE);
Keyboard.releaseAll();
~~~

Note: Not all versions of the Keyboard library or Teensy models may support media keys directly. Check your library and board version for compatibility.

4. Complex Macros

For a complex macro, like opening a new email in Outlook:
~~~
cpp
Copy code
Keyboard.press(KEY_LEFT_CTRL); // Ctrl key
Keyboard.press(KEY_LEFT_SHIFT); // Shift key
Keyboard.press('n'); // Assuming 'Ctrl + Shift + N' opens a new email
Keyboard.releaseAll();
~~~

**Adding Delays**

In complex macros, you might need to add delays '(delay(milliseconds);)' between commands to allow the computer to catch up with the input, especially when launching applications or sending a series of commands that the computer needs time to process

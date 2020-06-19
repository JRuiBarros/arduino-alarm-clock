#pragma once
#include "Adafruit_LEDBackpack.h"

// I2C address of the display.  Stick with the default address of 0x70
// unless you've changed the address jumpers on the back of the display.
#define DISPLAY_ADDRESS 0x70

// Extension of the Adafruit 7 segment class to accommodate this project's needs.
class Display : public Adafruit_7segment
{
private:
  // Inserts time values on the display buffer.
  void insertTimeValues(int hour, int minute);

  // Reads brightness sensor and writes buffer to display.
  void writeToDisplay();

public:
  using Adafruit_7segment::Adafruit_7segment;

  // Display a time value, including the alarm LED dots on the left of the screen if needed.
  // A value of -1 hides the respective time field, useful to create a blinking effect.
  void displayTime(int hour, int minute, bool alarm1, bool alarm2);

  // Clears the display, useful for the alarm blinking effect.
  void displayBlank();

  // Display a temperature value on the screen, including the ºC symbol.
  void displayTemperature(float temp);

  // Display a humidity value on the screen, including the % symbol.
  void displayHumidity(float humi);
};

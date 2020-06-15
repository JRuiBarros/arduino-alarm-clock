#include "Display.h"

void Display::displayTime(int hour, int minute, bool alarm1, bool alarm2)
{
  insertTimeValues(hour, minute);

  // Center colon
  int bitValue = 0x02;

  if (alarm1)
  {
    bitValue |= 0x04; // Upper left dot
  }
  if (alarm2)
  {
    bitValue |= 0x08; // Lower left dot
  }

  writeDigitRaw(2, bitValue); // Write the leds values on the buffer.
  writeToDisplay();
}

void Display::insertTimeValues(int hour, int minute)
{
  clear();
  
  if (hour != -1)
  {
    int d1 = hour / 10;
    writeDigitNum(0, d1);

    int d2 = hour % 10;
    writeDigitNum(1, d2);
  }

  if (minute != -1)
  {
    int d3 = minute / 10;
    writeDigitNum(3, d3);

    int d4 = minute % 10;
    writeDigitNum(4, d4);
  }
}

void Display::displayBlank()
{
  clear();
  writeToDisplay();
}

void Display::displayTemperature(float temp)
{
  // Round temperature value to one decimal case
  float rounded = ((float)((int)(temp * 10 + .5))) / 10;

  printFloat(rounded);

  // Write the ºC character
  writeDigitNum(4, 0xC);
  writeDigitRaw(2, 0x10);

  writeToDisplay();
}

void Display::writeToDisplay()
{
  // Read brightess value.
  int val = analogRead(A0);
  // Map brightness to "display class" brightess values.
  val = map(val, 0, 1020, 0, 15);
  setBrightness(val);
  writeDisplay();
}
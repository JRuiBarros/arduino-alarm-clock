#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper() : Adafruit_7segment{}
{
}

void DisplayWrapper::begin()
{
  Adafruit_7segment::begin(DISPLAY_ADDRESS);
}

void DisplayWrapper::displayTime(int hour, int minute, bool alarm1, bool alarm2)
{
  displayHours(hour, minute);

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

  writeDigitRaw(2, bitValue);
  writeDisplay();
}

void DisplayWrapper::displayHours(int hour, int minute)
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

void DisplayWrapper::displayBlank()
{
  clear();
  writeDisplay();
}

void DisplayWrapper::displayTemperature(float temp)
{
  // Round temperature value to one decimal case
  float rounded = ((float)((int)(temp * 10 + .5))) / 10;

  printFloat(rounded);

  // Write the ºC character
  writeDigitNum(4, 0xC);
  writeDigitRaw(2, 0x10);

  writeDisplay();
}

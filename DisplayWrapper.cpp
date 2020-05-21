#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper()
{
  clockDisplay = Adafruit_7segment();
}

void DisplayWrapper::begin()
{
  clockDisplay.begin(DISPLAY_ADDRESS);
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

  clockDisplay.writeDigitRaw(2, bitValue);
  clockDisplay.writeDisplay();
}

void DisplayWrapper::displayHours(int hour, int minute)
{
  clockDisplay.clear();
  
  if (hour != -1)
  {
    int d1 = hour / 10;
    clockDisplay.writeDigitNum(0, d1);

    int d2 = hour % 10;
    clockDisplay.writeDigitNum(1, d2);
  }

  if (minute != -1)
  {
    int d3 = minute / 10;
    clockDisplay.writeDigitNum(3, d3);

    int d4 = minute % 10;
    clockDisplay.writeDigitNum(4, d4);
  }
}

void DisplayWrapper::displayBlank()
{
  clockDisplay.clear();
  clockDisplay.writeDisplay();
}

void DisplayWrapper::displayTemperature(float temp)
{
  // Round temperature value to one decimal case
  float rounded = ((float)((int)(temp * 10 + .5))) / 10;

  clockDisplay.printFloat(rounded);

  // Write the ºC character
  clockDisplay.writeDigitNum(4, 0xC);
  clockDisplay.writeDigitRaw(2, 0x10);

  clockDisplay.writeDisplay();
}

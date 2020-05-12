#include "Alarm1.h"

int Alarm1::pollButtons()
{
    int ret = iMode::pollButtons();

    //TODO This should be on the parent class together with the logic on the CurrentTime.cpp file.
    if (ret != rets[0])
    {
        isBlink = true;
        previousMillis = 0;
    }
    return ret;
}

// TODO This should be on the parent class as well.
void Alarm1::display()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (isBlink)
    {
      m_display.displayTime(m_rtc.getA1Hour(), m_rtc.getA1Minute(), true, false);
      isBlink = false;
    }
    else
    {
      m_display.displayBlank();
      isBlink = true;
    }
  }
}
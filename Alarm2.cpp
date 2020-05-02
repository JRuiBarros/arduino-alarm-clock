#include "Alarm2.h"

int Alarm2::pollButtons()
{
    iMode::pollButtons();

    int ret = 2;
    if (buttons[0].wasReleased())
    {
        ret = 1;
    }
    if (buttons[1].wasReleased())
    {
        ret = 0;
    }
    if (ret != 2)
    {
        isBlink = true;
        previousMillis = 0;
    }
    return ret;
}

void Alarm2::display()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    if (isBlink)
    {
      m_display.displayTime(m_rtc.getA2Hour(), m_rtc.getA2Minute(), false, true);
      isBlink = false;
    }
    else
    {
      m_display.displayBlank();
      isBlink = true;
    }
  }
}
#include "Alarm1.h"

void Alarm1::display()
{
  displayAlarm(m_rtc.getA1Hour(), m_rtc.getA1Minute(), true, false);
}
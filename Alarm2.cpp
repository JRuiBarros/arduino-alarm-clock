#include "Alarm2.h"

void Alarm2::display()
{
  displayAlarm(m_rtc.getA2Hour(), m_rtc.getA2Minute(), false, true);
}
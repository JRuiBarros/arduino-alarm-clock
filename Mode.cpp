#include "Mode.h"

Mode::Mode(int c, int b1, int b2){
	curr = c;
	retB1 = b1;
	retB2 = b2;
}

int Mode::pollButtons(){
  
  buttons.readButtons();
  
  if(curr == 0){
    if(buttons.wasB1LongPressed()){
      m_rtc.toggleAlarm1();
      return curr;
    }
    if(buttons.wasB2LongPressed()){
      m_rtc.toggleAlarm2();
      return curr;
    }
  }
  
  int ret = curr;
	if (buttons.wasB1Released()){
    ret = retB1;
	}
  if (buttons.wasB2Released()){
    ret = retB2;
  }
  if(ret != curr){
    isBlink = true;
    previousMillis = 0;
  }
  return ret;
}

void Mode::display(){
  if(curr == 0){
    displayCurrent();
  }
  else if(curr == 1){
    displayAlarm(m_rtc.getA1Hour(), m_rtc.getA1Minute(), true, false);
  }
   else {
    displayAlarm(m_rtc.getA2Hour(), m_rtc.getA2Minute(), false, true);
  }
}

void Mode::displayCurrent(){
   // get time values
  int hour = m_rtc.getHour();
  int min = m_rtc.getMinute();
  m_display.displayTime(hour, min, m_rtc.isAlarm1(), m_rtc.isAlarm2());
}

void Mode::displayAlarm(int hour, int min, bool alarm1, bool alarm2){
   unsigned long currentMillis = millis();
   if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      if(isBlink){
        m_display.displayTime(hour, min, alarm1, alarm2);
        isBlink = false;
      } else {
        m_display.displayBlank();
        isBlink = true;
      }
  }
}

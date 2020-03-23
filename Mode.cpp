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
    displayAlarm1();
  }
   else {
    displayAlarm2();
  }
}

void Mode::displayCurrent(){
   // get time values
  int hour = m_rtc.getHour();
  int min = m_rtc.getMinute();
  m_display.displayTime(hour, min, m_rtc.isAlarm1(), m_rtc.isAlarm2());
}

void Mode::displayAlarm1(){
  unsigned long currentMillis = millis();
  Serial.println(previousMillis);
  if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      if(isBlink){
        // get time values
        int hour = m_rtc.getA1Hour();
        int min = m_rtc.getA1Minute();
        m_display.displayTime(hour, min, false, true);
        isBlink = false;
      } else {
        m_display.displayBlank();
        isBlink = true;
      }
  }
}

void Mode::displayAlarm2(){
  unsigned long currentMillis = millis();
  Serial.println(previousMillis);
  if (currentMillis - previousMillis >= interval) {
      // save the last time you blinked the LED
      previousMillis = currentMillis;

      if(isBlink){
        // get time values
        int hour = m_rtc.getA2Hour();
        int min = m_rtc.getA2Minute();
        m_display.displayTime(hour, min, true, false);
        isBlink = false;
      } else {
        m_display.displayBlank();
        isBlink = true;
      }
  }
}

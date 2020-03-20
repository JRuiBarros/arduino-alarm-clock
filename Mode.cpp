#include "Mode.h"

Mode::Mode(int c, int b1, int b2){
	curr = c;
	retB1 = b1;
	retB2 = b2;
}

int Mode::pollButtons(){

	if (buttons.wasB1Released()){
//    Serial.println("retb1");
    return retB1;
	}
  if (buttons.wasB2Released()){
//    Serial.println("retb2");
    return retB2;
  }
//  Serial.println("retCurr");
  return curr;
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
  m_display.displayTime(hour, min);
}

void Mode::displayAlarm1(){
   // get time values
  int hour = m_rtc.getA1Hour();
  int min = m_rtc.getA1Minute();
  m_display.displayAlarm1(hour, min);
}

void Mode::displayAlarm2(){
   // get time values
  int hour = m_rtc.getA2Hour();
  int min = m_rtc.getA2Minute();
  m_display.displayAlarm2(hour, min);
}

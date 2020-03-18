#include <SparkFunDS3234RTC.h>
#include "RTCWrapper.h"


RTCWrapper::RTCWrapper(){
  	
  // Initialize library
  rtc.begin(DS13074_CS_PIN);
  
  // Set the time using compiler data
  rtc.autoTime();
}

int RTCWrapper::getHour(){
	return rtc.getHour();
}

int RTCWrapper::getMinute(){
	return rtc.getMinute();
}

int RTCWrapper::getA1Hour(){
  return 10;
}

int RTCWrapper::getA1Minute(){
  return 10;
}

int RTCWrapper::getA2Hour(){
  return 20;
}

int RTCWrapper::getA2Minute(){
  return 20;
}

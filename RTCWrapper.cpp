#include "RTCWrapper.h"

RTCWrapper::RTCWrapper(){
  	
  // Initialize library
  rtc.begin(DS13074_CS_PIN);
  
  // Set the time using compiler data
  rtc.autoTime();

  rtc.setAlarm1(255, 10, 11);
  rtc.setAlarm2(22, 22);
} 

int RTCWrapper::getHour(){
	return rtc.getHour();
}

int RTCWrapper::getMinute(){
	return rtc.getMinute();
}

int RTCWrapper::readRegister(DS3234_registers regVal){
  return BCDtoDEC(rtc.readFromRegister(regVal));
}

int RTCWrapper::getA1Hour(){
  return readRegister(DS3234_registers::DS3234_REGISTER_A1HR);
}

int RTCWrapper::getA1Minute(){
  return readRegister(DS3234_registers::DS3234_REGISTER_A1MIN);
}

int RTCWrapper::getA2Hour(){
  return readRegister(DS3234_registers::DS3234_REGISTER_A2HR);
}

int RTCWrapper::getA2Minute(){
  return readRegister(DS3234_registers::DS3234_REGISTER_A2MIN);
}

// BCDtoDEC -- convert binary-coded decimal (BCD) to decimal
uint8_t RTCWrapper::BCDtoDEC(uint8_t val)
{
  return ( ( val / 0x10) * 10 ) + ( val % 0x10 );
}

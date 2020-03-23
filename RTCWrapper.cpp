#include "RTCWrapper.h"

RTCWrapper::RTCWrapper(){
  	
  // Initialize library
  rtc.begin(DS13074_CS_PIN);
  
  // Set the time using compiler data
  rtc.autoTime();

  rtc.setAlarm1(255, 10, 11);
  rtc.setAlarm2(22, 22);
  rtc.enableAlarmInterrupt(false, false);
} 

void RTCWrapper::toggleAlarm1(){
  if(isAlarm1()){
    int reg = rtc.readFromRegister(DS3234_REGISTER_CONTROL);
    rtc.writeToRegister(DS3234_REGISTER_CONTROL, reg & ~0x01);
    disableINTCN();
  } else {
    rtc.enableAlarmInterrupt(true, false);
  }
}

void RTCWrapper::toggleAlarm2(){
  if(isAlarm2()){
    int reg = rtc.readFromRegister(DS3234_REGISTER_CONTROL);
    rtc.writeToRegister(DS3234_REGISTER_CONTROL, reg & ~(0x01<<1));
    disableINTCN();
  } else {
    rtc.enableAlarmInterrupt(false, true);
  }
}

void RTCWrapper::disableINTCN(){
  if(!isAlarm1() && !isAlarm2()){
    int reg = rtc.readFromRegister(DS3234_REGISTER_CONTROL);
    rtc.writeToRegister(DS3234_REGISTER_CONTROL, reg & ~(0x01<<2));
  }
}

bool RTCWrapper::isAlarm1(){
  return rtc.readFromRegister(DS3234_REGISTER_CONTROL) & 0x01;
}

bool RTCWrapper::isAlarm2(){
  return (rtc.readFromRegister(DS3234_REGISTER_CONTROL)>> 1) & 0x01;
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
  return readRegister(DS3234_REGISTER_A1HR);
}

int RTCWrapper::getA1Minute(){
  return readRegister(DS3234_REGISTER_A1MIN);
}

int RTCWrapper::getA2Hour(){
  return readRegister(DS3234_REGISTER_A2HR);
}

int RTCWrapper::getA2Minute(){
  return readRegister(DS3234_REGISTER_A2MIN);
}

// BCDtoDEC -- convert binary-coded decimal (BCD) to decimal
uint8_t RTCWrapper::BCDtoDEC(uint8_t val)
{
  return ( ( val / 0x10) * 10 ) + ( val % 0x10 );
}

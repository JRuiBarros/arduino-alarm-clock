#include "RTCWrapper.h"

RTCWrapper::RTCWrapper() : DS3234{}
{

  // Initialize library
  begin(DS13074_CS_PIN);

  // Set the time using compiler data
  autoTime();

  setAlarm1(255, 10, 11);
  setAlarm2(22, 22);
}

void RTCWrapper::processHour(bool inc)
{
  int currHour = getHour();
  currHour = processVal(currHour, 24, inc);
  setHour(currHour);
}

void RTCWrapper::processMinute(bool inc)
{
  int currMin = getMinute();
  currMin = processVal(currMin, 60, inc);
  setMinute(currMin);
}

void RTCWrapper::processA1Hour(bool inc)
{
  int currHour = getA1Hour();
  currHour = processVal(currHour, 24, inc);
  writeRegister(DS3234_REGISTER_A1HR, currHour);
}

void RTCWrapper::processA1Minute(bool inc)
{
  int currMin = getA1Minute();
  currMin = processVal(currMin, 60, inc);
  writeRegister(DS3234_REGISTER_A1MIN, currMin);
}

void RTCWrapper::processA2Hour(bool inc)
{
  int currHour = getA2Hour();
  currHour = processVal(currHour, 24, inc);
  writeRegister(DS3234_REGISTER_A2HR, currHour);
}

void RTCWrapper::processA2Minute(bool inc)
{
  int currMin = getA2Minute();
  currMin = processVal(currMin, 60, inc);
  writeRegister(DS3234_REGISTER_A2MIN, currMin);
}

int RTCWrapper::processVal(int val, int max, bool inc)
{
  if (inc)
  {
    val = val == max - 1 ? 0 : val + 1;
  }
  else
  {
    val = val == 0 ? max - 1 : val - 1;
  }
  return val;
}

void RTCWrapper::toggleAlarm1()
{
  if (isAlarm1())
  {
    int reg = readFromRegister(DS3234_REGISTER_CONTROL);
    writeToRegister(DS3234_REGISTER_CONTROL, reg & ~0x01);
    disableINTCN();
  }
  else
  {
    enableAlarmInterrupt(true, false);
  }
}

void RTCWrapper::toggleAlarm2()
{
  if (isAlarm2())
  {
    int reg = readFromRegister(DS3234_REGISTER_CONTROL);
    writeToRegister(DS3234_REGISTER_CONTROL, reg & ~(0x01 << 1));
    disableINTCN();
  }
  else
  {
    enableAlarmInterrupt(false, true);
  }
}

void RTCWrapper::disableINTCN()
{
  if (!isAlarm1() && !isAlarm2())
  {
    int reg = readFromRegister(DS3234_REGISTER_CONTROL);
    writeToRegister(DS3234_REGISTER_CONTROL, reg & ~(0x01 << 2));
  }
}

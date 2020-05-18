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

void RTCWrapper::processTime(DS3234_registers reg, bool inc, int max)
{
  int val = readRegister(reg);
  if (inc)
  {
    val = val == max - 1 ? 0 : val + 1;
  }
  else
  {
    val = val == 0 ? max - 1 : val - 1;
  }
  writeRegister(reg, val);
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

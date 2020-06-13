#include "RTCWrapper.h"

RTCWrapper::RTCWrapper() : DS3234{}
{

  // Initialize library
  begin(DS13074_CS_PIN);

  // Set the time using compiler data
  autoTime();

  setAlarm1(0, 50, 15);
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

void RTCWrapper::toggleAlarm(int mask)
{
    int reg = readFromRegister(DS3234_REGISTER_CONTROL);
    writeToRegister(DS3234_REGISTER_CONTROL, reg ^ mask);
    //clearAlarm(mask);
}

// void RTCWrapper::clearAlarm(int mask)
// {
//     int reg = readFromRegister(DS3234_REGISTER_STATUS);
//     writeToRegister(DS3234_REGISTER_STATUS, reg & ~mask);
// }
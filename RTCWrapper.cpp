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

// void RTCWrapper::processHour(int mode, bool inc)
// {

//   int currHour;

//   switch (mode)
//   {
//   case 0:
//     currHour = rtc.getHour();
//     currHour = processVal(currHour, 24, inc);
//     rtc.setHour(currHour);
//     break;
//   case 1:
//     currHour = getA1Hour();
//     currHour = processVal(currHour, 24, inc);
//     writeRegister(DS3234_REGISTER_A1HR, currHour);
//     break;
//   case 2:
//     currHour = getA2Hour();
//     currHour = processVal(currHour, 24, inc);
//     writeRegister(DS3234_REGISTER_A2HR, currHour);
//     break;
//   }
// }

// void RTCWrapper::processMinute(int mode, bool inc)
// {

//   int currHour;

//   switch (mode)
//   {
//   case 0:
//     currHour = rtc.getMinute();
//     currHour = processVal(currHour, 60, inc);
//     rtc.setMinute(currHour);
//     break;
//   case 1:
//     currHour = getA1Minute();
//     currHour = processVal(currHour, 60, inc);
//     writeRegister(DS3234_REGISTER_A1MIN, currHour);
//     break;
//   case 2:
//     currHour = getA2Minute();
//     currHour = processVal(currHour, 60, inc);
//     writeRegister(DS3234_REGISTER_A2MIN, currHour);
//     break;
//   }
// }

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

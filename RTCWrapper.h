#pragma once
#include <SparkFunDS3234RTC.h>
#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin

class RTCWrapper // Extend here
{
private:
  uint8_t BCDtoDEC(uint8_t val);
  uint8_t DECtoBCD(uint8_t val);
  int readRegister(DS3234_registers regVal);
  void writeRegister(DS3234_registers regVal, uint8_t data);
  void disableINTCN();
  //TODO Change this
  int processVal(int val, int max, bool inc);

public:
  //TODO delete this
  RTCWrapper();
  //TODO Change this
  void processHour(int mode, bool inc);
  //TODO Change this
  void processMinute(int mode, bool inc);
  //TODO Delete this
  int getHour();
  //TODO Delete this
  int getMinute();
  int getA1Hour();
  int getA1Minute();
  int getA2Hour();
  int getA2Minute();
  bool isAlarm1();
  bool isAlarm2();
  void toggleAlarm1();
  void toggleAlarm2();
  void processHour(bool inc);
  void processMinute(bool inc);
};

#pragma once
#include <SparkFunDS3234RTC.h>
#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin

class RTCWrapper : public DS3234
{
private:
  
  // Copied from the parent class source code as they are private functions there
  uint8_t BCDtoDEC(uint8_t val) { return ((val / 0x10) * 10) + (val % 0x10); }
  uint8_t DECtoBCD(uint8_t val) { return ((val / 10) * 0x10) + (val % 10); }
  
  int readRegister(DS3234_registers regVal) { return BCDtoDEC(readFromRegister(regVal)); }
  void writeRegister(DS3234_registers regVal, uint8_t data) { writeToRegister(regVal, DECtoBCD(data)); }

  void disableINTCN();
  int processVal(int val, int max, bool inc);

public:
  RTCWrapper();

  int getA1Hour() { return readRegister(DS3234_REGISTER_A1HR); }
  int getA1Minute() { return readRegister(DS3234_REGISTER_A1MIN); }
  int getA2Hour() { return readRegister(DS3234_REGISTER_A2HR); }
  int getA2Minute() { return readRegister(DS3234_REGISTER_A2MIN); }

  bool isAlarm1() { return readFromRegister(DS3234_REGISTER_CONTROL) & 0x01; }
  bool isAlarm2() { return (readFromRegister(DS3234_REGISTER_CONTROL) >> 1) & 0x01; }

  void toggleAlarm1();
  void toggleAlarm2();

  void processHour(bool inc);
  void processMinute(bool inc);
  
  void processA1Hour(bool inc);
  void processA1Minute(bool inc);

  void processA2Hour(bool inc);
  void processA2Minute(bool inc);
};

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

  void processTime(DS3234_registers reg, bool inc, int max);
  void toggleAlarm(int mask);
  // void clearAlarm(int mask);

public:
  RTCWrapper();

  int getA1Hour() { return readRegister(DS3234_REGISTER_A1HR); }
  int getA1Minute() { return readRegister(DS3234_REGISTER_A1MIN); }
  int getA2Hour() { return readRegister(DS3234_REGISTER_A2HR); }
  int getA2Minute() { return readRegister(DS3234_REGISTER_A2MIN); }

  // Read alarm bits from the control register to check alarm status.
  bool isAlarm1() { return readFromRegister(DS3234_REGISTER_CONTROL) & 0x01; }
  bool isAlarm2() { return (readFromRegister(DS3234_REGISTER_CONTROL) >> 1) & 0x01; }

  void toggleAlarm1() { toggleAlarm(1); } // Toggle first bit of the control register and clear the alarm.
  void toggleAlarm2() { toggleAlarm(2); } // Toggle second bit of the control register and clear the alarm.

  // void clearAlarm1() { clearAlarm(1); } // Clear first bit of the status register.
  // void clearAlarm2() { clearAlarm(2); } // Clear second bit of the status register.

  void processHour(bool inc) { processTime(DS3234_REGISTER_HOURS, inc, 24); }
  void processMinute(bool inc) { processTime(DS3234_REGISTER_MINUTES, inc, 60); }

  void processA1Hour(bool inc) { processTime(DS3234_REGISTER_A1HR, inc, 24); }
  void processA1Minute(bool inc) { processTime(DS3234_REGISTER_A1MIN, inc, 60); }

  void processA2Hour(bool inc) { processTime(DS3234_REGISTER_A2HR, inc, 24); }
  void processA2Minute(bool inc) { processTime(DS3234_REGISTER_A2MIN, inc, 60); }
};

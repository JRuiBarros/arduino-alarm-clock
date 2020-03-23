#pragma once
#include <SparkFunDS3234RTC.h>
#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin

class RTCWrapper {
  private:
    uint8_t BCDtoDEC(uint8_t val);
    int readRegister(DS3234_registers regVal);
    void disableINTCN();
	public:
		RTCWrapper();
		int getHour();
		int getMinute();
    int getA1Hour();
    int getA1Minute();
    int getA2Hour();
    int getA2Minute();
    bool isAlarm1();
    bool isAlarm2();
    void toggleAlarm1();
    void toggleAlarm2();
};

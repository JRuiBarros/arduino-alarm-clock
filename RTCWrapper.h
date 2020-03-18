#pragma once
#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin

class RTCWrapper {
	public:
		RTCWrapper();
		int getHour();
		int getMinute();
    int getA1Hour();
    int getA1Minute();
    int getA2Hour();
    int getA2Minute();
};

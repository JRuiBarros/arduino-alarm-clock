#pragma once
#include "Adafruit_LEDBackpack.h"

// I2C address of the display.  Stick with the default address of 0x70
// unless you've changed the address jumpers on the back of the display.
#define DISPLAY_ADDRESS   0x70

class DisplayWrapper {
	private:
    Adafruit_7segment clockDisplay;
	public:
		DisplayWrapper();
    void begin();
    void displayAlarm1(int hour, int minute);
    void displayAlarm2(int hour, int minute);
		void displayTime(int hour, int minute);
    void displayHours(int hour, int minute);

};

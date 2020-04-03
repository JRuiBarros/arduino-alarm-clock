#pragma once
#include "Buttons.h"
#include "DisplayWrapper.h"
#include "RTCWrapper.h"

class Mode {
	private:
    void displayCurrent();
    void displayAlarm(int hour, int min, bool alarm1, bool alarm2);
	  boolean isBlink = true;
	  // Generally, you should use "unsigned long" for variables that hold time  
    // The value will quickly become too large for an int to store
    unsigned long previousMillis = 0;        // will store last time LED was updated
    // constants won't change:
    long interval = 500;           // interval at which to blink (milliseconds)
	public:
 		
		static RTCWrapper m_rtc;
		static DisplayWrapper m_display;
		static Buttons buttons;
    
    int curr;
    int retB1;
    int retB2;

		Mode(int c, int b1, int b2);
		int pollButtons();
		void display();
};

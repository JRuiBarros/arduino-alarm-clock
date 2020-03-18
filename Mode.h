#pragma once
#include "Buttons.h"
#include "DisplayWrapper.h"
#include "RTCWrapper.h"

class Mode {
	private:
    void displayCurrent();
    void displayAlarm1();
    void displayAlarm2();
	
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

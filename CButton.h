#pragma once
#include <JC_Button.h> // https://github.com/JChristensen/JC_Button

class CButton: public Button
{
    private:
        unsigned long LONG_PRESS = 1000; // we define a "long press" to be 1000 milliseconds.
	    bool inLongPress = false;
    public:
        CButton(int p);
        bool wasReleased();
        bool wasLongPressed();
};
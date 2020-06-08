#pragma once
#include <JC_Button.h> // https://github.com/JChristensen/JC_Button

#define LONG_PRESS  1000 // we define a "long press" to be 1000 milliseconds.

class CButton: public Button
{
    private:
	    bool inLongPress = false;
    public:
        CButton(int p);
        bool wasReleased();
        bool wasLongPressed();
};
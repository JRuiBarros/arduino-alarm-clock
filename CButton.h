#pragma once
#include <JC_Button.h> // https://github.com/JChristensen/JC_Button

#define LONG_PRESS  1000 // we define a "long press" to be 1000 milliseconds.

class CButton: public Button
{
    private:
	    bool inLongPress = false; // Boolean indicating if the button is currently in a long press position.
    public:
        using Button::Button;
        
        // Override of the function with the same name, ignores releases of buttons that have been long pressed first.
        bool wasReleased();

        // Checks if the button has entered a long press status, but only returns true on the first sucessful call. 
        // All subsequent calls on a long pressed button return false.
        bool wasLongPressed();
};
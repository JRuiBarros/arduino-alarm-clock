#pragma once
#include "CButton.h"
#include "Display.h"
#include "Timer.h"

// Abstract class representing a "display mode" of the alarm clock.
class BaseMode
{
protected:
    int *rets; // Int array containing the "display modes" corresponding to each respective button position, used to change between the modes using the buttons.
    int m_setMode = 0; // Setting mode of the "display mode", 0 = no setting, 1 = setting hour, 2 = setting minutes.

    // Executes the read() function in all the buttons.
    void readButtons();

    static Timer displayTimer; // Timer responsible for the display blinking effect.
    static Display m_display; // 7 segment display of the alarm clock.
    static CButton buttons[]; // All the buttons used by the alarm clock.

public:
    BaseMode(int p_rets[]);
    virtual int pollButtons();
    virtual void display() = 0;

    // Starts up the buttons and the display components.
    static void begin();
};
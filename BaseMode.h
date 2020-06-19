#pragma once
#include "CButton.h"
#include "Display.h"
#include "Timer.h"
#include "RTC.h"

// Abstract class representing a "display mode" of the alarm clock.
class BaseMode
{
protected:
    int *rets; // Int array containing the "display modes" corresponding to each respective button position, used to change between the modes using the buttons.

    // Executes the read() function in all the buttons.
    void readButtons();

    static Timer displayTimer; // Timer responsible for the display blinking effect.
    static Display m_display; // 7 segment display of the alarm clock.
    static CButton buttons[]; // All the buttons used by the alarm clock.

    static RTC m_rtc; // It is in this class so the alarm can be cleared from any mode.
public:
    BaseMode(int p_rets[]);

    // Polls all the buttons and returns an int representing the "current" display mode to be displayed.
    virtual int pollButtons();

    // Display the current display mode.
    virtual void display() = 0;

    // Starts up the buttons and the display components.
    static void begin();
};
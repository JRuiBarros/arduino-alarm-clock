#pragma once
#include "CButton.h"
#include "Display.h"
#include "Timer.h"
#include "RTC.h"
#include <Adafruit_BME280.h>

// Abstract class representing a "display mode" of the alarm clock.
class BaseMode
{
protected:
    int *rets; // Int array containing the "display modes" corresponding to each respective button position, used to change between the modes using the buttons.

    // Executes the read() function in all the buttons.
    void readButtons();
    
    // Polls the buttons without reading them first.
    int pollWithoutRead();

    static Timer displayTimer; // Timer responsible for the display blinking effect.
    static Display m_display; // 7 segment display of the alarm clock.
    static CButton buttons[]; // All the buttons used by the alarm clock.

    static RTC m_rtc; // It is in this class so the alarm can be cleared from any mode.
    static Adafruit_BME280 bme; // Since there are two modes that use this sensor it is here to avoid too much abstraction.

public:
    BaseMode(int p_rets[]);

    // Polls all the buttons and returns an int representing the "current" display mode to be displayed.
    virtual int pollButtons();

    // Display the current display mode.
    virtual void display() = 0;

    // Starts up the buttons, display and the temp/humidity sensor.
    static void begin();
};
#pragma once
#include "CButton.h"
#include "DisplayWrapper.h"

class iMode
{
private:
    // constants won't change:
    static const long interval = 500; // interval at which to blink (milliseconds)

    // Generally, you should use "unsigned long" for variables that hold time
    // The value will quickly become too large for an int to store
    static unsigned long previousMillis; // will store last time LED was updated

    static boolean isDisplaying; // Starting with false so the first call to checkTimerToDisplay() will return true

protected:
    int *rets;
    void readButtons();
    int m_setMode = 0;

    static boolean checkTimerToDisplay();
    static void resetTimer();
    static DisplayWrapper m_display;
    static CButton buttons[];

public:
    iMode(int p_rets[]);
    virtual int pollButtons();
    virtual void display() = 0;
    static void begin();
};
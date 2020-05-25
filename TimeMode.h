#pragma once
#include "iMode.h"
#include "RTCWrapper.h"

class TimeMode : public iMode
{
public:
    using iMode::iMode;
    static RTCWrapper m_rtc;

    virtual int pollButtons();
    virtual void display();

private:
    boolean checkTimer();
    void resetTimer()
    {
        previousMillis = 0;
        isBlink = true;
    }
    int m_setMode = 0;

    // Generally, you should use "unsigned long" for variables that hold time
    // The value will quickly become too large for an int to store
    unsigned long previousMillis = 0; // will store last time LED was updated

    boolean isBlink = true;

    // constants won't change:
    long interval = 500; // interval at which to blink (milliseconds)

    virtual bool hook() { return false; }

    virtual void decHour() = 0;
    virtual void decMin() = 0;
    virtual void incHour() = 0;
    virtual void incMin() = 0;
    virtual void longPress1() = 0;
    virtual void longPress2() = 0;
    virtual int getHour() = 0;
    virtual int getMin() = 0;
    virtual bool getA1() = 0;
    virtual bool getA2() = 0;
};
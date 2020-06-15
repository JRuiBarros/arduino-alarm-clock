#pragma once
#include "iMode.h"
#include "RTC.h"

class TimeMode : public iMode
{
public:
    using iMode::iMode;

    virtual int pollButtons();
    virtual void display();
protected:
    static RTC m_rtc; // TODO move this to the iMode class so the alarm can be cleared from any mode.
private:
    static Timer setTimer;

    virtual bool isAlarm() { return true; }
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
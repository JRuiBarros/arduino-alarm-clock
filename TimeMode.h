#pragma once
#include "BaseMode.h"
#include "RTC.h"

// Abstract class representing the modes that use time values from the clock module.
class TimeMode : public BaseMode
{
public:
    using BaseMode::BaseMode;

    int pollButtons();
    void display();

protected:
    static RTC m_rtc; // TODO move this to the iMode class so the alarm can be cleared from any mode.
private:
    int m_setMode = 0;     // Setting mode of the "time mode", 0 = no setting, 1 = setting hour, 2 = setting minutes.
    static Timer setTimer; // Timer used to create the long press time setting effect.

    // Checks if time mode is an alarm.
    virtual bool isAlarm() { return true; }

    // Increase or decrease the current time values.
    virtual void decHour() = 0;
    virtual void decMin() = 0;
    virtual void incHour() = 0;
    virtual void incMin() = 0;

    // These functions represent the behaviour of the long press of the first two alarm buttons during setMode = 0;
    virtual void longPress1() = 0;
    virtual void longPress2() = 0;

    // Get the current time values and led status.
    virtual int getHour() = 0;
    virtual int getMin() = 0;
    virtual bool getA1() = 0;
    virtual bool getA2() = 0;
};
#pragma once
#include "TimeMode.h"

class CurrentTime : public TimeMode
{
public:
    using TimeMode::TimeMode;
    virtual void display();

private:
    virtual bool hook() { return true; }

    virtual void decHour() { m_rtc.processHour(false); }
    virtual void decMin() { m_rtc.processMinute(false); }
    virtual void incHour() { m_rtc.processHour(true); }
    virtual void incMin() { m_rtc.processMinute(true); }
    virtual void longPress1() { m_rtc.toggleAlarm1(); }
    virtual void longPress2() { m_rtc.toggleAlarm2(); }
};
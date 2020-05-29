#pragma once
#include "TimeMode.h"

class CurrentTime : public TimeMode
{
public:
    using TimeMode::TimeMode;

private:
    virtual bool isAlarm() { return false; }

    virtual void decHour() { m_rtc.processHour(false); }
    virtual void decMin() { m_rtc.processMinute(false); }
    virtual void incHour() { m_rtc.processHour(true); }
    virtual void incMin() { m_rtc.processMinute(true); }
    virtual void longPress1() { m_rtc.toggleAlarm1(); }
    virtual void longPress2() { m_rtc.toggleAlarm2(); }
    virtual int getHour() { return m_rtc.getHour(); }
    virtual int getMin() { return m_rtc.getMinute(); }
    virtual bool getA1() { return m_rtc.isAlarm1(); }
    virtual bool getA2() { return m_rtc.isAlarm2(); }
};
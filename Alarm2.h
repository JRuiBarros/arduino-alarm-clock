#pragma once
#include "TimeMode.h"

class Alarm2 : public TimeMode
{
public:
    using TimeMode::TimeMode;

private:
    virtual void decHour(){m_rtc.processA2Hour(false);}
    virtual void decMin(){m_rtc.processA2Minute(false);}
    virtual void incHour(){m_rtc.processA2Hour(true);}
    virtual void incMin(){m_rtc.processA2Minute(true);}
    virtual void longPress1(){}
    virtual void longPress2(){}
    virtual int getHour() { m_rtc.getA2Hour(); }
    virtual int getMin() { m_rtc.getA2Minute(); }
    virtual bool getA1() { return false; }
    virtual bool getA2() { return true; }
};
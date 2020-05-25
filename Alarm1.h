#pragma once
#include "TimeMode.h"

class Alarm1 : public TimeMode
{
public:
    using TimeMode::TimeMode;

private:
    virtual void decHour(){m_rtc.processA1Hour(false);}
    virtual void decMin(){m_rtc.processA1Minute(false);}
    virtual void incHour(){m_rtc.processA1Hour(true);}
    virtual void incMin(){m_rtc.processA1Minute(true);}
    virtual void longPress1(){}
    virtual void longPress2(){}
    virtual int getHour() { m_rtc.getA1Hour(); }
    virtual int getMin() { m_rtc.getA1Minute(); }
    virtual bool getA1() { return true; }
    virtual bool getA2() { return false; }
};
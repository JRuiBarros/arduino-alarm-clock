#pragma once
#include "TimeMode.h"

class Alarm2 : public TimeMode
{
public:
    using TimeMode::TimeMode;
    virtual void display();

private:
    virtual void decHour(){m_rtc.processA2Hour(false);}
    virtual void decMin(){m_rtc.processA2Minute(false);}
    virtual void incHour(){m_rtc.processA2Hour(true);}
    virtual void incMin(){m_rtc.processA2Minute(true);}
    virtual void longPress1(){}
    virtual void longPress2(){}
};
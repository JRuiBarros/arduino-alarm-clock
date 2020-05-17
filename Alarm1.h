#pragma once
#include "TimeMode.h"

class Alarm1 : public TimeMode
{
public:
    using TimeMode::TimeMode;
    virtual void display();

private:
    virtual void decHour(){m_rtc.processA1Hour(false);}
    virtual void decMin(){m_rtc.processA1Minute(false);}
    virtual void incHour(){m_rtc.processA1Hour(true);}
    virtual void incMin(){m_rtc.processA1Minute(true);}
    virtual void longPress1(){}
    virtual void longPress2(){}
};
#pragma once
#include "TimeMode.h"

class Alarm1 : public TimeMode
{
public:
    using TimeMode::TimeMode;
    virtual void display();

private:
    virtual void decHour(){}
    virtual void decMin(){}
    virtual void incHour(){}
    virtual void incMin(){}
    virtual void longPress1(){}
    virtual void longPress2(){}
};
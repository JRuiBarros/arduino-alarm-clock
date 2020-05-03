#pragma once
#include "TimeMode.h"

class Alarm2: public TimeMode
{
    public:
        using TimeMode::TimeMode;
        virtual int pollButtons();
        virtual void display();
};
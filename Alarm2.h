#pragma once
#include "TimeMode.h"

class Alarm2: public TimeMode
{
    public:
        virtual int pollButtons();
        virtual void display();
};
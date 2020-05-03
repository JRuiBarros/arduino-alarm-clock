#pragma once
#include "TimeMode.h"

class CurrentTime: public TimeMode
{
    public:
        using TimeMode::TimeMode;
        virtual int pollButtons();
        virtual void display();
};
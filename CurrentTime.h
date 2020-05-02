#pragma once
#include "TimeMode.h"

class CurrentTime: public TimeMode
{
    public:
        virtual int pollButtons();
        virtual void display();
};
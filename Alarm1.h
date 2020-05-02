#pragma once
#include "TimeMode.h"

class Alarm1: public TimeMode
{
    public:
        virtual int pollButtons();
        virtual void display();
};
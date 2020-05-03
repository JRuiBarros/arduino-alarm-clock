#pragma once
#include "iMode.h"
#include "RTCWrapper.h"

class TimeMode: public iMode
{
    public:
        using iMode::iMode;
        static RTCWrapper m_rtc;
    protected:
        // Generally, you should use "unsigned long" for variables that hold time
        // The value will quickly become too large for an int to store
        unsigned long previousMillis = 0; // will store last time LED was updated
       	
        boolean isBlink = true;
        
        // constants won't change:
        long interval = 500; // interval at which to blink (milliseconds)
        
        // virtual void lel() = 0;
};
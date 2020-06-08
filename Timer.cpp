#include "Timer.h"

Timer::Timer(long p_interval)
{
    interval = p_interval;
}

bool Timer::check()
{
    unsigned long currentMillis = millis();
    if (currentMillis - prevMillis >= interval)
    {
        // save the last time you blinked the LED
        prevMillis = currentMillis;
        on = !on;
    }
    return on;
}

void Timer::reset(bool p_on = false)
{
    prevMillis = 0;
    on = p_on;
}
#pragma once
#include <Arduino.h>

class Timer
{
private:
    long interval; // interval at which to blink (milliseconds)

    // Generally, you should use "unsigned long" for variables that hold time
    // The value will quickly become too large for an int to store
    unsigned long prevMillis = 0; // will store last time LED was updated

    bool on = false; // Starting with false so the first call to checkTimerToDisplay() will return true

public:
    Timer(long p_interval);
    bool check();
    void reset(bool p_on = false);
};
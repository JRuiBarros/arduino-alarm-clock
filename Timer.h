#pragma once
#include <Arduino.h> // needed to call millis() function

// Class to simulate an asyncronous delay() call used to create for example a blinking effect.
class Timer
{
private:
    long interval; // interval at which to blink (milliseconds)

    // Generally, you should use "unsigned long" for variables that hold time
    // The value will quickly become too large for an int to store
    unsigned long prevMillis = 0; // will store last time LED was updated

    bool on = false; // Starting with false so the first call to check() will return true

public:
    Timer(long p_interval);

    // Checks if timer is on or off, first call by default should return true.
    // Can be used to check if it is time to display or not for the blinking effect.
    bool check();

    // Resets the timer, prevMillis goes back to zero and by default "on" goes to false.
    void reset(bool p_on = false);
};
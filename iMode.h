#pragma once
#include "CButton.h"
#include "DisplayWrapper.h"

class iMode
{
protected:
    int *rets;
    void readButtons();

    boolean checkTimer();
    void resetTimer();
    int m_setMode = 0;

    // Generally, you should use "unsigned long" for variables that hold time
    // The value will quickly become too large for an int to store
    unsigned long previousMillis = 0; // will store last time LED was updated

    boolean isBlink = true;

    // constants won't change:
    long interval = 500; // interval at which to blink (milliseconds)
public:
    static DisplayWrapper m_display;
    static CButton buttons[];

    iMode(int p_rets[]);
    virtual int pollButtons();
    virtual void display() = 0;
    static void beginButtons();
};
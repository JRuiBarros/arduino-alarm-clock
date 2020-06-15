#pragma once
#include "CButton.h"
#include "Display.h"
#include "Timer.h"

class iMode
{
protected:
    int *rets;
    void readButtons();
    int m_setMode = 0;

    static Timer displayTimer;
    static Display m_display;
    static CButton buttons[];

public:
    iMode(int p_rets[]);
    virtual int pollButtons();
    virtual void display() = 0;

    // Starts up the buttons and the display components.
    static void begin();
};
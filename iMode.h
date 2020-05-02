#pragma once
#include "CButton.h"
#include "DisplayWrapper.h"

class iMode
{
    public:
        static DisplayWrapper m_display;
	    static CButton buttons[];
        virtual int pollButtons();
        virtual void display() = 0;
        static void beginButtons();
};
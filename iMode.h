#pragma once
#include "CButton.h"
#include "DisplayWrapper.h"

class iMode
{
    protected:
        int *rets;
        void readButtons();
    public:
        static DisplayWrapper m_display;
	    static CButton buttons[];
        
        iMode(int p_rets[]);
        virtual int pollButtons();
        virtual void display() = 0;
        static void beginButtons();

};
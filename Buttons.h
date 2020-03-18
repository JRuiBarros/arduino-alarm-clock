#pragma once
#include <JC_Button.h>              // https://github.com/JChristensen/JC_Button

class Buttons {
	private:
		Button b1;
		Button b2;
	public:
    Buttons(int p1, int p2);
    
		boolean wasB1Released();
		boolean wasB2Released();
};

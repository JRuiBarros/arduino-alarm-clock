#pragma once
#include <JC_Button.h> // https://github.com/JChristensen/JC_Button

class Buttons
{
private:
	Button b1;
	Button b2;
	unsigned long LONG_PRESS = 1000; // we define a "long press" to be 1000 milliseconds.
	bool inLongPress = false;
public:
	Buttons(int p1, int p2);
	void readButtons();
	boolean wasB1Released();
	boolean wasB2Released();
	boolean wasB1LongPressed();
	boolean wasB2LongPressed();
};

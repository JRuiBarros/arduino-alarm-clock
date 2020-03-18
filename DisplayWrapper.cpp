#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper(){
	clockDisplay = Adafruit_7segment();
}

void DisplayWrapper::begin(){
  clockDisplay.begin(DISPLAY_ADDRESS);
}

void DisplayWrapper::displayTime(int hour, int minute){
	int displayValue = hour * 100 + minute;
 	clockDisplay.print(displayValue, DEC);
  clockDisplay.drawColon(true);
  clockDisplay.writeDisplay();
}

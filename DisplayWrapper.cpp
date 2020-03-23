#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper(){
	clockDisplay = Adafruit_7segment();
}

void DisplayWrapper::begin(){
  clockDisplay.begin(DISPLAY_ADDRESS);
}

void DisplayWrapper::displayTime(int hour, int minute, bool alarm1, bool alarm2){
  displayHours(hour, minute);
  if(alarm1 && alarm2){
    clockDisplay.drawColon(true);
  }
  else if(alarm1){
    clockDisplay.writeDigitRaw(2, 0x04);
  }
  else if(alarm2){
    clockDisplay.writeDigitRaw(2, 0x08);
  }
  clockDisplay.writeDisplay();
}

void DisplayWrapper::displayHours(int hour, int minute){
	int displayValue = hour * 100 + minute;
 	clockDisplay.print(displayValue, DEC);
}

void DisplayWrapper::displayAlarm1(int hour, int minute){
  displayHours(hour, minute);
  clockDisplay.writeDigitRaw(2, 0x04);
  clockDisplay.writeDisplay();

}

void DisplayWrapper::displayAlarm2(int hour, int minute){
  displayHours(hour, minute);
  clockDisplay.writeDigitRaw(2, 0x08);
  clockDisplay.writeDisplay();
}

void DisplayWrapper::displayBlank(){
  clockDisplay.clear();
  clockDisplay.writeDisplay();
}

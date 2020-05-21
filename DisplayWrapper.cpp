#include "DisplayWrapper.h"

DisplayWrapper::DisplayWrapper(){
	clockDisplay = Adafruit_7segment();
}

void DisplayWrapper::begin(){
  clockDisplay.begin(DISPLAY_ADDRESS);
}

void DisplayWrapper::displayTime(int hour, int minute, bool alarm1, bool alarm2){
  displayHours(hour, minute);

  // Center colon
  int bitValue = 0x02;
    
  if(alarm1){
      bitValue |= 0x04; // Upper left dot
  }
  if(alarm2){
      bitValue |= 0x08; // Lower left dot
  }
  
  clockDisplay.writeDigitRaw(2, bitValue);
  clockDisplay.writeDisplay();
}

void DisplayWrapper::displayHours(int hour, int minute){
	int displayValue = hour * 100 + minute;
 	clockDisplay.print(displayValue, DEC);
}

void DisplayWrapper::displayBlank(){
  clockDisplay.clear();
  clockDisplay.writeDisplay();
}

void DisplayWrapper::displayTemperature(float temp){

  // Round temperature value to one decimal case
  float rounded = ((float)((int)(temp * 10 + .5))) / 10;
  
  clockDisplay.printFloat(rounded);

  // Write the ºC character
  clockDisplay.writeDigitNum(4, 0xC);
  clockDisplay.writeDigitRaw(2, 0x10);
  
  clockDisplay.writeDisplay();
}

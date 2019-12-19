#include <SPI.h>
#include <SparkFunDS3234RTC.h>
#include <LiquidCrystal.h>
#include <JC_Button.h>              // https://github.com/JChristensen/JC_Button

#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin
const int CHANGE_PIN = 19; //

// Set pin mode for change button
Button button1(19);
Button button2(18);
Button button3(17);

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

int currDisplay = 0;
bool settingMode = false;

void setup() {

  button1.begin();
  button2.begin();
  button3.begin();
  
  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2); 

  // Initialize library
  rtc.begin(DS13074_CS_PIN);
  
  // Set the time using compiler data
  rtc.autoTime();
}

void loop() {
   
   // Re set the cursor
   lcd.setCursor(0,0);
   
   // Fetch current time from the rtc chip
   rtc.update();

   button1.read();
   button2.read();   
   button3.read();

   bool increase = button3.wasReleased();
   bool decrease = button2.wasReleased();
   
   if(button1.pressedFor(1000)){
       if(currDisplay == 0){
           settingMode = true;
       }
   }
   else if(button1.wasReleased()){
      currDisplay++;
   }

    switch(currDisplay){
      case 0: printHours(); break;
      case 1: printKEK(); break;
      default: currDisplay = 0;
    }

    if(settingMode){
      switch(currDisplay){
        case 0:
            if(increase){
              int hour = rtc      
            }
      }
    }
    
}

void printKEK(){
  lcd.print("AAAAAAAAAAAAAAAAAAAAA");
}

void printHours(){
  
   // Print everything
   hPrint(rtc.hour());
   lcd.print(":");
   hPrint(rtc.minute());
   lcd.print(":");
   hPrint(rtc.second());
}

void hPrint(uint8_t i, bool a) {
  if (i < 10){
    lcd.print("0");
  }
  lcd.print(i);
}

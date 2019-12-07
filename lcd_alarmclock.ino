#include <SPI.h>
#include <SparkFunDS3234RTC.h>
#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

#define DS13074_CS_PIN 10 // DeadOn RTC Chip-select pin

void setup() {
  
  //Set up the LCD's number of columns and rows:
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

   // Print everything
   hPrint(rtc.hour());
   lcd.print(":");
   hPrint(rtc.minute());
   lcd.print(":");
   hPrint(rtc.second());
   
}

void hPrint(short i) {
  if (i < 10){
    lcd.print("0");
  }
  lcd.print(i);
}

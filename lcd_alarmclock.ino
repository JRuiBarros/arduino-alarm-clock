#include "DisplayWrapper.h"
#include "RTCWrapper.h"
#include "Buttons.h"
#include "Mode.h"

RTCWrapper Mode::m_rtc;
Buttons Mode::buttons(2,3);
DisplayWrapper Mode::m_display;

Mode timeMode(0,1,2);
Mode alarm1Mode(1,0,2);
Mode alarm2Mode(2,1,0);

Mode modes[] = {timeMode, alarm1Mode, alarm2Mode};

Mode currentMode = timeMode;

void setup() {

  // This is needed because reasons
  Mode::m_display.begin();
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
}

void loop() {
   int mode = currentMode.pollButtons();
   currentMode = modes[mode];
   currentMode.display();
}

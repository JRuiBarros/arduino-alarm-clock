#include "CurrentTime.h"
#include "Alarm1.h"
#include "Alarm2.h"

RTCWrapper TimeMode::m_rtc;
CButton b1(2);
CButton b2(3);
CButton iMode::buttons[] = {b1, b2};
DisplayWrapper iMode::m_display;

CurrentTime timeMode;
Alarm1 alarm1Mode;
Alarm2 alarm2Mode;

iMode *modes[] = {&timeMode, &alarm1Mode, &alarm2Mode};

iMode *currentMode = &timeMode;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  Serial.println("abcdef");

  // This is needed because reasons
  iMode::m_display.begin();
  
  iMode::beginButtons();

  Serial.println("ccccccccccc");
}

void loop()
{
  // Serial.println("bbbbbbbbbb");
  int mode = currentMode->pollButtons();
  currentMode = modes[mode];
  currentMode->display();
}

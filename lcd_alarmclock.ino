#include "CurrentTime.h"
#include "Alarm1.h"
#include "Alarm2.h"
#include "TempMode.h"

int a[] = {0, 1, 2, 3};
CurrentTime timeMode(a);
int b[] = {1, 0, 2, 3};
Alarm1 alarm1Mode(b);
int c[] = {2, 1, 0, 3};
Alarm2 alarm2Mode(c);
int d[] = {3, 1, 2, 0};
TempMode tempMode(d);

iMode *modes[] = {&timeMode, &alarm1Mode, &alarm2Mode, &tempMode};

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
  tempMode.begin();

  iMode::begin();

  Serial.println("ccccccccccc");
}

void loop()
{
  // Serial.println("bbbbbbbbbb");
  int mode = currentMode->pollButtons();
  currentMode = modes[mode];
  currentMode->display();
}

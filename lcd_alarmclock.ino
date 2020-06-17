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

BaseMode *modes[] = {&timeMode, &alarm1Mode, &alarm2Mode, &tempMode};

BaseMode *currentMode = &timeMode;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  // This is needed because reasons
  tempMode.begin();
  BaseMode::begin();

  pinMode(9, INPUT_PULLUP); // INT pin of the time module.
  pinMode(8, OUTPUT); // LED PIN.
}

void loop()
{
  // Polls the INT pin of the time module, the pin is output inverted so we use ! digital read.
  !digitalRead(9) ? digitalWrite(8, HIGH) : digitalWrite(8, LOW);

  int mode = currentMode->pollButtons(); // Polls alarm buttons and returns the next current mode to be displayed.
  currentMode = modes[mode]; // Selects the current mode using the return value of the previous line.
  currentMode->display(); // Displays the curent mode on the screen.
}

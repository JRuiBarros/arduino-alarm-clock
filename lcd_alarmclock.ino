#include "CurrentTime.h"
#include "Alarm1.h"
#include "Alarm2.h"
#include "TempMode.h"
#include "HumiMode.h"

// The numbers on each array work as follows:
// 1st position corresponds to the position on the modes array below of the mode itself.
// The other three numbers are an association of the buttons to the other display modes represented by their position on the modes array.
// They are needed so the user can switch between the modes at will using the alarm clock buttons.
int a[] = {0, 1, 2, 3};
CurrentTime timeMode(a);
int b[] = {1, 0, 2, 3};
Alarm1 alarm1Mode(b);
int c[] = {2, 1, 0, 3};
Alarm2 alarm2Mode(c);
int d[] = {3, 1, 2, 4};
TempMode tempMode(d);
int e[] = {4, 1, 2, 0};
HumiMode humiMode(e);

// Array containing all the instances of the clock display modes. Only one can be active at a time and it is decided by the result of the pollButtons function.
BaseMode *modes[] = {&timeMode, &alarm1Mode, &alarm2Mode, &tempMode, &humiMode};

BaseMode *currentMode = &timeMode; // Pointer to the current mode being displayed.

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for Native USB only
  }

  // This is needed because reasons
  BaseMode::begin();

  pinMode(9, INPUT_PULLUP); // INT pin of the time module.
  pinMode(8, OUTPUT);       // LED PIN.
}

void loop()
{
  // Polls the INT pin of the time module, the pin is output inverted so we use ! digital read.
  !digitalRead(9) ? digitalWrite(8, HIGH) : digitalWrite(8, LOW);

  int mode = currentMode->pollButtons(); // Polls alarm buttons and returns the next current mode to be displayed.
  currentMode = modes[mode];             // Selects the current mode using the return value of the previous line.
  currentMode->display();                // Displays the curent mode on the screen.
}

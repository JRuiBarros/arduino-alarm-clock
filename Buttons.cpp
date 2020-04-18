#include "Buttons.h"

Buttons::Buttons(int p1, int p2) : b1(p1), b2(p2)
{
  b1.begin();
  b2.begin();
}

void Buttons::readButtons()
{
  b1.read();
  b2.read();
}

boolean Buttons::wasB1Released()
{
  if (inLongPress)
  {
    inLongPress = false;
  }
  else
  {
    return b1.wasReleased();
  }
}

boolean Buttons::wasB2Released()
{
  if (inLongPress)
  {
    inLongPress = false;
  }
  else
  {
    return b2.wasReleased();
  }
}

boolean Buttons::wasB1LongPressed()
{
  if (!inLongPress)
  {
    inLongPress = true;
    return b1.pressedFor(LONG_PRESS);
  }
}

boolean Buttons::wasB2LongPressed()
{
  if (!inLongPress)
  {
    inLongPress = true;
    return b2.pressedFor(LONG_PRESS);
  }
}

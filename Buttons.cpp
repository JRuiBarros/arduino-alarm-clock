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
  bool ret = b1.wasReleased();
  if (ret && inLongPress)
  {
    inLongPress = false;
    return false;
  }
  return ret;
}

boolean Buttons::wasB2Released()
{
  bool ret = b2.wasReleased();
  if (ret && inLongPress)
  {
    inLongPress = false;
    return false;
  }
  return ret;
}

boolean Buttons::wasB1LongPressed()
{
  if (!inLongPress)
  {
    bool ret = b1.pressedFor(LONG_PRESS);
    inLongPress = ret;
    return ret;
  }

  return false;
}

boolean Buttons::wasB2LongPressed()
{
  if (!inLongPress)
  {
    bool ret = b2.pressedFor(LONG_PRESS);
    inLongPress = ret;
    return ret;
  }

  return false;
}

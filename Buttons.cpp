#include "Buttons.h"

Buttons::Buttons(int p1, int p2):b1(p1), b2(p2){
  b1.begin();
  b2.begin();
}

boolean Buttons::wasB1Released(){
  b1.read();
	return b1.wasReleased();
}

boolean Buttons::wasB2Released(){
  b2.read();
	return b2.wasReleased();
}

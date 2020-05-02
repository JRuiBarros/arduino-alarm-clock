#include "iMode.h"

int iMode::pollButtons(){
    buttons[0].read();
    buttons[1].read();
    return -1;
}

void iMode::beginButtons(){
    buttons[0].begin();
    buttons[1].begin();
}
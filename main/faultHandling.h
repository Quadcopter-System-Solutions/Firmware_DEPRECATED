#ifndef FAULT_HANDLING
#define FAULT_HANDLING

#include "arduino.h"

extern u16 errorCode;

bool goingToCrash(void);
void dont(void);

#endif

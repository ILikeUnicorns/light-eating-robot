#ifndef DWENGO_SENSORS_H
#define DWENGO_SENSORS_H

#include "dwengoBoard.h"
#include "dwengoDelay.h"

// Functions
void initializeSensors(void);
int readSensor(BYTE sensor);
#endif
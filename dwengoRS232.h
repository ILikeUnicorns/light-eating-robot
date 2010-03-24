#ifndef DWENGO_RS232_H
#define DWENGO_RS232_H

#include "dwengoBoard.h"
#include "dwengoDelay.h"

void initializeRS232(void);
void sendData(void);
void closeRS232(void);

#endif
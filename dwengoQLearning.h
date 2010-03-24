#ifndef DWENGO_QLEARNING_H
#define DWENGO_QLEARNING_H

#include "dwengoBoard.h"
#include "dwengoDelay.h"

void initializeQLearning(void);
void addNode(char s, char a, char r);
void getTable(void);

#endif
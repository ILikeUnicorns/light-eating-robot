#ifndef DWENGO_MOTOR_H
#define DWENGO_MOTOR_H

#include "dwengoBoard.h"
#include "dwengoDelay.h"

//Vars
static BYTE DIR;

// Functions
void initializeMotors(void);
void leftMotor(int speed);
void rightMotor(int speed);
#endif
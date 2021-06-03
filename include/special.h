// File : special.h
// Description : interface of special and i\o operations 

#ifndef SPECIAL_H
#define SPECIAL_H

#include "cpu.h"

;void ei(emulatedCPU *cpu);

void di(emulatedCPU *cpu);

void nop();

void in();

void out();

void halt();

#endif
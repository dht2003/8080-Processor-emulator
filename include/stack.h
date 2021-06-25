// File : stack.h
// Description: Interface of cpu stack operation

#ifndef STACK_H
#define STACK_H

#include "cpu.h"
#include "util.h"
#include "mem.h"

void push(emulatedCPU *cpu,uint8_t highRegister, uint8_t lowerRegister );

uint16_t pop(emulatedCPU *cpu);

void sphl(emulatedCPU *cpu);

void xthl(emulatedCPU *cpu);

#endif
#ifndef STACK_H
#define STACK_H

#include "cpu.h"

void push(emulatedCPU *cpu,uint8_t highRegister, uint8_t lowerRegister );

uint16_t pop(emulatedCPU *cpu);


#endif
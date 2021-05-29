#ifndef BRANCH_H
#define BRANCH_H

#include "stack.h"
#include "cpu.h"

void jump(emulatedCPU *cpu, uint8_t upper_adr, uint8_t lower_adr); // might change that later 

void call(emulatedCPU *cpu,uint16_t addr);

void ret(emulatedCPU *cpu);

#endif
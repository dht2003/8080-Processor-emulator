// File : logic.h
// Description: Interface of logic operations

#ifndef LOGIC_H
#define LOGIC_H

#include "cpu.h"
#include "util.h"

void and(emulatedCPU *cpu , uint8_t value);

void or(emulatedCPU *cpu, uint8_t value); 

void xor(emulatedCPU *cpu, uint8_t value);

void cmp(emulatedCPU *cpu,uint8_t value);

void rar(emulatedCPU *cpu);

void rrc(emulatedCPU *cpu);

void cmc(emulatedCPU *cpu);

void cma(emulatedCPU *cpu);

void stc(emulatedCPU *cpu);

#endif
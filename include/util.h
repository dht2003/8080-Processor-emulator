#ifndef UTIL_H
#define UTIL_H

#include "cpu.h"

void updateAllFlags(flags *CPUflags , uint16_t value);

int parity(int value);

uint16_t pair(uint8_t high_reg,uint8_t low_reg);

uint16_t get_hl(emulatedCPU *cpu);

uint16_t get_bc(emulatedCPU *cpu); 

uint16_t get_de(emulatedCPU *cpu);

void readFile(emulatedCPU* cpu,char *filePath,uint16_t offset);

#endif
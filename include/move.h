
#ifndef MOVE_H
#define MOVE_H

#include "cpu.h"

void mov(uint8_t *reg, uint8_t value);

void lxi(uint8_t *high_reg,uint8_t *low_reg,uint16_t value);

void ldax(emulatedCPU *cpu,uint16_t addr);

void stax(emulatedCPU *cpu,uint16_t addr);

#endif
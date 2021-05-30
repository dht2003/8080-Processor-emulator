// File : arithmetic.h
// Description : Interface of arithmetic operations

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include "cpu.h"

void add(emulatedCPU *cpu , uint16_t value);

void adc(emulatedCPU *cpu, uint16_t value);

void dad(emulatedCPU *cpu , uint16_t value);

void sub(emulatedCPU *cpu ,  uint16_t value);

void inr(flags *CPUflags , uint8_t *reg);

void inx(flags *CPUflags , uint8_t *upperRegister , uint8_t *lowerRegister);

void dcr(flags *CPUflags, uint8_t *reg);

void dcx(flags *CPUflags , uint8_t *upperRegister, uint8_t *lowerRegister);

#endif
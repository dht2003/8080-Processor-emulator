// File : arithmetic.c
// Description : Implementation of arithmetic operations

#include "arithmetic.h"

void add(emulatedCPU *cpu , uint16_t value) {
    uint16_t result = (uint16_t) cpu->A + value;
    updateAllFlags(cpu->cpuFlags,result);
    cpu->A = result & MAX_BYTE_VALUE_MASK;
}

void adc(emulatedCPU *cpu, uint16_t value) {
    add(cpu,value + cpu->cpuFlags->cy);
}

void dad(emulatedCPU *cpu , uint16_t value) {
    uint16_t hl = (cpu->H << 8) | cpu->L;
    uint16_t result = hl + value;
    cpu->cpuFlags->cy = (result > MAX_BYTE_VALUE_MASK);
    cpu->H = (result >> 8) & MAX_BYTE_VALUE_MASK;
    cpu->L = result & MAX_BYTE_VALUE_MASK;
}

void sub(emulatedCPU *cpu, uint16_t value) {
    uint16_t result = (uint16_t) cpu->A - value;
    updateAllFlags(cpu->cpuFlags,result);
    cpu->A = result & MAX_BYTE_VALUE_MASK;
}

void inr(flags *CPUflags , uint8_t *reg) {
    (*reg)++;
    CPUflags->z = ((*reg) == 0);
    CPUflags->s = (((*reg) & MSB_MASK) != 0);
    CPUflags->p = parity((*reg));
    CPUflags->ac = 0;
}

void inx(uint8_t *upperRegister , uint8_t *lowerRegister) {
    uint16_t pair = ((*upperRegister) << 8) | (*lowerRegister);
    pair++;
    *lowerRegister = (pair & MAX_BYTE_VALUE_MASK);
    *upperRegister = pair >> 8;
}

void dcr(flags *CPUflags, uint8_t *reg) {
    (*reg)--;
    CPUflags->z = ((*reg) == 0);
    CPUflags->s = (((*reg) & MSB_MASK) != 0);
    CPUflags->p = parity((*reg));
    CPUflags->ac = 0;
}

void dcx(uint8_t *upperRegister, uint8_t *lowerRegister) {
   uint16_t pair = ((*upperRegister) << 8) | (*lowerRegister);
    pair--;
    *lowerRegister = (pair & MAX_BYTE_VALUE_MASK);
    *upperRegister = pair >> 8; 
}
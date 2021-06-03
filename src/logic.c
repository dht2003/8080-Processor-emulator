// File: logic.c 
// Description : imlementation of logic operations

#include "logic.h"

void and(emulatedCPU *cpu, uint8_t value) {
    cpu->A &= value;
    updateAllFlags(cpu->cpuFlags, cpu->A);
}

void or(emulatedCPU *cpu, uint8_t value) {
    cpu->A |= value;
    updateAllFlags(cpu->cpuFlags, cpu->A);
}

void xor(emulatedCPU *cpu,uint8_t value) {
    cpu->A ^= value;
    updateAllFlags(cpu->cpuFlags,cpu->A);
}

void cmp(emulatedCPU *cpu, uint8_t value) {
    uint8_t dif = cpu->A - value;
    updateAllFlags(cpu->cpuFlags , dif);
}

void cma(emulatedCPU *cpu) {
    cpu->A = ~(cpu->A);
}

void cmc(emulatedCPU *cpu) {
    cpu->cpuFlags->cy = ~(cpu->cpuFlags->cy);
}

void stc(emulatedCPU *cpu) {
    cpu->cpuFlags->cy = 1;
}

void rrc(emulatedCPU *cpu) {
    uint8_t tmp = cpu->A;
    cpu->A = ( tmp >> 1) | ((tmp & 0x01) << 7);
    cpu->cpuFlags->cy = tmp & 0x01;

}
// might need to change that 
void rar(emulatedCPU *cpu) {
    uint8_t tmp = cpu->A;
    cpu->A = (tmp & MSB_MASK) | (tmp >> 1);
    cpu->cpuFlags->cy = tmp & 0x01;
}
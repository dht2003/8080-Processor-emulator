#include "util.h"

uint16_t pair(uint8_t high_reg,uint8_t low_reg) {
    uint16_t result = (high_reg << 8) | (low_reg & MAX_BYTE_VALUE_MASK);
    return result;
}

int parity(int value) {
    int count = 0;
    while (value > 0) {
        if (value & 0x01) count++;
        value >>= 1;
    }
    return count % 2 == 0;
}


uint16_t get_hl(emulatedCPU *cpu) {
    return pair(cpu->H,cpu->L);
}

uint16_t get_bc(emulatedCPU *cpu) {
    return pair(cpu->B,cpu->C);
}

uint16_t get_de(emulatedCPU *cpu) {
    return pair(cpu->D,cpu->E);
}


void updateAllFlags(flags* CPUflags , uint16_t value) {
    CPUflags->z = ((value & MAX_BYTE_VALUE_MASK) == 0);
    CPUflags->s = ((value & MSB_MASK) != 0);
    CPUflags->p = parity(value & MAX_BYTE_VALUE_MASK); //TODO
    CPUflags->cy = (value > MAX_BYTE_VALUE_MASK);
    CPUflags->ac = 0; //TODO 
}


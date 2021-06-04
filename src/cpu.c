// File : cpu.c
// Description : implementation of general cpu functions

#include "cpu.h"

void freeCPU(emulatedCPU *cpu) {
    free(cpu->memory);
}

void unimplemented() {
    printf("ERROR : unimplemented instruction\n");
    exit(1);
}

void updateAllFlags(flags* CPUflags , uint16_t value) {
    CPUflags->z = ((value & MAX_BYTE_VALUE_MASK) == 0);
    CPUflags->s = ((value & MSB_MASK) != 0);
    CPUflags->p = parity(value & MAX_BYTE_VALUE_MASK); //TODO
    CPUflags->cy = (value > MAX_BYTE_VALUE_MASK);
    CPUflags->ac = 0; //TODO 
}

int parity(int value) {
    int count = 0;
    while (value > 0) {
        if (value & 0x01) count++;
        value >>= 1;
    }
    return count % 2 == 0;
}

void printState(emulatedCPU *cpu) {
    printf("Flags:\nS:%d\nZ:%d\nP:%d\nCY:%d\nAC:%d\n",cpu->cpuFlags->s,cpu->cpuFlags->z,cpu->cpuFlags->p,cpu->cpuFlags->cy,cpu->cpuFlags->ac);
    printf("Registers:\nA: $%02x \nB: $%02x \nC: $%02x \nD: $%02x \nE: $%02x \nH: $%02x \nL: $%02x \nSP: %04x\nPC: %04x\n",    
           cpu->A, cpu->B, cpu->C, cpu->D,    
           cpu->E, cpu->H, cpu->L, cpu->SP,cpu->PC);   
}

uint16_t pair(uint8_t high_reg,uint8_t low_reg) {
    uint16_t result = (high_reg << 8) | (low_reg & MAX_BYTE_VALUE_MASK);
    return result;
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

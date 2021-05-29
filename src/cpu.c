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


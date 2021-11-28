// File : cpu.c
// Description : implementation of general cpu functions

#include "cpu.h"

emulatedCPU initCPU() {
    emulatedCPU cpu; 
    cpu.PC = 0;
    cpu.SP = STACK_START;
    return cpu;
}

void freeCPU(emulatedCPU *cpu) { 
}

void unimplemented() {
    printf("ERROR : unimplemented instruction\n");
    exit(1);
}

void printState(emulatedCPU cpu) {
    printf("Flags:\nS:%d\nZ:%d\nP:%d\nCY:%d\nAC:%d\n",cpu.cpuFlags->s,cpu.cpuFlags->z,cpu.cpuFlags->p,cpu.cpuFlags->cy,cpu.cpuFlags->ac);
    printf("Registers:\nA: $%02x \nB: $%02x \nC: $%02x \nD: $%02x \nE: $%02x \nH: $%02x \nL: $%02x \nSP: %04x\nPC: %04x\n",    
           cpu.A, cpu.B, cpu.C, cpu.D,    
           cpu.E, cpu.H, cpu.L, cpu.SP,cpu.PC);   
}





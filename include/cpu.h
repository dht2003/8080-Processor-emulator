// File : cpu.h
// Description: Interface of general cpu functions

#ifndef CPU_H
#define CPU_H 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_BYTE_VALUE_MASK 0xff
#define MSB_MASK 0x80


typedef struct Flags {
    uint8_t s:1;
    uint8_t z:1;
    uint8_t p:1;
    uint8_t cy:1;
    uint8_t ac:1;
} flags;

typedef struct EMULATED_CPU {
   uint8_t A;
   uint8_t B;
   uint8_t C; 
   uint8_t D; 
   uint8_t E;
   uint8_t H;
   uint8_t L;
   uint16_t SP;
   uint16_t PC;
   uint8_t enable_intrupts : 1;
   flags *cpuFlags;
   uint8_t *memory;
} emulatedCPU;

void freeCPU(emulatedCPU *cpu) ;

void unimplemented();

int parity(int value);

void updateAllFlags(flags *CPUflags , uint16_t value);

void printState(emulatedCPU *cpu);

uint16_t pair(uint8_t high_reg,uint8_t low_reg);

uint16_t get_hl(emulatedCPU *cpu);

uint16_t get_bc(emulatedCPU *cpu); 

uint16_t get_de(emulatedCPU *cpu);

#endif
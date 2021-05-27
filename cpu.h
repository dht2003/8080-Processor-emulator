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
   flags cpuFlags;
   uint8_t *memory;
} emulatedCPU;

void freeCPU(emulatedCPU *cpu) ;

void unimplemented();

int parity(int value);

void  updateAllFlags(flags *CPUflags , uint16_t value);

void add(emulatedCPU *cpu , uint16_t value);

void adc(emulatedCPU *cpu, uint16_t value);

void dad(emulatedCPU *cpu , uint16_t value);

void sub(emulatedCPU *cpu ,  uint16_t value);

void inr(flags *CPUflags , uint8_t *reg);

void inx(flags *CPUflags , uint8_t *upperRegister , uint8_t *lowerRegister);

void dcr(flags *CPUflags, uint8_t *reg);

void dcx(flags *CPUflags , uint8_t *upperRegister, uint8_t *lowerRegister);

void jump(emulatedCPU *cpu, uint16_t addr);

void call(emulatedCPU *cpu);

void ret(emulatedCPU *cpu);

#endif
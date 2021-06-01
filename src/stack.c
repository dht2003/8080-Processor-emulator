// File : stack.c
// Description : imlementation of general stack functions 

#include "stack.h"

void push(emulatedCPU *cpu,uint8_t highRegister,uint8_t lowerRegister) {
    cpu->memory[cpu->SP - 1] = highRegister;
    cpu->memory[cpu->SP - 2] = lowerRegister;
    cpu->SP -= 2;
}

uint16_t pop(emulatedCPU *cpu) {
    uint8_t low = cpu->memory[cpu->SP];
    uint8_t high = cpu->memory[cpu->SP + 1];
    uint16_t result = (high << 8) | low ;
    cpu->SP += 2;
    return result;
}

void sphl(emulatedCPU *cpu) {
    uint16_t hl = (cpu->H << 8) | cpu->L;
    cpu->SP = hl;
}

void xthl(emulatedCPU *cpu) {
    uint16_t sp = pop(cpu);
    push(cpu,cpu->H,cpu->L);
    cpu->H = sp >> 8;
    cpu->L = sp & MAX_BYTE_VALUE_MASK;
}
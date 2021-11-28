#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "cpu.h"
#include "stack.h"

typedef enum interrupts_enum {
    interrupt0 = 0,
    interrupt1 = 1,
    interrupt2 = 2,
    interrupt3 = 3,
    interrupt4 = 4,
    interrupt5 = 5,
    interrupt6 = 6,
    interrupt7 = 7,
} interrupts;

void generateInterrupt(emulatedCPU *cpu, interrupts interruptNumber);

#endif
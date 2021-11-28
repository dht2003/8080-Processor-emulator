#include "interrupt.h"

void generateInterrupt(emulatedCPU *cpu, interrupts interruptNumber) {
    if (cpu->enable_interrupts) {
        push(cpu,(cpu->PC & 0xff00) >> 8, (cpu->PC & 0xff));
        cpu->PC = 8 * interruptNumber;
    }
}
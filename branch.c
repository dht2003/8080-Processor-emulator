#include "cpu.h"

void jump(emulatedCPU *cpu, uint8_t upper_adr, uint8_t lower_adr) {
    uint16_t adr = (upper_adr << 8) | lower_adr;
    cpu->PC = adr;
}


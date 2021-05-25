#include "cpu.h"

void freeCPU(emulatedCPU *cpu) {
    free(cpu->memory);
}

void unimplemented() {
    printf("ERROR : unimplemented instruction\n");
    exit(1);
}


void add(emulatedCPU *cpu , uint16_t value) {
    uint16_t result = (uint16_t) cpu->A + value;
    cpu->flags.z = ((result & MAX_BYTE_VALUE_MASK) == 0);
    cpu->flags.s = ((result & MSB_MASK) != 0);
    cpu->flags.p = parity(answer & MAX_BYTE_VALUE_MASK);
    cpu->flags.cy = (result > MAX_BYTE_VALUE_MASK);
    cpu->flags.ac = 0; //TODO
    cpu->A = result & MAX_BYTE_VALUE_MASK;

}
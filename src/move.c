#include "move.h"

void mov(uint8_t *reg,uint8_t value) { (*reg) = value; }

void lxi(uint8_t *high_reg,uint8_t *low_reg,uint16_t value) {
    mov(high_reg,(value>>8) & MAX_BYTE_VALUE_MASK);
    mov(low_reg,value & MAX_BYTE_VALUE_MASK);
}

void ldax(emulatedCPU *cpu,uint16_t addr) { cpu->A = readByte(cpu,addr);}

void stax(emulatedCPU *cpu,uint16_t addr) {writeByte(cpu,addr,cpu->A);}
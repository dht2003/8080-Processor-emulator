//  File: mem.c
// Description : Implementation of memory read and write operations

#include "mem.h"


uint8_t readByte(emulatedCPU *cpu,uint16_t addr) {
    if (addr > MEMORY_SIZE) 
        invalidMemoryAccess();
    return cpu->memory[addr];
}

uint8_t *getMemoryAddr(emulatedCPU* cpu,uint16_t addr) {
    if (addr > MEMORY_SIZE) 
        invalidMemoryAccess();
    return &cpu->memory[addr];
}

uint16_t readWord(emulatedCPU *cpu,uint16_t addr) {
    return pair(readByte(cpu,addr + 1),readByte(cpu,addr));
}

void writeByte(emulatedCPU *cpu ,uint16_t addr,uint8_t value) {
    if (addr > MEMORY_SIZE) {
        invalidMemoryAccess();
    }
    cpu->memory[addr] = value;
}


void writeWord(emulatedCPU *cpu,uint16_t addr,uint16_t word) {
    writeByte(cpu,addr,word & MAX_BYTE_VALUE_MASK);
    writeByte(cpu,addr+1,(word >> 8) & MAX_BYTE_VALUE_MASK);
}

uint8_t readNextByte(emulatedCPU *cpu) {
    return readByte(cpu,cpu->PC++);
}


uint16_t readNextWord(emulatedCPU *cpu) {
    uint8_t lowAddr = readNextByte(cpu);
    uint8_t highAddr = readNextByte(cpu);
    return pair(highAddr,lowAddr);
}


void invalidMemoryAccess() {
    printf("Invalid memory access\n");
    exit(1);
}
// File : mem.h
// Description : Interface of memory read and write  operations


#ifndef MEM_H
#define MEM_H

#include "cpu.h"
#include "util.h"

uint8_t readByte(emulatedCPU *cpu,uint16_t addr);

uint16_t readWord(emulatedCPU *cpu,uint16_t addr);

void writeByte(emulatedCPU *cpu,uint16_t addr,uint8_t value);

void writeWord(emulatedCPU *cpu,uint16_t addr,uint16_t word);

uint8_t readNextByte(emulatedCPU *cpu);

uint16_t readNextWord(emulatedCPU * cpu);

void invalidMemoryAccess();

uint8_t *getMemoryAddr(emulatedCPU* cpu,uint16_t addr);

#endif
// File : mem.h
// Description : Interface of memory read and write  operations


#ifdef MEM_H
#define MEM_H

#include "cpu.h"
#include "util.h"

uint8_t readByte(emulatedCPU *cpu);

uint16_t readWord(emulatedCPU *cpu);

void writeByte(emulatedCPU *cpu);

void writeWord(emulatedCPU *cpu);

#endif
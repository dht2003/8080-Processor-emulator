#include "util.h"

uint16_t pair(uint8_t high_reg,uint8_t low_reg) {
    uint16_t result = (high_reg << 8) | (low_reg & MAX_BYTE_VALUE_MASK);
    return result;
}

int parity(int value) {
    int count = 0;
    while (value > 0) {
        if (value & 0x01) count++;
        value >>= 1;
    }
    return count % 2 == 0;
}

void readFile(emulatedCPU* cpu,char *filePath,uint16_t offset) {
    FILE *binary = fopen(filePath,"rb");
    if (binary == NULL) {
        printf("ERROR: can't open %s\n",filePath);
        exit(1);
    }
    fseek(binary,0,SEEK_END);
    uint16_t binarySize = ftell(binary);
    fseek(binary,0,SEEK_SET);
    uint8_t *memRead = &cpu->memory[offset];
    fread(memRead,binarySize,1,binary);
    free(binary);
    
}

uint16_t get_hl(emulatedCPU *cpu) {
    return pair(cpu->H,cpu->L);
}

uint16_t get_bc(emulatedCPU *cpu) {
    return pair(cpu->B,cpu->C);
}

uint16_t get_de(emulatedCPU *cpu) {
    return pair(cpu->D,cpu->E);
}


void updateAllFlags(flags* CPUflags , uint16_t value) {
    CPUflags->z = ((value & MAX_BYTE_VALUE_MASK) == 0);
    CPUflags->s = ((value & MSB_MASK) != 0);
    CPUflags->p = parity(value & MAX_BYTE_VALUE_MASK); //TODO
    CPUflags->cy = (value > MAX_BYTE_VALUE_MASK);
    CPUflags->ac = 0; //TODO 
}



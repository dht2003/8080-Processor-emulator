// File : branch.c 
// Description : implementation of general branch functions 
#include "branch.h"

void jump(emulatedCPU *cpu, uint8_t upper_adr, uint8_t lower_adr) {
    uint16_t adr =  pair(upper_adr,lower_adr);
    cpu->PC = adr;
}


void call(emulatedCPU *cpu, uint16_t addr) {
    if (addr == 5) {
        uint16_t offset = (cpu->D<<8) | (cpu->E);    
                    char *str = &cpu->memory[offset+3];  //skip the prefix bytes    
                    while (*str != '$')    
                        printf("%c", *str++);    
                    printf("\n");
    }
    else if (addr == 0) {exit(0);}
    else {
    uint16_t ret = cpu->PC + 2;
    uint8_t high = (ret >> 8) & MAX_BYTE_VALUE_MASK;
    uint8_t low = (ret & MAX_BYTE_VALUE_MASK);
    push(cpu,high,low);
    cpu->PC = addr;
    }
}

void ret(emulatedCPU *cpu) { cpu->PC = pop(cpu);}
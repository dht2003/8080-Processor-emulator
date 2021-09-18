#include "test.h"

void testCPU(emulatedCPU cpu) {
    readFile(&cpu,TEST_SCRIPT_PATH,0x100);
    cpu.memory[0]=0xc3;    
    cpu.memory[1]=0;    
    cpu.memory[2]=0x01;    

    //Fix the stack pointer from 0x6ad to 0x7ad    
    cpu.memory[368] = 0x7;    

    //Skip DAA test    
    cpu.memory[0x59c] = 0xc3; //JMP    
    cpu.memory[0x59d] = 0xc2;    
    cpu.memory[0x59e] = 0x05;  
    while(1) {
        if (cpu.PC == 0x689) {
            printState(&cpu);
            printf("failed\n");
            break;
        };
        if (cpu.PC == 0x69b) {
            printf("CPU IS OPERATIONAL\n");
            break;
        }
        printf("PC: %04x, instruction: %02x\n",cpu.PC,cpu.memory[cpu.PC]);
        emulate(&cpu);
    }
}
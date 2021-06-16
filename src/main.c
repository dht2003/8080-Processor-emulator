#include "emulate.h"

int main(int argc , char *argv[]) {
    emulatedCPU *cpu = initCPU();
    readFile(cpu,"/home/guysham2003/projects/8080CPU/tests/cpudiag.bin",0x100);
    /*readFile(cpu,"/home/guysham2003/projects/8080CPU/space_invaders/invaders.h",0);
    readFile(cpu,"/home/guysham2003/projects/8080CPU/space_invaders/invaders.g",0x800);
    readFile(cpu,"/home/guysham2003/projects/8080CPU/space_invaders/invaders.f",0x1000);
    readFile(cpu,"/home/guysham2003/projects/8080CPU/space_invaders/invaders.e",0x1800); */
    cpu->memory[0]=0xc3;    
    cpu->memory[1]=0;    
    cpu->memory[2]=0x01;    

    //Fix the stack pointer from 0x6ad to 0x7ad    
    // this 0x06 byte 112 in the code, which is    
    // byte 112 + 0x100 = 368 in memory    
    cpu->memory[368] = 0x7;    

    //Skip DAA test    
    cpu->memory[0x59c] = 0xc3; //JMP    
    cpu->memory[0x59d] = 0xc2;    
    cpu->memory[0x59e] = 0x05;  
    while(cpu->PC <= 0x0fff) {
        printf("d\n");
        emulate(cpu);
        //printState(cpu);
    }
    freeCPU(cpu);
}
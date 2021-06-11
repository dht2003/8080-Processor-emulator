#include "emulate.h"

int main(int argc , char *argv[]) {
    if (argc != 2) 
        printf("usage : ./emulate.out [CODE_FILE]\n");
    emulatedCPU *cpu = initCPU();
    readFile(cpu,argv[1],0);
    freeCPU(cpu);
}
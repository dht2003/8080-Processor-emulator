#include "emulate.h"

int main(int argc , char *argv[]) {
    if (argc != 2) 
        printf("usage : ./emulate.out [CODE_FILE]\n");
    emulatedCPU cpu = {.PC=0};
    
}
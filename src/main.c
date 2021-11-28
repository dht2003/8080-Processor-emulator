#include "emulate.h"
#include "test.h"
#include <string.h>

int main(int argc , char *argv[]) {
    emulatedCPU cpu;
    if (argc == 2) {
        if (strcmp(argv[1],"test") == 0)
            testCPU(&cpu);
        else {
            readFile(&cpu,argv[1],0);
            while(1)
                emulate(&cpu);
        }
    }

    else if (argc == 3) {
        readFile(&cpu,argv[1],atoi(argv[2]));
        while(1) 
            emulate(&cpu);
    }

    else {
        printf("Usage:\n");
        printf("./build/bin/emulate.out [INPUT_FILE] [OFFSET(OPTIONAL)] - for regular use\n");
        printf("./build/bin/emulate.out test - runs test script\n");
    }

}
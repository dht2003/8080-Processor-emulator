#include "emulate.h"
#include "test.h"

int main(int argc , char *argv[]) {
    emulatedCPU *cpu = initCPU();
    testCPU(*cpu);   
    testCPU(*cpu);
    freeCPU(cpu);
}
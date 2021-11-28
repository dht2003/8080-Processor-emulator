#include "emulate.h"
#include "test.h"

int main(int argc , char *argv[]) {
    emulatedCPU cpu;
    testCPU(&cpu);
    printState(cpu);
}
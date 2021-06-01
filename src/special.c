//File : special.c
// Description: imlementation of special and i\o operations

#include "special.h"

void ei(emulatedCPU *cpu) {
    cpu->enable_intrupts = 1;
}

void di(emulatedCPU *cpu) {
    cpu->enable_intrupts = 0;
}

void halt() {
    exit(1);
}

void in() {

}

void out() {

}
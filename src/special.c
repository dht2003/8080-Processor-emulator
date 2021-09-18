//File : special.c
// Description: implementation of special and i\o operations

#include "special.h"

void ei(emulatedCPU *cpu) {
    cpu->enable_interrupts = 1;
}

void di(emulatedCPU *cpu) {
    cpu->enable_interrupts = 0;
}

void halt() {
    exit(1);
}

void in() {

}

void out() {

}

void nop() {

}

void daa() {
    
}
#ifndef EMULATE_H
#define EMULATE_H

#include "cpu.h"
#include "arithmetic.h"
#include "branch.h"
#include "util.h"
#include "emulate.h"
#include "logic.h"
#include "move.h"
#include "opcodes.h"
#include "special.h"
#include "stack.h"
#include "mem.h"

int emulate(emulatedCPU *cpu);


#endif
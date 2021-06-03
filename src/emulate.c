#include "emulate.h"

void emulate(emulatedCPU *cpu) {
    unsigned char *opcode = &cpu->memory[cpu->PC];
    int opbytes = 1;
    switch (*opcode) {
        case nop_op: nop() ;break;
        case lxi_b_c:
        {
            uint16_t value = ((opcode[2] << 8) | (opcode[1] & MAX_BYTE_VALUE_MASK));
            lxi(&cpu->B,&cpu->C,value);
            opbytes = 3;
            break;
        }
        case stax_b_c:
            unimplemented(); break;
        case inx_b_c: inx(&cpu->B,&cpu->C); break; 
        //case inr_b: inr();

    }
}
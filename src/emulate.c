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
        case stax_b_c: {
            uint16_t bc = pair(cpu->B,cpu->C);
            stax(cpu,bc);
            break;
        }
        case inx_b_c: inx(&cpu->B,&cpu->C); break; 
        case inr_b: inr(cpu->cpuFlags,&cpu->B); break;
        case dcr_b: dcr(cpu->cpuFlags,&cpu->B); break;
        case mvi_b: mov(&cpu->B,opcode[1]); opbytes = 2; break;
        case rlc_op: unimplemented(); break;
        case dad_b_c: {
            uint16_t bc = pair(cpu->B,cpu->C);
            dad(cpu,bc);
            break;
        }
        case ldax_b_c: 
        {
            uint16_t bc = pair(cpu->B,cpu->C);
            ldax(cpu,bc);
            break;
        }
        case dcx_b_c: dcx(&cpu->B,&cpu->C); break;
        case inr_c: inr(cpu->cpuFlags,&cpu->C); break;
        case dcr_c: dcr(cpu->cpuFlags,&cpu->C); break;
        case mvi_c: mov(&cpu->C,opcode[1]); opbytes=2; break;
        case rrc_op: rrc(cpu); break;
        case lxi_d_e: {
            uint16_t value = pair(opcode[2],opcode[1]);
            lxi(&cpu->D,&cpu->E,value); opbytes=3;break;
        }
        case stax_d_e: 
        {
            uint16_t de = pair(cpu->D,cpu->E);
            stax(cpu,de);
            break;
        }
        case inx_d_e: inx(&cpu->D,&cpu->E); break;
        case inr_d: inr(cpu->cpuFlags,&cpu->D); break;
        case dcr_d: dcr(cpu->cpuFlags,&cpu->D); break;
        case mvi_d: mov(&cpu->D,opcode[1]); opbytes=2;break;
        case ral_op: unimplemented(); break;
        case dad_d_e: {
            uint16_t de = pair(cpu->D,cpu->E);
            dad(cpu,de);
            break;
        }
        case ldax_d_e: {
            uint16_t de = pair(cpu->D,cpu->E);
            ldax(cpu,de);
            break;
        }
        case dcx_d_e: dcx(&cpu->D,&cpu->E);
    }
}
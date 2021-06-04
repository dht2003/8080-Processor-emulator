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
        case dcx_d_e: dcx(&cpu->D,&cpu->E); break;
        case inr_e: inr(cpu->cpuFlags,&cpu->E); break;
        case dcr_e: dcr(cpu->cpuFlags,&cpu->E); break;
        case mvi_e: mov(&cpu->E,opcode[1]); opbytes = 2; break;
        case rar_instruction: rar(cpu); break;
        case lxi_h_l: {
            uint16_t hl = pair(opcode[2],opcode[1]); 
            lxi(&cpu->H,cpu->L,hl); 
            opbytes = 3;
            break;
        }
        case shld: 
        {
            uint16_t addr = pair(opcode[2],opcode[1]);
            opbytes = 3;
            unimplemented();
        }
        case  inx_h_l: inx(&cpu->H,&cpu->L); break;
        case inr_h: inr(cpu->cpuFlags,&cpu->H); break;
        case dcr_h: dcr(cpu->cpuFlags,&cpu->H); break;
        case mvi_h: mov(&cpu->H,opcode[1]); opbytes =2; break;
        case daa_op: daa(); break;
        case dad_h_l:
        {
            uint16_t hl = pair(cpu->H,cpu->L);
            dad(cpu,hl);
            break;
        }
        case lhld: unimplemented(); break;
        case dcx_h_l: dcx(&cpu->H,&cpu->L); break;
        case inr_l: inr(cpu->cpuFlags,&cpu->L); break;
        case dcr_l: dcr(cpu->cpuFlags,&cpu->L); break;
        case mvi_l: mov(&cpu->L,opcode[1]); opbytes =2; break;
        case cma_op: cma(cpu); break;
        case lxi_sp: {
            uint16_t sp = pair(opcode[2],opcode[1]); 
            cpu->SP = sp;
            opbytes = 3;
            break;
        }
        case sta_op: {
            uint16_t addr = pair(opcode[2],opcode[1]); 
            stax(cpu,addr); 
            opbytes = 3;
            break;
        }
        case inx_sp: cpu->SP++; break; // might need to change that 

    }
}
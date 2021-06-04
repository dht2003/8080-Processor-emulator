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
        case inr_m: 
        {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t m = cpu->memory[hl];
            inr(cpu->cpuFlags,&m);
            break;
        }
        case dcr_m: {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t m = cpu->memory[hl]; 
            dcr(cpu->cpuFlags,&m);
            break;
        }
        case mvi_m: {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t m = cpu->memory[hl];
            mov(&m,opcode[1]);
            opbytes;
            break;
        }
        case stc_op: stc(cpu); break;
        case dad_sp:  dad(cpu,cpu->SP); break;
        case lda_op: {
            uint16_t addr = pair(opcode[2],opcode[1]);
            ldax(cpu,addr);
            opbytes = 3;
            break;
        }
        case dcx_sp: cpu->SP--; break;
        case inr_a: inr(cpu->cpuFlags,&cpu->A); break;
        case dcr_a: dcr(cpu->cpuFlags,&cpu->A); break;
        case mvi_a: mov(&cpu->A,opcode[1]); opbytes =2; break;
        case cmc_op: cmc(cpu); break;
        case mov_b_b: mov(&cpu->B,cpu->B); break;
        case mov_b_c: mov(&cpu->B,cpu->C); break;
        case mov_b_d: mov(&cpu->B,cpu->D); break;
        case mov_b_e: mov(&cpu->B,cpu->E); break;
        case mov_b_h: mov(&cpu->B,cpu->H); break;
        case mov_b_l: mov(&cpu->B,cpu->L); break;
        case mov_b_m: {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t m = cpu->memory[hl];
            mov(&cpu->B,m);
            break;
        }
        case mov_b_a: mov(&cpu->B,cpu->A); break;
        case mov_c_b: mov(&cpu->C,cpu->B); break;
        case mov_c_c: mov(&cpu->C,cpu->C); break; 
        case mov_c_d: mov(&cpu->C,cpu->D); break;
        case mov_c_e: mov(&cpu->C,cpu->E); break;
        case mov_c_h: mov(&cpu->C,cpu->H); break;
        case mov_c_l: mov(&cpu->C,cpu->L); break;
        case mov_c_m: mov(&cpu->C,cpu->memory[get_hl(cpu)]); break;
        case mov_c_a: mov(&cpu->C,cpu->A); break;
        case mov_d_b: mov(&cpu->D,cpu->B) ; break;
        case mov_d_c: mov(&cpu->D,cpu->C); break;
        case mov_d_d: mov(&cpu->D,cpu->D); break;
        case mov_d_e: mov(&cpu->D,cpu->E); break;
        case mov_d_h: mov(&cpu->D,cpu->H); break;
        case mov_d_l: mov(&cpu->D,cpu->L); break;
        case mov_d_m: mov(&cpu->D,cpu->memory[get_hl(cpu)]); break;
        case mov_d_a: mov(&cpu->D,cpu->A); break;
        case mov_e_b: mov(&cpu->E,cpu->B); break;
        case mov_e_c: mov(&cpu->E,cpu->C); break;
        case mov_e_d: mov(&cpu->E,cpu->D); break;
        case mov_e_e: mov(&cpu->E,cpu->E); break;
        case mov_e_h: mov(&cpu->E,cpu->H); break;
        case mov_e_l: mov(&cpu->E,cpu->L); break;
        case mov_e_m: mov(&cpu->E,cpu->memory[get_hl(cpu)]); break;
        case mov_e_a: mov(&cpu->E,cpu->A); break;
        case mov_h_b: mov(&cpu->H,cpu->B); break;
        case mov_h_c: mov(&cpu->H,cpu->C); break;
        case mov_h_d: mov(&cpu->H,cpu->D); break;
        case mov_h_e: mov(&cpu->H,cpu->E); break;
        case mov_h_h: mov(&cpu->H,cpu->H); break;
        case mov_h_l: mov(&cpu->H,cpu->L); break;
        case mov_h_m: mov(&cpu->H,cpu->memory[get_hl(cpu)]); break;
        case mov_h_a: mov(&cpu->H,cpu->A); break;
        case mov_l_b: mov(&cpu->L,cpu->B); break;
        case mov_l_c: mov(&cpu->L,cpu->C); break;
        case mov_l_d: mov(&cpu->L,cpu->D); break;
        case mov_l_e: mov(&cpu->L,cpu->E); break;
        case mov_l_h: mov(&cpu->L,cpu->H); break;
        case mov_l_l: mov(&cpu->L,cpu->L); break;
        case mov_l_m: mov(&cpu->L,cpu->memory[get_hl(cpu)]); break;
        case mov_l_a: mov(&cpu->L,cpu->A); break;
        case mov_m_b: mov(&cpu->memory[get_hl(cpu)],cpu->B); break;
        case mov_m_c: mov(&cpu->memory[get_hl(cpu)],cpu->C); break;
        case mov_m_d: mov(&cpu->memory[get_hl(cpu)],cpu->D); break;
        case mov_m_e: mov(&cpu->memory[get_hl(cpu)],cpu->E); break;
        case mov_m_h: mov(&cpu->memory[get_hl(cpu)],cpu->H); break;
        case mov_m_l: mov(&cpu->memory[get_hl(cpu)],cpu->L); break;
        case halt_op: halt(); break;
        case mov_m_a: mov(&cpu->memory[get_hl(cpu)],cpu->A); break;
        case mov_a_b: mov(&cpu->A,cpu->B); break;
        case mov_a_c: mov(&cpu->A,cpu->C); break;
        case mov_a_d: mov(&cpu->A,cpu->D); break;
        case mov_a_e: mov(&cpu->A,cpu->E); break;
        case mov_a_h: mov(&cpu->A,cpu->H); break;
        case mov_a_l: mov(&cpu->A,cpu->L); break;
        case mov_a_m: mov(&cpu->A,cpu->memory[get_hl(cpu)]); break;
        case mov_a_a: mov(&cpu->A,cpu->A); break;

    }
}
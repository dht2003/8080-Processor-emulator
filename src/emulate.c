#include "emulate.h"

int emulate(emulatedCPU *cpu) {
    unsigned char *opcode = &cpu->memory[cpu->PC];
    cpu->PC++;
    switch (*opcode) {
        case nop_op: nop() ;break;
        case lxi_b_c:
        {
            uint16_t value = ((opcode[2] << 8) | (opcode[1] & MAX_BYTE_VALUE_MASK));
            lxi(&cpu->B,&cpu->C,value);
            cpu->PC += 2;
        } break;
        case stax_b_c: {
            uint16_t bc = pair(cpu->B,cpu->C);
            stax(cpu,bc);
        } break;
        case inx_b_c: inx(&cpu->B,&cpu->C); break; 
        case inr_b: inr(cpu->cpuFlags,&cpu->B); break;
        case dcr_b: dcr(cpu->cpuFlags,&cpu->B); break;
        case mvi_b: mov(&cpu->B,opcode[1]); cpu->PC++; break;
        case rlc_op: {
            cpu->cpuFlags->cy = (cpu->A & MSB_MASK) >> 7;
            cpu->A = (cpu->A << 1) | (cpu->A >> 7);
        } break;
        case dad_b_c: {
            uint16_t bc = pair(cpu->B,cpu->C);
            dad(cpu,bc);
        } break;
        case ldax_b_c: 
        {
            uint16_t bc = pair(cpu->B,cpu->C);
            ldax(cpu,bc);
        } break;
        case dcx_b_c: dcx(&cpu->B,&cpu->C); break;
        case inr_c: inr(cpu->cpuFlags,&cpu->C); break;
        case dcr_c: dcr(cpu->cpuFlags,&cpu->C); break;
        case mvi_c: mov(&cpu->C,opcode[1]); cpu->PC++; break;
        case rrc_op: rrc(cpu); break;
        case lxi_d_e: {
            uint16_t value = pair(opcode[2],opcode[1]);
            lxi(&cpu->D,&cpu->E,value); cpu->PC+=2;
        } break;
        case stax_d_e: 
        {
            uint16_t de = pair(cpu->D,cpu->E);
            stax(cpu,de);
        } break;
        case inx_d_e: inx(&cpu->D,&cpu->E); break;
        case inr_d: inr(cpu->cpuFlags,&cpu->D); break;
        case dcr_d: dcr(cpu->cpuFlags,&cpu->D); break;
        case mvi_d: mov(&cpu->D,opcode[1]); cpu->PC++;break;
        case ral_op: {
            uint8_t prevA = cpu->A;
            cpu->A = (prevA << 1) | cpu->cpuFlags->cy;
            cpu->cpuFlags->cy = prevA >> 7;
        } break;
        case dad_d_e: {
            uint16_t de = pair(cpu->D,cpu->E);
            dad(cpu,de);
        } break;
        case ldax_d_e: {
            uint16_t de = pair(cpu->D,cpu->E);
            ldax(cpu,de);
        } break;
        case dcx_d_e: dcx(&cpu->D,&cpu->E); break;
        case inr_e: inr(cpu->cpuFlags,&cpu->E); break;
        case dcr_e: dcr(cpu->cpuFlags,&cpu->E); break;
        case mvi_e: mov(&cpu->E,opcode[1]); cpu->PC++; break;
        case rar_instruction: rar(cpu); break;
        case lxi_h_l: {
            uint16_t hl = pair(opcode[2],opcode[1]); 
            lxi(&cpu->H,&cpu->L,hl); 
            cpu->PC += 2;
        } break;
        case shld: 
        {
            uint16_t addr = pair(opcode[2],opcode[1]); 
            cpu->memory[addr] = cpu->L;
            cpu->memory[addr + 1] = cpu->H;
            cpu->PC += 2;
        } break;
        case  inx_h_l: inx(&cpu->H,&cpu->L); break;
        case inr_h: inr(cpu->cpuFlags,&cpu->H); break;
        case dcr_h: dcr(cpu->cpuFlags,&cpu->H); break;
        case mvi_h: mov(&cpu->H,opcode[1]); cpu->PC++; break;
        case daa_op: daa(); break;
        case dad_h_l:
        {
            uint16_t hl = pair(cpu->H,cpu->L);
            dad(cpu,hl);
        } break;
        case lhld: {
            uint16_t addr = pair(opcode[2],opcode[1]);
            cpu->L = cpu->memory[addr]; 
            cpu->H = cpu->memory[addr + 1];
            cpu->PC += 2;
        }break;
        case dcx_h_l: dcx(&cpu->H,&cpu->L); break;
        case inr_l: inr(cpu->cpuFlags,&cpu->L); break;
        case dcr_l: dcr(cpu->cpuFlags,&cpu->L); break;
        case mvi_l: mov(&cpu->L,opcode[1]); cpu->PC++; break;
        case cma_op: cma(cpu); break;
        case lxi_sp: {
            uint16_t sp = pair(opcode[2],opcode[1]); 
            cpu->SP = sp;
            cpu->PC += 2;
        } break;
        case sta_op: {
            uint16_t addr = pair(opcode[2],opcode[1]); 
            stax(cpu,addr); 
            cpu->PC += 2;
        } break;
        case inx_sp: cpu->SP++; break; // might need to change that 
        case inr_m: 
        {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t m = cpu->memory[hl];
            inr(cpu->cpuFlags,&m);
        } break;
        case dcr_m: {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t m = cpu->memory[hl]; 
            dcr(cpu->cpuFlags,&m);
        } break;
        case mvi_m: {
            uint16_t hl = pair(cpu->H,cpu->L);
            uint8_t * m = &cpu->memory[hl];
            mov(m,opcode[1]);
            cpu->PC++;
        } break;
        case stc_op: stc(cpu); break;
        case dad_sp:  dad(cpu,cpu->SP); break;
        case lda_op: {
            uint16_t addr = pair(opcode[2],opcode[1]);
            ldax(cpu,addr);
            cpu->PC += 2;
        } break;
        case dcx_sp: cpu->SP--; break;
        case inr_a: inr(cpu->cpuFlags,&cpu->A); break;
        case dcr_a: dcr(cpu->cpuFlags,&cpu->A); break;
        case mvi_a: mov(&cpu->A,opcode[1]); cpu->PC++; break;
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
            
        } break;
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
        case add_b: add(cpu,cpu->B); break;
        case add_c: add(cpu,cpu->C); break;
        case add_d: add(cpu,cpu->D); break;
        case add_e: add(cpu,cpu->E); break;
        case add_h: add(cpu,cpu->H); break;
        case add_l: add(cpu,cpu->L); break;
        case add_m: add(cpu,cpu->memory[get_hl(cpu)]);break;
        case add_a: add(cpu,cpu->A); break;
        case adc_b: adc(cpu,cpu->B); break;
        case adc_c: adc(cpu,cpu->C); break;
        case adc_d: adc(cpu,cpu->D); break;
        case adc_e: adc(cpu,cpu->E); break;
        case adc_h: adc(cpu,cpu->H); break;
        case adc_l: adc(cpu,cpu->L); break;
        case adc_m: adc(cpu,cpu->memory[get_hl(cpu)]); break;
        case adc_a: adc(cpu,cpu->A); break;
        case sub_b: sub(cpu,cpu->B); break;
        case sub_c: sub(cpu,cpu->C); break;
        case sub_d: sub(cpu,cpu->D); break;
        case sub_e: sub(cpu,cpu->E); break;
        case sub_h: sub(cpu,cpu->H); break;
        case sub_l: sub(cpu,cpu->L); break;
        case sub_m: sub(cpu,cpu->memory[get_hl(cpu)]); break;
        case sub_a: sub(cpu,cpu->A); break;
        case sbb_b: sbb(cpu,cpu->B); break;
        case sbb_c: sbb(cpu,cpu->C); break;
        case sbb_d: sbb(cpu,cpu->D); break;
        case sbb_e: sbb(cpu,cpu->E); break;
        case sbb_h: sbb(cpu,cpu->H); break;
        case sbb_l: sbb(cpu,cpu->L); break;
        case sbb_m: sbb(cpu,cpu->memory[get_hl(cpu)]); break;
        case sbb_a: sbb(cpu,cpu->A); break;
        case ana_b: and(cpu,cpu->B); break;
        case ana_c: and(cpu,cpu->C); break;
        case ana_d: and(cpu,cpu->D); break;
        case ana_e: and(cpu,cpu->E); break;
        case ana_h: and(cpu,cpu->H); break;
        case ana_l: and(cpu,cpu->L); break;
        case ana_m: and(cpu,cpu->memory[get_hl(cpu)]); break;
        case ana_a: and(cpu,cpu->A); break;
        case xra_b: xor(cpu,cpu->B); break;
        case xra_c: xor(cpu,cpu->C); break;
        case xra_d: xor(cpu,cpu->D); break;
        case xra_e: xor(cpu,cpu->E); break;
        case xra_h: xor(cpu,cpu->H); break;
        case xra_l: xor(cpu,cpu->L); break;
        case xra_m: xor(cpu,cpu->memory[get_hl(cpu)]); break;
        case xra_a: xor(cpu,cpu->A); break;
        case ora_b: or(cpu,cpu->B); break;
        case ora_c: or(cpu,cpu->C); break;
        case ora_d: or(cpu,cpu->D); break;
        case ora_e: or(cpu,cpu->E); break;
        case ora_h: or(cpu,cpu->H); break;
        case ora_l: or(cpu,cpu->L); break;
        case ora_m: or(cpu,cpu->memory[get_hl(cpu)]); break;
        case ora_a: or(cpu,cpu->A); break;
        case cmp_b: cmp(cpu,cpu->B); break;
        case cmp_c: cmp(cpu,cpu->C); break;
        case cmp_d: cmp(cpu,cpu->D); break;
        case cmp_e: cmp(cpu,cpu->E); break;
        case cmp_h: cmp(cpu,cpu->H); break;
        case cmp_l: cmp(cpu,cpu->L); break;
        case cmp_m: cmp(cpu,cpu->memory[get_hl(cpu)]); break;
        case cmp_a: cmp(cpu,cpu->A); break;
        case rnz: if (!cpu->cpuFlags->z) ret(cpu); break;
        case pop_b: {
            uint16_t bc = pop(cpu);
            cpu->B = (bc >> 8) & MAX_BYTE_VALUE_MASK;
            cpu->C = bc & MAX_BYTE_VALUE_MASK;
        }
        break;
        case jnz: if(!cpu->cpuFlags->z) jump(cpu,opcode[2],opcode[1]);else cpu->PC += 2; break;
        case jmp: jump(cpu,opcode[2],opcode[1]);break;
        case cnz: if(cpu->cpuFlags->z == 0) call(cpu,pair(opcode[2],opcode[1])); else cpu->PC+=2; break;
        case push_b: push(cpu,cpu->B,cpu->C); break;
        case adi: add(cpu,opcode[1]); cpu->PC++; break;
        case rst_0: unimplemented(); break;
        case rz: if(cpu->cpuFlags->z) ret(cpu);break;
        case ret_op: ret(cpu);break;
        case jz: if(cpu->cpuFlags->z) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2;break;
        case cz: if(cpu->cpuFlags->z) call(cpu,pair(opcode[2],opcode[1])); else cpu->PC+=2;break;
        case call_op: call(cpu,pair(opcode[2],opcode[1]));break;
        case aci: adc(cpu,opcode[1]);cpu->PC++;break;
        case rst_1: unimplemented();break;
        case rnc: if(!cpu->cpuFlags->cy) ret(cpu); break;
        case pop_d: {
            uint16_t de = pop(cpu);
            cpu->D = (de >> 8) & MAX_BYTE_VALUE_MASK;
            cpu->E = de & MAX_BYTE_VALUE_MASK;
        } break;
        case jnc: if (!cpu->cpuFlags->cy) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2; break;
        case out_op: out(); cpu->PC++; break;
        case cnc_op: if(!cpu->cpuFlags->cy) call(cpu,pair(opcode[2],opcode[1])); else cpu->PC+=2;break;
        case push_d: push(cpu,cpu->D,cpu->E); break;
        case sui: sub(cpu,opcode[1]); cpu->PC++;break;
        case rst_2: unimplemented(); break;
        case rc: if(cpu->cpuFlags->cy) ret(cpu); break;
        case jc: if(cpu->cpuFlags->cy) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2;break;
        case in_op: in(); cpu->PC++; break;
        case cc: if(cpu->cpuFlags->cy) call(cpu,pair(opcode[2],opcode[1]));else cpu->PC+=2;break;
        case sbi: sbb(cpu,opcode[1]); cpu->PC++;break;
        case rst_3: unimplemented(); break;
        case rpo: if(!cpu->cpuFlags->p)ret(cpu); break; 
        case pop_h: {
            uint16_t hl = pop(cpu);
            cpu->H = (hl >> 8) & MAX_BYTE_VALUE_MASK;
            cpu->L = hl & MAX_BYTE_VALUE_MASK;
        } break;
        case jpo: if(!cpu->cpuFlags->p) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2;break;
        case xthl_op: xthl(cpu); break;
        case cpo: if(!cpu->cpuFlags->p) call(cpu,pair(opcode[2],opcode[1]));else cpu->PC+=2;break;
        case push_h: push(cpu,cpu->H,cpu->L); break;
        case ani: and(cpu,opcode[1]);cpu->PC++;break;
        case rst_4: unimplemented(); break;
        case rpe: if(cpu->cpuFlags->p) ret(cpu); break;
        case pchl: {
            cpu->PC = pair(cpu->H,cpu->L);
        } break;
        case jpe: if(cpu->cpuFlags->p) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2;break;
        case xchg: {
            uint8_t tmpH = cpu->H , tmpL=cpu->L;
            cpu->H = cpu->D;
            cpu->D = tmpH;
            cpu->L = cpu->E;
            cpu->E = tmpL;
        } break; 
        case cpe: if(cpu->cpuFlags->p) call(cpu,pair(opcode[2],opcode[1]));else cpu->PC+=2;break;
        case xri: xor(cpu,opcode[1]);cpu->PC++;break;
        case rst_5: unimplemented(); break;
        case rp_op: if(!cpu->cpuFlags->s) ret(cpu);break;
        case pop_psw: {
            uint16_t value = pop(cpu);
            cpu->A = (value >> 8) & MAX_BYTE_VALUE_MASK;
            uint8_t psw = value & MAX_BYTE_VALUE_MASK;
            cpu->cpuFlags->cy = value & 0x01;
            cpu->cpuFlags->p = psw  >> 2;
            cpu->cpuFlags->ac =psw  >> 4;
            cpu->cpuFlags->z = psw  >> 6;
            cpu->cpuFlags->s = psw  >> 7;
        } break; 
        case jp: if(!cpu->cpuFlags->s) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2;break;
        case di_op: di(cpu); break;
        case cp: if(!cpu->cpuFlags->s) call(cpu,pair(opcode[2],opcode[1]));else cpu->PC+=2;break;
        case push_psw: {
            uint8_t psw = (cpu->cpuFlags->cy |
                            (cpu->cpuFlags->p << 2)|
                            (cpu->cpuFlags->ac << 4)|
                            (cpu->cpuFlags->z << 6)|
                            (cpu->cpuFlags->s << 7));
            push(cpu,cpu->A,psw);
            
        } break; 
        case ori_op: or(cpu,opcode[1]); cpu->PC++; break;
        case rst_6: unimplemented(); break;
        case rm_op: if(cpu->cpuFlags->s) ret(cpu); break;
        case sphl_op: sphl(cpu); break;
        case jm_op: if(cpu->cpuFlags->s) jump(cpu,opcode[2],opcode[1]);else cpu->PC+=2;break;
        case ei_op: ei(cpu); break;
        case cm_op: if(cpu->cpuFlags->s) call(cpu,pair(opcode[2],opcode[1]));else cpu->PC+=2;break;
        case cpi_op: cmp(cpu,opcode[1]);cpu->PC++;break;
        case rst_7: unimplemented(); break;
    }
    return 0;
}
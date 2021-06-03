// File : opcodes.h
// Description: list of opcodes

#ifndef OP_CODES_H
#define OP_CODES_H

enum opcodes {
    nop_op = 0x00,
    lxi_b_c = 0x01,
    stax_b_c = 0x02,
    inx_b_c = 0x03,
    inr_b = 0x04,
    dcr_b = 0x05,
    mvi_b = 0x06,
    rlc_op = 0x07,
    dad_b_c = 0x09,
    ldax_b_c = 0x0a,
    dcx_b_c = 0x0b,
    inr_c = 0x0c,
    dcr_c = 0x0d,
    mvi_c = 0x0e,
    rrc_op = 0x0f,
    lxi_d_e = 0x11,
    stax_d_e = 0x12,
    inx_d_e = 0x13,
    inr_d = 0x14,
    dcr_d = 0x15,
    mvi_d = 0x16,
    ral_op = 0x17,
    dad_d_e = 0x19,
    inr_h = 0x24,
    ldax_d_e = 0x1a,
    dcx_d_e = 0x1b,
    mvi_e = 0x1e,
    rar_instruction = 0x1f,
    lxi_h_l = 0x21,
    shld = 0x22,
    inx_h_l = 0x23,
    mvi_h = 0x26,
    daa_op = 0x27,
    dad_h_l = 0x29,
    lhld = 0x2a,
    dcx_h_l = 0x2b,
    inr_l = 0x2c,
    mvi_l = 0x2e,
    cma_op = 0x2f,
    lxi_sp = 0x31,
    sta = 0x32,
    inr_m = 0x34,
    dcr_m = 0x35,
    mvi_m = 0x36,
    stc_op = 0x37,
    lda_op = 0x3a,
    inr_a = 0x3c,
    dcr_a = 0x3d,
    mvi_a = 0x3e,
    mov_b_b = 0x40,
    mov_b_c = 0x41,
    mov_b_d = 0x42,
    mov_b_e = 0x43,
    mov_b_h = 0x44,
    mov_b_l = 0x45,
    mov_b_m = 0x46,
    mov_b_a = 0x47,
    mov_c_b = 0x48,
    mov_c_c = 0x49,
    mov_c_d = 0x4a,
    mov_c_e = 0x4b,
    mov_c_h = 0x4c,
    mov_c_l = 0x4d,
    mov_c_m = 0x4e,
    mov_c_a = 0x4f,
    mov_d_b = 0x50,
    mov_d_c = 0x51,
    mov_d_d = 0x52,
    mov_d_e = 0x53,
    mov_d_h = 0x54,
    mov_d_l = 0x55,
    mov_d_m = 0x56,
    mov_d_a = 0x57,
    mov_e_b = 0x58,
    mov_e_c = 0x59,
    mov_e_d = 0x5a,
    mov_e_e = 0x5b,
    mov_e_h = 0x5c,
    mov_e_l = 0x5d,
    mov_e_m = 0x5e,
    mov_e_a = 0x5f,
    mov_h_b = 0x60,
    mov_h_c = 0x61,
    mov_h_d = 0x62,
    mov_h_e = 0x63,
    mov_h_h = 0x64,
    mov_h_l = 0x65,
    mov_h_m = 0x66,
    mov_h_a = 0x67,
    mov_l_b = 0x68,
    mov_l_c = 0x69,
    mov_l_d = 0x6a,
    mov_l_e = 0x6b,
    mov_l_h = 0x6c,
    mov_l_l = 0x6d,
    mov_l_m = 0x6e,
    mov_l_a = 0x6f,
    mov_m_b = 0x70,
    mov_m_c = 0x71,
    mov_m_d = 0x72,
    mov_m_e = 0x73,
    mov_m_h = 0x74,
    mov_m_l = 0x75,
    mov_m_a = 0x77,
    mov_a_b = 0x78,
    mov_a_c = 0x79,
    mov_a_d = 0x7a,
    mov_a_e = 0x7b,
    mov_a_h = 0x7c,
    mov_a_l = 0x7d,
    mov_a_m = 0x7e,
    mov_a_a = 0x7f,
    add_b = 0x80,
    add_c = 0x81,
    add_d = 0x82,
    add_e = 0x83,
    add_h = 0x84,
    add_l = 0x85,
    add_m = 0x86,
    add_a = 0x87,
    adc_b = 0x88,
    adc_c = 0x89,
    adc_d = 0x8a,
    adc_e = 0x8b,
    adc_h = 0x8c,
    adc_l = 0x8d,
    adc_m = 0x8e,
    adc_a = 0x8f,
    sub_b = 0x90,
    sub_c = 0x91,
    sub_d = 0x92,
    sub_e = 0x93,
    sub_h = 0x94,
    sub_l = 0x95,
    sub_m = 0x96,
    sub_a = 0x97,
    ana_b = 0xa0,
    ana_c = 0xa1,
    ana_d = 0xa2,
    ana_e = 0xa3,
    ana_h = 0xa4,
    ana_l = 0xa5,
    ana_m = 0xa6,
    ana_a = 0xa7,
    xra_b = 0xa8,
    xra_c = 0xa9,
    xra_d = 0xaa,
    xra_e = 0xab,
    xra_h = 0xac,
    xra_l = 0xad,
    xra_m = 0xae,
    xra_a = 0xaf,
    ora_b = 0xb0,
    ora_c = 0xb1,
    ora_d = 0xb2,
    ora_e = 0xb3,
    ora_h = 0xb4,
    ora_l = 0xb5,
    ora_m = 0xb6,
    ora_a = 0xb7,
    cmp_b = 0xb8,
    cmp_c = 0xb9,
    cmp_d = 0xba,
    cmp_e = 0xbb,
    cmp_h = 0xbc,
    cmp_l = 0xbd,
    cmp_m = 0xbe,
    cmp_a = 0xbf,
    rnz = 0xc0,
    pop_b = 0xc1,
    jnz = 0xc2,
    jmp = 0xc3,
    cnz = 0xc4,
    push_b = 0xc5,
    adi = 0xc6,
    rz = 0xc8,
    ret_op = 0xc9,
    jz = 0xca,
    cz = 0xcc,
    call_op = 0xcd,
    rnc = 0xd0,
    pop_d = 0xd1,
    jnc = 0xd2,
    out_op = 0xd3,
    cnc_op = 0xd4,
    push_d = 0xd5,
    sui = 0xd6,
    rc = 0xd8,
    jc = 0xda,
    in_op = 0xdb,
    sbi = 0xde,
    rpo = 0xe0,
    pop_h = 0xe1,
    xthl_op = 0xe3,
    push_h = 0xe5,
    ani = 0xe6,
    rpe = 0xe8,
    pchl = 0xe9,
    xchg = 0xeb,
    rp_op = 0xf0,
    pop_psw = 0xf1,
    di_op = 0xf3,
    push_psw = 0xf5,
    ori_op = 0xf6,
    rm_op = 0xf8,
    jm_op = 0xfa,
    ei_op = 0xfb,
    cpi_op = 0xfe,
    rst_7 = 0xff,
};

#endif
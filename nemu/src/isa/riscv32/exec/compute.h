static inline def_EHelper(lui) {
  rtl_li(s, ddest, id_src1->imm);
  print_asm_template2(lui);
}


// U x[rd] = pc + sext(immediate[31:12] << 12)
static inline def_EHelper(auipc) {
  // sword_t jump =;
  Log("id_src2->simm\t=\t%x\n",id_src1->simm);
  rtl_li(s, ddest,s->seq_pc+id_src1->simm);
  print_asm_template2(auipc);
}


// wth
// M[x[rs1] + sext(offset) = x[rs2][31: 0]
// static inline def_EHelper(sw) {
//   rtl_sm(s, dsrc1,id_src2->imm,ddest,4);
// print_asm_template2(lui);
// }
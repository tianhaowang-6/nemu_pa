static inline def_EHelper(lui) {
  rtl_li(s, ddest, id_src1->imm);
  print_asm_template2(lui);
}

// wth
// static inline def_rtl(sm, const rtlreg_t* addr, word_t offset, const rtlreg_t* src1, int len) {
//    vaddr_write(*addr + offset, *src1, len);
// }
static inline def_EHelper(sw) {
  // rtlreg_t* addr=id_dest;
  // sword_t offset = id_src2->imm; 
  // rtlreg_t* src1 = id_dest;
  // rtl_sm(id_dest,id_src2->imm,id_dest,4);
  // print_asm_template2(lui);
}
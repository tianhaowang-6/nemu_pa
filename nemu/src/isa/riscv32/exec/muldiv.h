// wth I
static inline def_EHelper(addi) {
  //rtl_addi(s, dest, rz, imm);
  printf("dsrc1=%x\n",*dsrc1);
  rtl_addi(s, ddest, dsrc1,id_src2->imm);
  print_asm_template2(addi);
}
static inline def_EHelper(ld) {
  rtl_lm(s, ddest, dsrc1, id_src2->imm, s->width);

  print_Dop(id_src1->str, OP_STR_SIZE, "%d(%s)", id_src2->imm, reg_name(id_src1->reg));
  switch (s->width) {
    case 4: print_asm_template2(lw); break;
    case 2: print_asm_template2(lhu); break;
    case 1: print_asm_template2(lbu); break;
    default: assert(0);
  }
}

static inline def_EHelper(st) {
  printf("id_src2->imm=%x,dsrc1=%x\n",id_src2->imm,*dsrc1);
  rtl_sm(s, dsrc1, id_src2->imm, ddest, s->width);

  print_Dop(id_src1->str, OP_STR_SIZE, "%d(%s)", id_src2->imm, reg_name(id_src1->reg));
  switch (s->width) {
    case 4: print_asm_template2(sw); break;
    case 2: print_asm_template2(sh); break;
    case 1: print_asm_template2(sb); break;
    default: assert(0);
  }
}
// wth
static inline def_EHelper(li) {
  rtl_li(s, ddest, id_src1->imm);
  print_asm_template2(li);
}

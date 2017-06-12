/*
** op.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Thu Mar 23 23:00:48 2017 
** Last update Fri Mar 31 15:16:22 2017 
*/

#include "op.h"
#include "struct.h"
#include "proto.h"

op_t    op_tab[] =
  {
    {"live", 1, {T_DIR}, 1, 10, "alive", write_live, check_live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", write_ld, check_ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", write_st, check_st},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", write_add, check_op},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", write_sub, check_op},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
     "et (and  r1, r2, r3   r1&r2 -> r3", write_and, check_bin},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
     "ou  (or   r1, r2, r3   r1 | r2 -> r3", write_or, check_bin},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
     "ou (xor  r1, r2, r3   r1^r2 -> r3", write_xor, check_bin},
    {"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", write_zjmp, check_zjump},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
     "load index", write_ldi, check_ldi},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
     "store index", write_sti, check_sti},
    {"fork", 1, {T_DIR}, 12, 800, "fork", write_fork, check_fork},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", write_ld, check_ld},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
     "long load index", write_ldi, check_ldi},
    {"lfork", 1, {T_DIR}, 15, 1000, "long fork", write_fork, check_fork},
    {"aff", 1, {T_REG}, 16, 2, "aff", write_aff, check_aff},
    {0, 0, {0}, 0, 0, 0, 0, 0}
  };

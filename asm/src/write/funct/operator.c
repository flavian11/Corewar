/*
** operator.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:07:54 2017 
** Last update Sun Apr  2 17:25:21 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "struct.h"
#include "macro.h"
#include "proto.h"
#include "op.h"

void	check_op(const t_info info)
{
  if (info.arg_code[0] != REGISTER || info.arg_code[1] != REGISTER ||
      info.arg_code[2] != REGISTER)
    compile_error();
}

void	write_add(const t_info info, const int fd)
{
  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  write(fd, &info.arg[0], 1);
  write(fd, &info.arg[1], 1);
  write(fd, &info.arg[2], 1);
  g_size += 5;
}

void	write_sub(const t_info info, const int fd)
{
  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  write(fd, &info.arg[0], 1);
  write(fd, &info.arg[1], 1);
  write(fd, &info.arg[2], 1);
  g_size += 5;
}

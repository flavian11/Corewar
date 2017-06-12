/*
** live.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:06:25 2017 
** Last update Sun Apr  2 15:49:59 2017 
*/

#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "macro.h"
#include "op.h"

void	write_live(const t_info info, const int fd)
{
  int	converted;

  converted = convert_big_endian_magic_number(info.arg[0]);
  write(fd, &info.instruc_code, 1);
  write(fd, &converted, 4);
  g_size += 5;
}

void	check_live(const t_info info)
{
  if (info.arg_code[0] == REGISTER)
    compile_error();
}

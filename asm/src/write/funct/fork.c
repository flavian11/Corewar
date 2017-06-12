/*
** fork.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:11:30 2017 
** Last update Sun Apr  2 17:24:54 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "macro.h"
#include "op.h"

void	check_fork(const t_info info)
{
  if (info.arg_code[0] == REGISTER)
    compile_error();
  if (info.arg_code[1] != -1)
    compile_error();
}

void	write_fork(const t_info info, const int fd)
{
  int	converted;

  write(fd, &info.instruc_code, 1);
  g_size += 1;
  converted = convert_big_endian(info.arg[0]);
  write(fd, &converted, 2);
  g_size += 2;
}

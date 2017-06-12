/*
** jump.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:09:30 2017 
** Last update Sun Apr  2 17:23:34 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "struct.h"
#include "macro.h"
#include "proto.h"
#include "op.h"

void	check_zjump(const t_info info)
{
  if (info.arg_code[0] == REGISTER)
    compile_error();
  if (info.arg_code[1] != -1)
    compile_error();
}

void	write_zjmp(const t_info info, const int fd)
{
  int	converted;

  write(fd, &info.instruc_code, 1);
  if (info.arg_code[0] == DIRECT)
    {
      converted = convert_big_endian(info.arg[0]);
      write(fd, &converted, 2);
    }
  if (info.arg_code[0] == INDIRECT)
    {
      converted = convert_big_endian(info.arg[0]);
      write(fd, &converted, 2);
    }
  g_size += 3;
}

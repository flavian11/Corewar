/*
** ld.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:07:02 2017 
** Last update Sun Apr  2 20:02:33 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "proto.h"
#include "op.h"
#include "macro.h"

void	check_ld(const t_info info)
{
  if (info.arg_code[0] == REGISTER)
    compile_error();
  if (info.arg_code[1] != REGISTER)
    compile_error();
  if (info.arg_code[2] != -1)
    compile_error();
}

void	write_ld(const t_info info, const int fd)
{
  long	converted;

  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  if (info.arg_code[0] == DIRECT)
    {
      converted = convert_big_endian_magic_number(info.arg[0]);
      write(fd, &converted, DIR_SIZE);
      g_size += DIR_SIZE;
    }
  else if (info.arg_code[0] == INDIRECT)
    {
      converted = convert_big_endian(info.arg[0]);
      write(fd, &converted, IND_SIZE);
      g_size += IND_SIZE;
    }
  write(fd, &info.arg[1], 1);
  g_size += 3;
}

void	check_ldi(const t_info info)
{
  if (info.arg_code[0] == REGISTER)
    compile_error();
  if (info.arg_code[1] == REGISTER)
    compile_error();
  if (info.arg_code[2] != REGISTER)
    compile_error();
}

void	write_ldi(const t_info info, const int fd)
{
  int	converted;

  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  converted = convert_big_endian(info.arg[0]);
  if (info.arg_code[0] == DIRECT)
    write(fd, &converted, 2);
  else if (info.arg_code[0] == INDIRECT)
    write(fd, &converted, 2);
  if (info.arg_code[1] == DIRECT)
    {
      converted = convert_big_endian(info.arg[1]);
      write(fd, &converted, 2);
    }
  else if (info.arg_code[1] == INDIRECT)
    {
      converted = convert_big_endian(info.arg[1]);
      write(fd, &converted, 2);
    }
  write(fd, &info.arg[2], 1);
  g_size += 7;
}

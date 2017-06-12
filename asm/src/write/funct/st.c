/*
** st.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:07:22 2017 
** Last update Sun Apr  2 15:55:02 2017 
*/

#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "macro.h"
#include "op.h"

void	check_st(const t_info info)
{
  if (info.arg_code[0] != REGISTER)
    compile_error();
}

void	write_st(const t_info info, const int fd)
{
  int	converted;
  int	a;

  a = 255;
  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  write(fd, &info.arg[0], 1);
  g_size += 3;
  if (info.arg_code[1] == REGISTER)
    {
      write(fd, &info.arg[1], 1);
      g_size += 1;
    }
  else if (info.arg_code[1] == DIRECT)
    {
      converted = convert_big_endian_magic_number(info.arg[1]);
      write(fd, &converted, DIR_SIZE);
      g_size += DIR_SIZE;
    }
  else if (info.arg_code[1] == INDIRECT)
    write_st2(info, a, fd, converted);
}

void	check_sti(const t_info info)
{
   if (info.arg_code[0] != REGISTER)
    compile_error();
}

void	write_sti(const t_info info, const int fd)
{
  int	converted;

   write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  write(fd, &info.arg[0], 1);
  g_size += 3;
  if (info.arg_code[1] == REGISTER)
    {
      write(fd, &info.arg[1], 1);
      g_size += REGISTER;
    }
  else if (info.arg_code[1] == DIRECT)
    {
      converted = convert_big_endian(info.arg[1]);
      write(fd, &converted, 2);
      g_size += 2;
    }
  else if (info.arg_code[1] == INDIRECT)
    {
      converted = convert_big_endian(info.arg[1]);
      write(fd, &converted, 2);
      g_size += 2;
    }
  write_sti2(info, fd);
}

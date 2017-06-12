/*
** binary_op.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:08:26 2017 
** Last update Sun Apr  2 17:24:44 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "struct.h"
#include "proto.h"
#include "op.h"
#include "macro.h"

void	check_bin(const t_info info)
{
  if (info.arg_code[0] != REGISTER)
    compile_error();
}

void	write_end_and(const t_info info, const int fd)
{
  int	converted;

  if (info.arg_code[2] == 1)
    {
      write(fd, &info.arg[2], 1);
      g_size += 1;
    }
  else if (info.arg_code[2] == 2)
    {
      converted = convert_big_endian_magic_number(info.arg[2]);
      write(fd, &converted, DIR_SIZE);
      g_size += DIR_SIZE;
    }
  else if (info.arg_code[2] == 3)
    {
      converted = convert_big_endian(info.arg[2]);
      write(fd, &converted, IND_SIZE);
      g_size += IND_SIZE;
    }
}

void	write_and(const t_info info, const int fd)
{
  int	converted;

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
    {
      converted = convert_big_endian(info.arg[1]);
      write(fd, &converted, IND_SIZE);
      g_size += IND_SIZE;
    }
  write_end_and(info, fd);
}

void	write_end_or(const t_info info, const int fd)
{
  int	converted;

  if (info.arg_code[2] == 1)
    {
      write(fd, &info.arg[2], 1);
      g_size += 1;
    }
  else if (info.arg_code[2] == 2)
    {
      converted = convert_big_endian_magic_number(info.arg[2]);
      write(fd, &converted, DIR_SIZE);
      g_size += DIR_SIZE;
    }
  else if (info.arg_code[2] == 3)
    {
      converted = convert_big_endian(info.arg[2]);
      write(fd, &converted, IND_SIZE);
      g_size += IND_SIZE;
    }
}

void	write_or(const t_info info, const int fd)
{
  int	converted;

  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  write(fd, &info.arg[0], 1);
  g_size += 3;
  if (info.arg_code[1] == 1)
    {
      write(fd, &info.arg[1], 1);
      g_size += 1;
    }
  else if (info.arg_code[1] == 2)
    {
      converted = convert_big_endian_magic_number(info.arg[1]);
      write(fd, &converted, DIR_SIZE);
      g_size += DIR_SIZE;
    }
  else if (info.arg_code[1] == 3)
    {
      converted = convert_big_endian(info.arg[1]);
      write(fd, &converted, IND_SIZE);
      g_size += IND_SIZE;
    }
  write_end_or(info, fd);
}

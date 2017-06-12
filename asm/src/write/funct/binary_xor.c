/*
** binary_xor.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Apr  2 16:45:31 2017 Hugo Tallineau
** Last update Sun Apr  2 17:23:18 2017 Hugo Tallineau
*/

#include "proto.h"
#include <unistd.h>

void    write_end_xor(const t_info info, const int fd)
{
  int   converted;

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

void    write_xor(const t_info info, const int fd)
{
  int   converted;

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
  write_end_xor(info, fd);
}

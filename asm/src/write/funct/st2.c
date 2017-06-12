/*
** st2.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Apr  2 16:55:23 2017 Hugo Tallineau
** Last update Sun Apr  2 17:24:01 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "macro.h"
#include "struct.h"
#include "proto.h"
#include "op.h"

void	write_sti2(const t_info info, const int fd)
{
  int	converted;

  if (info.arg_code[2] == REGISTER)
    {
      write(fd, &info.arg[2], 1);
      g_size += 1;
    }
  else if (info.arg_code[2] == DIRECT)
    {
      converted = convert_big_endian(info.arg[2]);
      write(fd, &converted, 2);
      g_size += 2;
    }
  else if (info.arg_code[2] == INDIRECT)
    {
      converted = convert_big_endian(info.arg[2]);
      write(fd, &converted, 2);
      g_size += 2;
    }
}

void	write_st2(const t_info info, const int a, const int fd, int converted)
{
  converted = convert_big_endian(info.arg[1]);
  if (info.arg[1] > -255 && info.arg[1] < 0)
    {
      write(fd, &a, 1);
      write(fd, &info.arg[1], 1);
    }
  else
    write(fd, &converted, IND_SIZE);
  g_size += IND_SIZE;
}

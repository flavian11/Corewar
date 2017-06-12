/*
** get_byte.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/codding_bytes
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Apr  2 16:14:50 2017 Hugo Tallineau
** Last update Sun Apr  2 16:15:04 2017 Hugo Tallineau
*/

#include "proto.h"

int     get_byte(int params[4])
{
  int   i;
  int   res;

  i = res = 0;

  while (params[i] != -1)
    {
      res = res | params[i];
      res = res << 2;
      i++;
    }
  while (i < 3)
    {
      res = res << 2;
      i++;
    }
  return (res);
}

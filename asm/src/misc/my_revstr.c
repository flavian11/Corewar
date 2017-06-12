/*
** my_revstr.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Fri Mar 31 17:05:37 2017 
** Last update Sun Apr  2 12:48:10 2017 Hugo Tallineau
*/

#include "proto.h"

char	*my_revstr(char *str)
{
  int	i;
  int	x;
  char	tmp;

  i = 0;
  x = my_strlen(str) - 1;
  while (i < x)
    {
      tmp = str[i];
      str[i] = str[x];
      str[x] = tmp;
      i++;
      x--;
    }
  return (str);
}

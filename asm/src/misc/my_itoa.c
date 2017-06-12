/*
** my_itoa.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Wed Mar 29 20:32:42 2017 Hugo Tallineau
** Last update Fri Mar 31 18:09:13 2017 Hugo Tallineau
*/

#include "proto.h"

char    *my_itoa(int nb)
{
  char  *str;
  int   mod;
  int   tmp;

  mod = 1;
  str = my_xmalloc(1);
  if (nb == 0)
    return ((str = my_addchar(my_realloc(str, 1, 1), '0')));
  while (mod <= nb)
    mod *= 10;
  mod /= 10;
  if (nb < 0)
    {
      nb = -nb;
      str = my_addchar(my_realloc(str, 1, 1), '-');
    }
  while (mod >= 1)
    {
      tmp = nb % mod;
      nb = nb / mod;
      str = my_addchar(my_realloc(str, 1, 1), nb + 48);
      nb = tmp;
      mod /= 10;
    }
  return (str);
}

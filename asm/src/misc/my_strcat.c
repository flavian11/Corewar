/*
** my_strcat.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 11:02:07 2017 Hugo Tallineau
** Last update Tue Mar 21 11:22:30 2017 Hugo Tallineau
*/

#include "proto.h"

char    *my_strcat(char *dest, char *src)
{
  int	i;
  int	y;

  i = y = 0;
  while (dest[i] != '\0')
    i++;
  while (src[y] != '\0')
    {
      dest[i + y] = src[y];
      y++;
    }
  dest[i + y] = '\0';
  return (dest);
}

/*
** my_strcpy.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 28 17:02:03 2017 Hugo Tallineau
** Last update Wed Mar 29 18:26:41 2017 Hugo Tallineau
*/

#include "proto.h"

char    *my_strcpy(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  dest = my_xmalloc(my_strlen(src) + 1);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

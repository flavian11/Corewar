/*
** my_xmalloc.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 11:01:11 2017 Hugo Tallineau
** Last update Fri Mar 24 15:45:23 2017 
*/

#include <sys/types.h>
#include "proto.h"

char		*my_memset(char *ptr, int c, size_t len)
{
  size_t	i;

  i = 0;
  while (i != len)
    {
      ptr[i] = c;
      i++;
    }
  return (ptr);
}

char    *my_xmalloc(size_t x)
{
  char	*str;

  if ((str = malloc(sizeof(char) * (x + 1))) == NULL)
    exit(84);
  str = my_memset(str, '\0', x + 1);
  return (str);
}

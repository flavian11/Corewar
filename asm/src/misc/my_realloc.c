/*
** my_realloc.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 11:01:44 2017 Hugo Tallineau
** Last update Sun Mar 26 19:44:21 2017 Hugo Tallineau
*/

#include "proto.h"

char    *my_realloc(char *str, int x, int is_free)
{
  char	*str2;
  int	i;

  i = 0;
  str2 = my_xmalloc(my_strlen(str) + x + 1);
  while (str[i] != '\0')
    {
      str2[i] = str[i];
      i++;
    }
  str2[i] = '\0';
  if (is_free == 1)
    if (str != NULL)
      free(str);
  return (str2);
}

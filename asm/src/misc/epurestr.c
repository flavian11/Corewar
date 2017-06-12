/*
** epurestr.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 10:59:38 2017 Hugo Tallineau
** Last update Fri Mar 24 15:54:17 2017 
*/

#include "proto.h"
#include "op.h"

char		*epurestr(char *str)
{
  char		*buf;
  size_t	i;

  i = 0;
  buf = my_xmalloc(1);
  while (str[i] != '\0')
    {
      if (str[i] == '\t' || str[i] == SEPARATOR_CHAR || str[i] == ' ')
	{
	  buf = my_addchar(my_realloc(buf, 1, 1), ' ');
	  while (str[i] == '\t' || str[i] == SEPARATOR_CHAR || str[i] == ' ')
	    i++;
	  i--;
	}
      else
	buf = my_addchar(my_realloc(buf, 1, 1), str[i]);
      i++;
    }
  free(str);
  return (buf);
}

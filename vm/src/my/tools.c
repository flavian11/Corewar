/*
** tools.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 14:03:47 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 16:59:49 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void            my_memset(void *ptr, char r, size_t len)
{
  size_t        i;

  i = 0;
  while (i < len)
    {
      ((char *)ptr)[i] = r;
      i++;
    }
}

size_t          my_strlen(const char *str)
{
  size_t        i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_strncpy(char *dest, char *src, size_t len)
{
  size_t		i;

  i = 0;
  while (i <= len)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

char            *my_strdup(char *str)
{
  char          *tmp;
  size_t           i;

  i = 0;
  if ((tmp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    exit(84);
  my_memset(tmp, 0, my_strlen(str) + 1);
  while (str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  return (tmp);
}

char    *my_strcpy(char *dest, char *src)
{
  size_t   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

/*
** my_strncmp.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 12:16:57 2017 Hugo Tallineau
** Last update Sun Apr  2 17:15:03 2017 Hugo Tallineau
*/

#include "proto.h"

int		my_strncmp(const char *s1, const char *s2, size_t len)
{
  size_t        i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && i < len)
    i++;
  if (s1[i] == s2[i] || i >= len)
    return (0);
  return (1);
}

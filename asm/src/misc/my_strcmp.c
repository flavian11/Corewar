/*
** my_strcmp.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue Mar 14 00:14:44 2017 
** Last update Sun Apr  2 14:30:55 2017 
*/

#include <stdlib.h>

int		my_strcmp(const char *s, const char *s2)
{
  size_t	i;

  i = 0;
  while (s[i] == s2[i] && s[i] != '\0')
    i++;
  if (s[i] == s2[i])
    return (0);
  return (1);
}

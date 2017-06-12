/*
** my_strcmp.c for emacs in /home/leo.colin-vimard/PSU_2016_minishell1
**
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.net>
**
** Started on  Tue Dec  6 21:02:38 2016 Léo COLIN VIMARD
** Last update Sun Apr  2 15:18:31 2017 Léo COLIN VIMARD
*/

#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int	r;

  r = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[r] != '\0' && s2[r] != '\0' && s1[r] == s2[r])
    r++;
  return (s1[r] - s2[r]);
}

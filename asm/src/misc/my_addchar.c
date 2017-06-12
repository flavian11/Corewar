/*
** my_addchar.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 11:08:03 2017 Hugo Tallineau
** Last update Tue Mar 21 11:16:01 2017 Hugo Tallineau
*/

#include "proto.h"

char    *my_addchar(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  str[i] = c;
  str[i + 1] = '\0';
  return (str);
}

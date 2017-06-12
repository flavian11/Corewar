/*
** get_command.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 11:58:12 2017 Hugo Tallineau
** Last update Fri Mar 24 00:06:00 2017 Hugo Tallineau
*/

#include "proto.h"
#include "op.h"

int	get_command(const char *str)
{
  int	i;
  int	x;
  int	len;

  i = len = x = 0;
  while (str[x] != '\0' && str[x] != ' ' && str[x] != '\t')
    x++;
  while (str[x] != '\0' && (str[x] == ' ' || str[x] == '\t'))
    x++;
  while (str[len + x] != '\0' && str[len + x] != ' ' && str[len + x] != '\t')
    len++;
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strncmp(&str[x], op_tab[i].mnemonique, len - 0) == 0 && str[x]
	  != '\0')
	return (op_tab[i].code);
      i++;
    }
  return (-1);
}

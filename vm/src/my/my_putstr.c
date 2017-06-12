/*
** my_putstr.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 15:21:00 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 15:23:44 2017 Léo COLIN VIMARD
*/

#include "vm.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  size_t	r;

  r = 0;
  while (str[r] != '\0')
    my_putchar(str[r++]);
}

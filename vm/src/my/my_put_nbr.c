/*
** my_put_nbr.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm/src/my
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 23:17:51 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:23:52 2017 Léo COLIN VIMARD
*/

#include "vm.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb / 10 > 0)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

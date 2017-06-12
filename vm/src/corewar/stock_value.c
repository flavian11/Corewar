/*
** stock_value.c for emacs$ in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 04:07:53 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 04:13:00 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void	write_value(t_data *arena, int value, size_t pos, int size)
{
  int	r;

  r = 1;
  while (r <= size)
    {
      arena[(pos + size - r) % MEM_SIZE].data = value % 256;
      value = value / 256;
      r++;
    }
}

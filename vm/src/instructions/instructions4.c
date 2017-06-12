/*
** functions4.c for emacs in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 03:22:55 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 16:38:47 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void	aff(t_data *arena, t_list *tmp, t_list *processes)
{
  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 2) % MEM_SIZE;
  write(1, &tmp->champ.regs[arena[tmp->champ.pos].data - 1], 1);
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  tmp->champ.wait = 2;
}

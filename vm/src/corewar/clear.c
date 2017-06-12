/*
** clear.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 13:53:46 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:24:18 2017 Léo COLIN VIMARD
*/

#include "vm.h"
#include "op.h"

void    clear_battlefield(t_data *arena, t_list *processes)
{
  t_list        *tmp;

  tmp = processes;
  free(arena);
  while (processes->next != NULL)
    {
      tmp = processes->next;
      free(processes->champ.name);
      free(processes->champ.comment);
      free(processes->champ.path);
      free(processes->champ.regs);
      free(processes);
      processes = tmp->next;
    }
  free(processes->champ.name);
  free(processes->champ.comment);
  free(processes->champ.path);
  free(processes->champ.regs);
  free(processes);
}

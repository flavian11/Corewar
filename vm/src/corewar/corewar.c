/*
** corewar.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 13:51:01 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:32:07 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void    do_something(t_data *arena, t_list *tmp, t_list *processes)
{
  void (*functions[16])(t_data *, t_list *, t_list *);

  functions[0] = live;
  functions[1] = ld;
  functions[2] = st;
  functions[3] = add;
  functions[4] = sub;
  functions[5] = and;
  functions[6] = or;
  functions[7] = xor;
  functions[8] = zjmp;
  functions[9] = ldi;
  functions[10] = sti;
  functions[11] = fork_i;
  functions[12] = lld;
  functions[13] = lldi;
  functions[14] = lfork;
  functions[15] = aff;
  functions[arena[tmp->champ.pos].data - 1](arena, tmp, processes);
}

void    refresh_processes(t_data *arena, t_list *processes)
{
  t_list        *tmp;

  tmp = processes;
  while (tmp != NULL)
    {
      if (tmp->champ.wait == 0)
        do_something(arena, tmp, processes);
      else
        tmp->champ.wait--;
      tmp = tmp->next;
    }
}

void     if_you_want_peace_prepare_for_war(t_data *arena, t_list *processes)
{
  int   cycles;
  int   total_cycles;
  int   cycle_to_die;
  int   nbr_live;

  cycle_to_die = CYCLE_TO_DIE;
  total_cycles = 0;
  while (still_no_winner(processes) == 1)
    {
      cycles = 0;
      while (cycles < cycle_to_die)
        {
          refresh_processes(arena, processes);
          cycles++;
          total_cycles++;
        }
      if (nbr_live > NBR_LIVE)
        {
          nbr_live = 0;
          cycle_to_die -= CYCLE_DELTA;
        }
      nbr_live += is_it_the_end(processes);
    }
  print_winner(processes);
}

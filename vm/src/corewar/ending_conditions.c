/*
** ending_conditions.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 13:55:15 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:27:28 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

int     still_no_winner(t_list *processes)
{
  int           nbr;
  t_list        *tmp;

  nbr = 0;
  tmp = processes;
  while (tmp != NULL)
    {
      if (tmp->champ.alive != -1)
          nbr++;
      tmp = tmp->next;
    }
  if (nbr <= 1)
    return (0);
  return (1);
}

int     is_it_the_end(t_list *processes)
{
  t_list        *tmp;
  int           res;

  (void)processes;
  res = 0;
  while (tmp != NULL)
    {
      if (tmp->champ.alive > 0)
        {
          res += tmp->champ.alive;
          tmp->champ.alive = 0;
        }
      else
        tmp->champ.alive = -1;
      tmp = tmp->next;
    }
  return (res);
}

void    print_winner(t_list *processes)
{
  t_list        *tmp;

  tmp = processes;
  while (tmp->next != NULL && tmp->champ.alive == -1)
    tmp = tmp->next;
  if (tmp->champ.alive == -1)
    my_putstr("No more champ alive\n");
  else
    {
      my_putstr("The player ");
      my_put_nbr(tmp->champ.nbr);
      my_putstr(tmp->champ.name);
      my_putstr(" is alive\n");
    }
}

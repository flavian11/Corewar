/*
** main.c for emacs in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Mon Mar 27 14:01:24 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 22:29:05 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

int	main(int ac, char **av)
{
  t_data	*arena;
  t_list	*processes;
  char		**champ_tab;

  (void)ac;
  champ_tab = get_champ(av);
  processes = make_list(my_det_wordtab_length(champ_tab) - 1, champ_tab);
  if (processes == NULL)
    return (84);
  arena = set_arena(processes);
  if (arena == NULL)
    return (84);
  if_you_want_peace_prepare_for_war(arena, processes);
  //  clear_battlefield(arena, processes);
}

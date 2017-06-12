/*
** set_arena.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 13:42:13 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:32:34 2017 Léo COLIN VIMARD
*/

#include "vm.h"
#include "op.h"

t_data     *add_champ_to_arena(t_champ champ, t_data *arena)
{
  int   fd;
  char  i[2];
  int   r;

  r = champ.pos - 1;
  fd = open(champ.path, O_RDONLY);
  lseek(fd, sizeof(header_t) - 1, SEEK_CUR);
  while (read(fd, i, 1) > 0)
    {
      arena[r % MEM_SIZE].data = i[0];
      arena[r % MEM_SIZE].champ_n = champ.nbr;
      r++;
    }
  return (arena);
}

t_data			*set_arena(t_list *processes)
{
  t_data		*arena;
  t_list		*tmp;
  unsigned int           r;

  r = 0;
  arena = malloc(sizeof(t_data) * MEM_SIZE);
  if (arena == NULL)
    exit(84);
  tmp = processes;
  r = 0;
  while (r < MEM_SIZE)
    {
      arena[r].data = arena[r].champ_n = 0;
      r++;
    }
  while (tmp != NULL)
    {
      arena = add_champ_to_arena(tmp->champ, arena);
      tmp = tmp->next;
    }
  return (arena);
}

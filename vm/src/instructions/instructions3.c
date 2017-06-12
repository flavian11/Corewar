/*
** functions3.c for emacs in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 03:22:42 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 21:22:44 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void	sti(t_data *arena, t_list *tmp, t_list *processes)
{
  int   *args;
  int   value1;
  int   value2;
  int   value3;

  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  args[1] += 3;
  args[2] += 3;
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  value3 = get_value(arena, tmp->champ.pos, args, 2);
  write_value(arena, tmp->champ.regs[value1 - 1],
	      tmp->champ.pos + (value2 + value3 - 1) % IDX_MOD, REG_SIZE);
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 25;
}

void	fork_i(t_data *arena, t_list *tmp, t_list *processes)
{
  t_list	*new;
  int		*args;
  int		value1;

  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  new = processes;
  while (new != NULL)
    new = new->next;
  new->next = malloc(sizeof(t_list) * 1);
  if (new->next == NULL)
    exit(84);
  new = new->next;
  new->champ.name = tmp->champ.name;
  new->champ.comment = tmp->champ.comment;
  new->champ.pos = (tmp->champ.pos + value1 % IDX_MOD) % MEM_SIZE;
  new->champ.regs = tmp->champ.regs;
  new->champ.nbr = tmp->champ.nbr;
  new->champ.alive = tmp->champ.alive;
  new->next = NULL;
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 80;
}

void	lld(t_data *arena, t_list *tmp, t_list *processes)
{
  int   *args;
  int   value1;
  int   value2;

  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  if (value2 <= REG_NUMBER)
    tmp->champ.regs[value2 - 1] = value1;
  else
    exit(84);
 tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 5;
}

void	lldi(t_data *arena, t_list *tmp, t_list *processes)
{
  int   *args;
  int   value1;
  int   value2;
  int   value3;
  int   res;

  (void)processes;
  res = 0;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  value3 = get_value(arena, tmp->champ.pos, args, 2);
  value1 += value2;
  tmp->champ.regs[value3 - 1] =
    read_value(arena, tmp->champ.pos + (value1 - 1) % IDX_MOD, IND_SIZE);
  tmp->champ.pos = (tmp->champ.pos + res) % MEM_SIZE;
  tmp->champ.wait = 50;
}

void	lfork(t_data *arena, t_list *tmp, t_list *processes)
{
  t_list        *new;
  int           *args;
  int           value1;

  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  new = processes;
  while (new != NULL)
    new = new->next;
  new->next = malloc(sizeof(t_list) * 1);
  if (new->next == NULL)
    exit(84);
  new = new->next;
  new->champ.name = tmp->champ.name;
  new->champ.comment = tmp->champ.comment;
  new->champ.pos = (tmp->champ.pos + value1) % MEM_SIZE;
  new->champ.regs = tmp->champ.regs;
  new->champ.nbr = tmp->champ.nbr;
  new->champ.alive = tmp->champ.alive;
  new->next = NULL;
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 1000;
}

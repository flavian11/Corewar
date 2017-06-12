/*
** functions2.c for emacs in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 03:22:32 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 21:42:23 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void	and(t_data *arena, t_list *tmp, t_list *processes)
{
  int	*args;
  int	value1;
  int	value2;
  int	value3;
  int	res;

  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  value3 = get_value(arena, tmp->champ.pos, args, 2);
  res = value1 & value2;
  tmp->champ.regs[value3 - 1] = res;
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 6;
}

void	or(t_data *arena, t_list *tmp, t_list *processes)
{
  int   *args;
  int   value1;
  int   value2;
  int   value3;
  int	res;

  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  value3 = get_value(arena, tmp->champ.pos, args, 2);
  res = value1 | value2;
  tmp->champ.regs[value3 - 1] = res;
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 6;
}

void	xor(t_data *arena, t_list *tmp, t_list *processes)
{
  int   *args;
  int   value1;
  int   value2;
  int   value3;
  int	res;

  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  value3 = get_value(arena, tmp->champ.pos, args, 2);
  res = value1 ^ value2;
  tmp->champ.regs[value3 - 1] = res;
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 6;
}

void	zjmp(t_data *arena, t_list *tmp, t_list *processes)
{
  unsigned char	value1;
  unsigned char	value2;
  int		res;

  (void)processes;
  value1 = arena[(tmp->champ.pos + 1) % MEM_SIZE].data;
  value2 = arena[(tmp->champ.pos + 2) % MEM_SIZE].data;
  if (value1 == 255)
    res = value2 - 256;
  else
    res = value2;
  tmp->champ.pos = (tmp->champ.pos + res) % MEM_SIZE;
  tmp->champ.wait = 20;
}

void	ldi(t_data *arena, t_list *tmp, t_list *processes)
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
  tmp->champ.wait = 25;
}

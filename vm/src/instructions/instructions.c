/*
** functions.c for emacs in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 03:22:19 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:26:31 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

void	live(t_data *arena, t_list *tmp, t_list *processes)
{
  t_list	*i;

  i = processes;
  tmp->champ.pos = (tmp->champ.pos + 4) % MEM_SIZE;
  while (i != NULL)
    {
      if (i->champ.nbr == arena[tmp->champ.pos].data)
	tmp->champ.alive++;
      i = i->next;
    }
  my_putstr("The player ");
  my_put_nbr(tmp->champ.nbr);
  my_putstr(tmp->champ.name);
  my_putstr(" is alive\n");
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  tmp->champ.wait = 10;
}

void	ld(t_data *arena, t_list *tmp, t_list *processes)
{
  int	*args;
  int	value1;
  int	value2;

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

void	st(t_data *arena, t_list *tmp, t_list *processes)
{
  int	*args;
  int	value1;
  int	value2;

  (void)processes;
  tmp->champ.pos = (tmp->champ.pos + 1) % MEM_SIZE;
  args = decode_coding_byte(arena[tmp->champ.pos].data);
  value1 = get_value(arena, tmp->champ.pos, args, 0);
  value2 = get_value(arena, tmp->champ.pos, args, 1);
  if (args[1] == 1)
    tmp->champ.regs[value2 - 1] = value1;
  else
    write_value(arena, tmp->champ.pos + value1, value2, REG_SIZE);
  tmp->champ.pos = change_pos(arena, tmp->champ.pos, args);
  tmp->champ.wait = 5;
}

void	add(t_data *arena, t_list *tmp, t_list *processes)
{
  t_list        *i;
  int	res;

  i = processes;
  res = tmp->champ.regs[(int)arena[(tmp->champ.pos + 2) % MEM_SIZE].data] +
    tmp->champ.regs[(int)arena[(tmp->champ.pos + 3) % MEM_SIZE].data];
   while (i != NULL)
    {
      if (i->champ.nbr == tmp->champ.nbr)
	i->champ.regs[(int)arena[(tmp->champ.pos + 4) % MEM_SIZE].data] = res;
      i = i->next;
    }
   tmp->champ.pos = (tmp->champ.pos + 5) % MEM_SIZE;
   tmp->champ.wait = 10;
}

void	sub(t_data *arena, t_list *tmp, t_list *processes)
{
  t_list        *i;
  int   res;

  i = processes;
  res = tmp->champ.regs[(int)arena[(tmp->champ.pos + 2) % MEM_SIZE].data] -
    tmp->champ.regs[(int)arena[(tmp->champ.pos + 3) % MEM_SIZE].data];
   while (i != NULL)
    {
      if (i->champ.nbr == tmp->champ.nbr)
        i->champ.regs[(int)arena[(tmp->champ.pos + 4) % MEM_SIZE].data] = res;
      i = i->next;
    }
   tmp->champ.pos = (tmp->champ.pos + 5) % MEM_SIZE;
   tmp->champ.wait = 10;
}

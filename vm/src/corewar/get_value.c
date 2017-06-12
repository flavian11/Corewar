/*
** get_value.c for emacs in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 03:23:13 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 21:45:48 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

int	read_value(t_data *arena, size_t pos, int size)
{
  int	res;

  (void)size;
  res = 0;
  res = arena[(pos + 1) % MEM_SIZE].data * 255;
  res = res + arena[(pos + 2) % MEM_SIZE].data;
  return (res);
}

int	move_forward(int *args, int nb)
{
  int	r;
  int	i;

  i = 0;
  r = 0;
  while (i < nb)
    {
      if (args[i] == 1 || args[i] == 4)
	r += 1;
      else if (args[i] == 2)
        r += 4;
      else if (args[i] >= 3)
        r += 2;
      i++;
    }
  return (r);
}

size_t	change_pos(t_data *arena, size_t pos, int *args)
{
  int   r;
  int   i;

  i = 0;
  r = 0;
  (void)arena;
  while (args[i] != -1)
    {
      if (args[i] == 1 || args[i] == 4)
        r += 1;
      else if (args[i] == 2)
        r += 4;
      else if (args[i] >= 3)
        r += 2;
      i++;
    }
  pos = (pos + r + 1) % MEM_SIZE;
  return (pos);
}

int	get_ind_value(t_data *arena, size_t pos, int add)
{
  int	res;

  res = 0;
  pos = (pos + add - 1) % MEM_SIZE;
  if (arena[pos].data == 255)
    res = arena[pos].data - arena[pos + 1 % MEM_SIZE].data - 1;
  else
    res = arena[pos].data * 255 + arena[pos + 1 % MEM_SIZE].data;
  return (res);
}

int	get_value(t_data *arena, size_t pos, int *args, int nb)
{
  int	r;
  int	i;
  int	res;

  res = 0;
  r = move_forward(args, nb);
  pos = (pos + r) % MEM_SIZE;
  if (args[nb] == 1 || args[nb] == 4)
    r = i = 1;
  else if (args[nb] == 2)
    r = i = 4;
  else
    r = i = 2;
  while (r > 0)
    {
      res += arena[(pos + r) % MEM_SIZE].data;
      r--;
    }
  if (args[nb] == 3 || args[nb] == 6)
    return (get_ind_value(arena, pos, res));
  return (res);
}


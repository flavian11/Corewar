/*
** decode_coding_byte.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue Mar 28 17:04:08 2017 
** Last update Sun Apr  2 21:45:13 2017 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	*decode_coding_byte(char nb)
{
  int	*res;
  int	i;
  int	x;
  int	tmp;

  x = 0;
  i = 6;
  res = malloc(sizeof(int) * 4);
  if (res == NULL)
    exit(84);
  res[3] = -1;
  while (x != 3)
    {
      tmp = (int)nb;
      tmp = tmp >> i;
      res[x++] = tmp;
      nb = nb - (tmp << i);
      i -= 2;
    }
  return (res);
}

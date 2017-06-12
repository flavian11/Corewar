/*
** my_str_to_wordtab.c for vm in /home/ZephX/Documents/CPE/corewar/vm_badass/vm
** 
** Made by Marigonez Estéban
** Login   <esteban.marigonez@epitech.eu>
** 
** Started on  Tue Mar 28 20:03:45 2017 Marigonez Estéban
** Last update Sun Apr  2 23:30:52 2017 Léo COLIN VIMARD
*/

#include "vm.h"

static int       find_biggest_line(char  *str)
{
  int            i;
  int            stack;
  int            len;

  i = stack = len = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
        {
          if (len < stack)
            len = stack;
          stack = 0;
        }
      i++;
      stack++;
    }
  if (len < stack)
    len = stack;
  return (len + 2);
}

static int     find_nb_line(char *str)
{
  int          nb_l;
  int          i;

  i = nb_l = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
        nb_l++;
      i++;
    }
  nb_l++;
  return (nb_l);
}

char**  my_str_to_wordtab(char *str)
{
  int   x;
  int   len;
  int   nb_l;
  int   y;
  char  **tab;
  int   i;

  i = x = y = 0;
  len = find_biggest_line(str);
  nb_l = find_nb_line(str);
  if ((tab = malloc(sizeof(char*) * (nb_l + 1))) == NULL)
    exit(84);
  while (y < nb_l)
    {
      if ((tab[y] = malloc(sizeof(char) * (len + 1))) == NULL)
        exit(84);;
      my_memset(tab[y], '\0', len + 1);
      while (str[i] != ' ' && str[i] != '\0')
        tab[y][x++] = str[i++];
      x = 0;
      i++;
      y++;
    }
  tab[y] = NULL;
  return (tab);
}

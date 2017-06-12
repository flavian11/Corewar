/*
** delete_line_in_array.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Wed Mar 29 16:32:16 2017 Hugo Tallineau
** Last update Sun Apr  2 22:42:51 2017 
*/

#include "proto.h"

char    **delete_line(char **tab, int x)
{
  free(tab[x]);
  tab[x] = my_xmalloc(sizeof(char) * 2);
  tab[x][0] = -1;
  tab[x][1] = 0;
  return (tab);
}

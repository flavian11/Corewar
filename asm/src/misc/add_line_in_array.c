/*
** add_line_in_array.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Wed Mar 29 16:31:51 2017 Hugo Tallineau
** Last update Wed Mar 29 16:32:03 2017 Hugo Tallineau
*/

#include "proto.h"

char    **add_line_in_array(char **label)
{
  char  **tab;
  int   x;

  x = 0;
  while (label[x] != NULL)
    x++;
  if ((tab = malloc(sizeof(char*) * (x + 2))) == NULL)
    exit(84);
  tab[x + 1] = NULL;
  x = 0;
  while (label[x] != NULL)
    {
      tab[x] = my_strcpy(label[x]);
      my_xfree(label[x]);
      x++;
    }
  tab[x] = my_xmalloc(1);
  free(label);
  return (tab);
}

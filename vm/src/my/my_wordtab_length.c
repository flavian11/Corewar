/*
** my_wordtab_length.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 17:10:19 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 17:11:39 2017 Léo COLIN VIMARD
*/

#include "vm.h"

int	my_det_wordtab_length(char **tab)
{
  int	r;

  r = 0;
  while (tab[r] != NULL)
    r++;
  return (r + 1);
}

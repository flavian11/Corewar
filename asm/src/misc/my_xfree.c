/*
** my_xfree.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Mar 26 19:47:22 2017 Hugo Tallineau
** Last update Sun Mar 26 19:48:26 2017 Hugo Tallineau
*/

#include <stdlib.h>

void	my_xfree(char *str)
{
  if (str != NULL)
    free(str);
}

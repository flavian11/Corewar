/*
** set_label_array.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/label
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 28 16:48:48 2017 Hugo Tallineau
** Last update Tue Mar 28 17:00:07 2017 Hugo Tallineau
*/

#include "proto.h"

char	**set_label_array(void)
{
  char	**label;

  if ((label = malloc(sizeof(char*) * 1)) == NULL)
    exit(84);
  label[0] = NULL;
  return (label);
}

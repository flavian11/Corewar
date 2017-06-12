/*
** write_in_cor.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 27 13:35:58 2017 
** Last update Sun Apr  2 20:13:32 2017 Hugo Tallineau
*/

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "struct.h"
#include "proto.h"
#include "macro.h"

void	my_write_in_cor(t_info info, const int fd)
{
  int	i;

  i = 0;
  while (op_tab[i].code != info.instruc_code)
    i++;
  op_tab[i].check(info);
  op_tab[i].writer(info, fd);
}

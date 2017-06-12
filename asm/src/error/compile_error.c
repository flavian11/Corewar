/*
** compile_error.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Fri Mar 31 14:32:03 2017 
** Last update Fri Mar 31 14:38:10 2017 
*/

#include <unistd.h>
#include "proto.h"

void	compile_error(void)
{
  my_putstr("compile error\n", 2);
  exit(84);
}

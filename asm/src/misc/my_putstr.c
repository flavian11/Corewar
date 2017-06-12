/*
** my_putstr.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/misc
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 13 22:27:27 2017 
** Last update Thu Mar 23 23:49:29 2017 
*/

#include <unistd.h>
#include "proto.h"

void	my_putstr(const char *str, int fd)
{
  write(fd, str, my_strlen(str));
}

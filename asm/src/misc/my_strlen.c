/*
** my_strlen.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/misc
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 13 22:28:31 2017 
** Last update Tue Mar 14 00:05:01 2017 
*/

#include <sys/types.h>

size_t		my_strlen(const char *str)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

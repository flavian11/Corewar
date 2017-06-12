/*
** aff_usage.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 13 22:00:20 2017 
** Last update Sun Apr  2 17:06:36 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "proto.h"

void	aff_usage(const char *binary_name)
{
  my_putstr("USAGE\n\t", STDOUT_FILENO);
  my_putstr(binary_name, STDOUT_FILENO);
  my_putstr(" file_name[.s]\n", STDOUT_FILENO);
  my_putstr("\nDESCRIPTION\n", STDOUT_FILENO);
  my_putstr("\tfile_name\tfile in assembly language to be ", STDOUT_FILENO);
  my_putstr("converted into file_name.cor, an\n", STDOUT_FILENO);
  my_putstr("\t\t\texecutable in the Virtual Machine.\n", STDOUT_FILENO);
}

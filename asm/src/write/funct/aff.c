/*
** aff.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src/write/funct
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Wed Mar 29 15:11:52 2017 
** Last update Sun Apr  2 20:13:15 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "struct.h"
#include "macro.h"
#include "proto.h"
#include "op.h"

void	write_aff(const t_info info, const int fd)
{
  write(fd, &info.instruc_code, 1);
  write(fd, &info.coding_byte, 1);
  write(fd, &info.arg[0], 1);
  g_size += 3;
}

void	check_aff(const t_info info)
{
  if (info.arg[0] != REGISTER)
    compile_error();
}

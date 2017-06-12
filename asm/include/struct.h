/*
** struct.h for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue Mar 14 17:47:56 2017 
** Last update Sun Apr  2 16:33:25 2017 Hugo Tallineau
*/

#ifndef COR_STRUCT_H
# define COR_STRUCT_H

typedef struct s_info	t_info;

struct		s_info
{
  int	coding_byte;
  int	nb_args;
  int	instruc_code;
  int 	arg_code[4];
  int	fd;
  long 	arg[4];
};

#endif

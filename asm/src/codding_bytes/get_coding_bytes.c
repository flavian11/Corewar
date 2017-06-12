/*
** coding_bytes.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue Mar 14 23:37:45 2017 
** Last update Sun Apr  2 19:10:41 2017 Hugo Tallineau
*/

#include "proto.h"
#include "struct.h"

int	get_param_code_next(char *str, int i, t_info **info, int c)
{
  (*info)->arg[c] = my_getnbr(&str[i]);
  if ((*info)->arg[c] < -1)
    (*info)->arg[c] = (*info)->arg[c] + 1;
  return (3);
}

int     get_param_code(char *str, int i, t_info **info, int c)
{
  if (str[i] == 'r' && str[i + 1] >= '0' && str[i + 1] <= '9' &&
      my_getnbr(&str[i + 1]) <= REG_NUMBER)
    {
      (*info)->arg[c] = my_getnbr(&str[i + 1]);
      return (1);
    }
  else if (str[i] == DIRECT_CHAR)
    {
      if (str[i + 1] == LABEL_CHAR)
	(*info)->arg[c] = 42;
      else
	{
	  (*info)->arg[c] = my_getnbr(&str[i + 1]);
	  if ((*info)->arg[c] < 0)
	    (*info)->arg[c] = (*info)->arg[c] + 1;
	}
      return (2);
    }
  else if (str[i] != '\0')
    return (get_param_code_next(str, i, info, c));
  else
    return (-1);
}

int	check_fourth_param(char *str, int i)
{
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  i = (str[i] == '\0') ? i : i + 1;
  if (str[i] != '\0')
    return (1);
  else
    return (0);
}

void     fill_params_array(char *str, int *params, t_info **info)
{
  int   i;

  i = 0;
  params[0] = get_param_code(str, i, info, 0);
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  i = (str[i] == '\0') ? i : i + 1;
  if (str[i] != '\0')
    params[1] = get_param_code(str, i, info, 1);
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  i = (str[i] == '\0') ? i : i + 1;
  if (str[i] != '\0')
    params[2] = get_param_code(str, i, info, 2);
  if (check_fourth_param(str, i) == 1)
    compile_error();
  i = 0;
  while (params[i] != -1)
    i++;
  (*info)->nb_args = i;
}

void     get_coding_bytes(char *str, t_info *info, int fd_cor)
{
  int   params[4];
  int   x;

  x = 0;
  if ((info->instruc_code = get_command(str)) == -1)
    {
      info->coding_byte = 0;
      return ;
    }
  params[0] = params[1] = params[2] = params[3] = -1;
  while (str[x] != '\0' && str[x] != ' ' && str[x] != '\t')
    x++;
  while (str[x] != '\0' && (str[x] == ' ' || str[x] == '\t'))
    x++;
  while (str[x] != '\0' && str[x] != ' ' && str[x] != '\t')
    x++;
  x = (str[x] == '\0') ? x : x + 1;
  fill_params_array(&str[x], params, &info);
  info->arg_code[0] = params[0];
  info->arg_code[1] = params[1];
  info->arg_code[2] = params[2];
  info->arg_code[3] = params[3];
  info->coding_byte = get_byte(params);
  info->fd = fd_cor;
}

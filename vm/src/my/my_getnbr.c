/*
** my_getnbr.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 14:10:00 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 14:11:07 2017 Léo COLIN VIMARD
*/

#include "vm.h"
#include "op.h"

int             my_getnbr(char *str)
{
  t_getnbr      vars;

  vars.i = vars.nb = vars.neg = vars.err = 0;
  (str[vars.i] == '-') ? (vars.neg = 1) : 0;
  while (str[vars.i] != '\0')
    {
      if (str[vars.i] >= '0' && str[vars.i] <= '9')
        {
          vars.err = 1;
          while (str[vars.i] >= '0' && str[vars.i] <= '9'
                 && str[vars.i] != '\0')
            {
              vars.nb = vars.nb + str[vars.i++] - '0';
              vars.nb *= 10;
            }
          break;
        }
      vars.i++;
    }
  vars.nb /= 10;
  if (vars.neg == 1)
    vars.nb *= -1;
  if (vars.err == 0)
    return (-666);
  return (vars.nb);
}


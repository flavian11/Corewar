/*
** main.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm/src
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 13 21:58:22 2017 
** Last update Sun Apr  2 22:17:55 2017 
*/

#include <unistd.h>
#include "proto.h"
#include "macro.h"

int	main(int ac, char **av)
{
  int	fd_cor;

  if (ac != 2)
    {
      aff_usage(av[0]);
      return (EXIT_ERROR);
    }
  if (my_strcmp(av[1], "-h") == 0)
    {
      aff_usage(av[0]);
      return (EXIT_SUCCESS);
    }
  av[1] = my_revstr(av[1]);
  if (my_strncmp(av[1], "s.", 2) != 0)
    return (84);
  av[1] = my_revstr(av[1]);
  fd_cor = create_file(av[1]);
  if (fd_cor == -1)
    return (EXIT_ERROR);
  if (read_file(av[1], fd_cor) == -1)
    return (EXIT_ERROR);
  close(fd_cor);
  return (EXIT_SUCCESS);
}

/*
** add_champ.c for vm in /home/ZephX/Documents/CPE/corewar/vm_badass/vm
** 
** Made by Marigonez Estéban
** Login   <esteban.marigonez@epitech.eu>
** 
** Started on  Tue Mar 28 16:42:27 2017 Marigonez Estéban
** Last update Sun Apr  2 16:41:45 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

t_champ		add_champ(char *file, int nbr, size_t pos)
{
  t_champ	chp;
  header_t	hdr;

  hdr = fill_header(file);
  (void)hdr;
  chp = fill_n_c(file);
  chp.pos = pos;
  if ((chp.regs = malloc(sizeof(int) * (REG_NUMBER))) == NULL)
    exit(84);
  my_memset(chp.regs, 0, sizeof(chp.regs));
  chp.regs[0] = nbr;
  chp.nbr = nbr;
  chp.wait = 0;
  chp.alive = 0;
  chp.path = my_strdup(file);
  return (chp);
}

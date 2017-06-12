/*
** fill.c for emacs in /home/leo.colin-vimard/repo/CPE_2016_corewar/vm
** 
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
** 
** Started on  Sun Apr  2 14:03:05 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 15:17:51 2017 Léo COLIN VIMARD
*/

#include "op.h"
#include "vm.h"

header_t        fill_header(char *file)
{
  header_t      hdr;
  int           fd;
  int           err;

  if ((fd = open(file, O_RDONLY)) == -1)
    exit(84);
  if ((err = read(fd, &hdr, sizeof(header_t))) == -1)
    exit(84);
  close(fd);
  return (hdr);
}

t_champ         fill_n_c(char  *file)
{
  t_champ       chp;
  header_t      hdr;
  size_t        len;

  hdr = fill_header(file);
  len = my_strlen(hdr.prog_name);
  if ((chp.name = malloc(sizeof(char) * (len + 1))) == NULL)
    exit(84);
  my_memset(chp.name, 0, len + 1);
  chp.name = my_strncpy(chp.name, hdr.prog_name, len);
  len = my_strlen(hdr.comment);
  if ((chp.comment = malloc(sizeof(char) * (len + 1))) == NULL)
    exit(84);
  my_memset(chp.comment, 0, sizeof(chp.comment));
  chp.comment = my_strncpy(chp.comment, hdr.comment, len);
  return (chp);
}

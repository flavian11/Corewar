/*
** read_file.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Tue Mar 21 10:06:12 2017 
** Last update Sun Apr  2 20:13:04 2017 Hugo Tallineau
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "op.h"
#include "struct.h"
#include "proto.h"

void	convert(t_info *info)
{
  int	i;

  i = 0;
  while (info->arg_code[i] != -1)
    {
      info->arg[i] = convert_big_endian(info->arg[i]);
      i++;
    }
}

void    free_stuff(char **label, char *buff)
{
  int   i;

  i = 0;
  while (label[i] != NULL)
    {
      my_xfree(label[i]);
      i++;
    }
  free(label);
  my_xfree(buff);
}

int		read_file(const char *filename, const int fd_cor)
{
  t_info	info;
  int		fd_s;
  char		*buff;
  header_t	header;
  char		**label;

  g_size = g_old_size = 0;
  label = set_label_array();
  fd_s = open(filename, O_RDONLY);
  if (fd_s == -1)
    return (-1);
  header = build_header(fd_s, fd_cor);
  while ((buff = get_next_valide_line(fd_s)) != NULL)
    {
      buff = epurestr(buff);
      get_coding_bytes(buff, &info, fd_cor);
      if (info.coding_byte != 0)
	my_write_in_cor(info, fd_cor);
      label = try_find_label(buff, label, fd_cor, info);
      my_xfree(buff);
      g_old_size = g_size;
    }
  write_prog_size(fd_cor, header);
  free_stuff(label, buff);
  return (0);
}

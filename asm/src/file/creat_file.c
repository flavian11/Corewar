/*
** creat_file.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 20 16:28:33 2017 
** Last update Sun Apr  2 01:26:16 2017 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "proto.h"

char		*change_name(char *filename)
{
  char		*cor_name;
  size_t	i;
  size_t	y;

  i = y = 0;
  cor_name = malloc(sizeof(char) * (my_strlen(filename) + 3));
  if (cor_name == NULL)
    exit(84);
  cor_name[i++] = 'r';
  cor_name[i++] = 'o';
  cor_name[i++] = 'c';
  cor_name[i++] = '.';
  filename = my_revstr(filename);
  while (filename[y++] != '.');
  while (filename[y] != '\0')
    {
      cor_name[i] = filename[y];
      i++;
      y++;
    }
  cor_name[i] = '\0';
  cor_name = my_revstr(cor_name);
  return (cor_name);
}

int	create_file(char *filename)
{
  char	*cor_name;
  int	fd;

  cor_name = change_name(filename);
  if (cor_name == NULL)
    return (-1);
  fd = open(cor_name, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
  free(cor_name);
  filename = my_revstr(filename);
  return (fd);
}

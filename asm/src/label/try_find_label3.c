/*
** try_find_label3.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/label
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Apr  2 16:20:54 2017 Hugo Tallineau
** Last update Sun Apr  2 23:42:19 2017 Hugo Tallineau
*/

#include <unistd.h>
#include <sys/types.h>
#include "proto.h"

void    jump_and_write(const char *call, const char *label, int fd)
{
  int   i;
  int   i2;
  int   y;
  int   pos;
  int   n;
  int   gap;
  off_t cur;

  cur = lseek(fd, 0, SEEK_CUR);
  i = y = gap = n = i2 = 0;
  while (call[i++] != LABEL_CHAR && call[i - 1] != '\0');
  if (i > 0 && call[i - 1] == '\0')
    return ;
  while (label[y++] != LABEL_CHAR && label[y - 1] != '\0');
  if (y > 0 && label[y - 1] == '\0')
    return ;
  i2 = (int)my_getnbr(&call[i]);
  y = (int)my_getnbr(&label[y]);
  while (call[i++] != LABEL_CHAR && call[i - 1] != '\0');
  pos = (int)my_getnbr(&call[i]);
  gap = y - pos;
  lseek(fd, sizeof(header_t) + i2, SEEK_SET);
  gap = convert_big_endian(gap);
  write(fd, &gap, 2);
  lseek(fd, cur, SEEK_SET);
}

char    **check_previous_call(char **tab, const char *label, int fd)
{
  int   x;
  int   len;

  x = len = 0;
  while (label[len] != '\0' && label[len] != LABEL_CHAR)
    len++;
  while (tab[x] != NULL)
    {
      if (tab[x][0] == LABEL_CHAR && tab[x][0] != -1)
	{
	  if (my_strncmp(label, &tab[x][1], len) == 0)
	    {
	      jump_and_write(&tab[x][1], label, fd);
	      tab = delete_line(tab, x);
	      x = -1;
	    }
	}
      x++;
    }
  return (tab);
}

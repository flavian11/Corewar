/*
** add_size.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/label
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Apr  2 16:19:34 2017 Hugo Tallineau
** Last update Sun Apr  2 23:32:54 2017 Hugo Tallineau
*/

#include <sys/types.h>
#include <unistd.h>
#include "proto.h"

void    write_diff(int pos, int fd, char *line, t_info info)
{
  off_t cur;
  int   a;
  int   b;

  a = 255;
  b = 255 - ((g_size - get_arg_rank(line, info, 0)) - pos - 1);
  while (b < 0)
    {
      a--;
      b = b + 256;
    }
  cur = lseek(fd, 0, SEEK_CUR);
  lseek(fd, cur - (get_arg_rank(line, info, 1)), SEEK_SET);
  write(fd, &a, 1);
  write(fd, &b, 1);
  lseek(fd, cur, SEEK_SET);
}

char    *add_size_call(char *label, char *line, t_info info)
{
  char  *size_a;
  char  *pos_call;

  size_a = my_itoa(g_size - get_arg_rank(line, info, 1));
  label = my_realloc(label, my_strlen(size_a) + 1, 1);
  label = my_strcat(label, size_a);
  label = my_addchar(label, ':');
  pos_call = my_itoa(g_size - get_arg_rank(line, info, 0));
  label = my_realloc(label, my_strlen(pos_call) + 1, 1);
  label = my_strcat(label, pos_call);
  free(size_a);
  free(pos_call);
  return (label);
}

char    *add_size_label(char *label)
{
  char  *size_a;

  size_a = my_itoa(g_old_size);
  label = my_realloc(label, my_strlen(size_a) + 1, 1);
  label = my_strcat(label, size_a);
  free(size_a);
  return (label);
}

int     is_label_here(char **label, char *buf)
{
  int   x;
  int   s;

  x = s = 0;
  while (buf[s] != '\0' && buf[s] != ' ')
    s++;
  while (label[x] != NULL)
    {
      if (label[x][0] != '\0' && label[x][0] != LABEL_CHAR)
	if (my_strncmp(label[x], buf, s) == 0)
	  return (x);
      x++;
    }
  return (0);
}

int     is_coding_byte(t_info info)
{
  if (info.instruc_code == 1 || info.instruc_code == 9 ||
      info.instruc_code == 12 || info.instruc_code == 15)
    return (0);
  else
    return (1);
}

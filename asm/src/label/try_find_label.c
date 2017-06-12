/*
** try_find_label.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/label
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 28 16:51:08 2017 Hugo Tallineau
** Last update Sun Apr  2 16:41:28 2017 Hugo Tallineau
*/

#include <sys/types.h>
#include <unistd.h>
#include "proto.h"

int	getsize(t_info info, int nb_arg, int l)
{
  int	res;
  int	i;

  if (l == 1)
    i = nb_arg;
  else
    i = 0;
  res = 0;
  while (info.arg_code[i] != -1 && 4 - i > 0)
    {
      if (info.arg_code[i] == 1)
	res += 1;
      else if (info.arg_code[i] == 2)
	res += 2;
      else if (info.arg_code[i] == 3)
	res += 4;
      i++;
    }
  if (l != 1)
    res += (1 + is_coding_byte(info));
  return (res);
}

int	get_arg_rank(char *line, t_info info, int l)
{
  int	i;
  int	nb_arg;

  i = nb_arg = 0;
  while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
    i++;
  while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
    i++;
  while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t')
    i++;
  i++;
  while (line[i] != '\0' && line[i] != LABEL_CHAR)
    {
      if (line[i] == ' ')
	nb_arg++;
      i++;
    }
  if (line[i] == LABEL_CHAR)
    return (getsize(info, nb_arg, l));
  else
    return (2);
}

char	**write_label_call(char **label, char *buf, char *line,
			   t_info info)
{
  int	i;
  int	x;
  int	y;

  i = x = y = 0;
  if ((x = is_label_here(label, &buf[1])) != 0)
    {
      while (label[x][y++] != LABEL_CHAR);
      write_diff((int)my_getnbr(&label[x][y]), info.fd, line, info);
    }
  else
    {
      label = add_line_in_array(label);
      while (label[x][y] != '\0')
	x++;
      while (buf[i + y] != ' ' && buf[i + y] != '\0')
	{
	  while (buf[i + y] != ' ' && buf[i + y] != '\0')
	    label[x] = my_addchar(my_realloc(label[x], 1, 1), buf[i + y++]);
	}
      label[x] = my_addchar(my_realloc(label[x], 1, 1), LABEL_CHAR);
      label[x] = add_size_call(label[x], line, info);
    }
  return (label);
}

int	is_valid_label_char(const char *label)
{
  int	i;
  int	y;
  int	here;

  i = y = here = 0;
  while (label[i] != '\0' && label[i] != LABEL_CHAR)
    {
      while (LABEL_CHARS[y] != '\0')
	{
	  if (LABEL_CHARS[y] == label[i])
	    here = 1;
	  y++;
	}
      if (here != 1)
	return (0);
      here = 0;
      y = 0;
      i++;
    }
  return (1);
}

char	**try_find_label(char *buf, char **label, int fd, t_info info)
{
  int	i;
  int	y;
  int	x;

  i = y = x = 0;
  while (buf[i++ + 1] != '\0' && buf[i] != LABEL_CHAR);
  if (buf[i] == LABEL_CHAR && i > 0 && buf[i - 1] != DIRECT_CHAR)
    {
      label = add_line_in_array(label);
      while (label[x][0] != '\0')
	x++;
      while (buf[i] != ' ' && i > 0)
	i--;
      i = (buf[i] == ' ') ? i + 1 : i;
      while (buf[i + y] != ' ' && buf[i + y] != '\0')
	label[x] = my_addchar(my_realloc(label[x], 1, 1), buf[i + y++]);
      label[x] = add_size_label(label[x]);
      (is_valid_label_char(label[x]) == 0) ? exit(84) : 0;
      label = check_previous_call(label, label[x], fd);
      while (buf[i++ + 1] != LABEL_CHAR && buf[i] != '\0');
    }
  else if (buf[i] == LABEL_CHAR && i > 0 && buf[i - 1] == DIRECT_CHAR)
    label = write_label_call(label, &buf[i], buf, info);
  label = (buf[i] != '\0') ? try_find_label(&buf[i + 1], label, fd, info) : label;
  return (label);
}

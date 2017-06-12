/*
** get_next_line.c for  in /home/hugo.tallineau/CPE_2016_matchstick/src
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Thu Feb 16 17:45:01 2017 Hugo Tallineau
** Last update Mon Apr  3 01:31:34 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "proto.h"
#include "macro.h"

int	check_tamp(char *tamp)
{
  int	i;

  i = 0;
  while (tamp[i] != '\0')
    {
      if (tamp[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

char    *free_tamp(char *tamp, char *s)
{
  if (tamp != NULL)
    free(tamp);
  return (s);
}

char    *free_all(char *tamp, char *s)
{
  if (tamp != NULL)
    free(tamp);
  if (s != NULL)
    free(s);
  return (NULL);
}

char	*get_next_line(int fd)
{
  char	*s;
  char	*tamp;
  int	a;

  a = 0;
  s = my_xmalloc(1);
  tamp = my_xmalloc(2);
  if (s == NULL || tamp == NULL)
    return (NULL);
  s[0] = tamp[0] = '\0';
  while (check_tamp(tamp) != 1)
    {
      if ((a = read(fd, tamp, READ_SIZE)) == 0)
	{
	  if (s[0] == '\0')
	    return (free_all(tamp, s));
	  else
	    return (free_tamp(tamp, s));
	}
      (tamp[0] < '\0') ? exit(84) : 0;
      tamp[a] = '\0';
      (tamp[0] != '\n') ? (s = my_strcat(my_realloc(s, 1, 1), tamp)) : 0;
    }
  free(tamp);
  return (s);
}

char            *get_next_valide_line(const int fd_s)
{
  size_t        i;
  char          *buff;

  if ((buff = get_next_line(fd_s)) == NULL)
    return (NULL);
  i = 0;
  while ((buff[i] == ' ' || buff[i] == '\t') && buff[i] != '\0')
    i++;
  if (buff[i] == '\0')
    {
      free(buff);
      return (get_next_valide_line(fd_s));
    }
  while (buff != NULL && buff[i] == COMMENT_CHAR)
    {
      my_xfree(buff);
      buff = get_next_line(fd_s);
      i = 0;
      while ((buff[i] == ' ' || buff[i] == '\t') && buff[i] != '\0')
	i++;
    }
  return (buff);
}

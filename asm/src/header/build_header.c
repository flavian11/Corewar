/*
** build_header.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Tue Mar 21 12:35:31 2017 Hugo Tallineau
** Last update Mon Apr  3 01:14:40 2017 Hugo Tallineau
*/

#include "op.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "proto.h"

int	try(char *buf, char *key)
{
  int	i;

  i = 0;
  while (buf[i] != '\0')
    {
      if (my_strncmp(key, &buf[i], my_strlen(key)) == 0)
	return (1);
      i++;
    }
  return (0);
}

void	return_i(int *i, char *s)
{
  while (s[*i] != '"' && s[*i] != '\0')
    *i = *i + 1;
}

void	get_name_comment(int fd, header_t *header)
{
  char	*s;
  int	i;
  int	y;

  i = y = 0;
  while ((header->prog_name[0] == '\0' || header->comment[0] == '\0') &&
	 (s = get_next_line(fd)) != NULL)
    {
      if (try(s, NAME_CMD_STRING) == 1 || try(s, COMMENT_CMD_STRING) == 1)
	{
	  return_i(&i, s);
	  (i++ > 0 && s[i - 2] != ' ' && s[i - 2] != '\t') ?
	    compile_error() : 0;
	  while (s[i + y] != '"' && s[i + y] != '\0')
	    {
	      (try(s, NAME_CMD_STRING) == 1) ? (header->prog_name[y] = s[i + y])
		: (header->comment[y] = s[i + y]);
	      y++;
	    }
	  (try(s, NAME_CMD_STRING) == 1) ? (header->prog_name[y] = '\0') :
	    (header->comment[y] = '\0');
	  i = y = 0;
	}
      free(s);
    }
}

header_t	build_header(const int fd, const int fd_cor)
{
  header_t	header;

  my_memset((char*)&header, '\0', sizeof(header));
  get_name_comment(fd, &header);
  if (header.prog_name[0] == '\0' || header.comment[0] == '\0')
    compile_error();
  write_header(fd_cor, header);
  return (header);
}

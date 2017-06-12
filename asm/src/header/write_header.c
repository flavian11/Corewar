/*
** write_header.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/header
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Mon Mar 27 14:21:28 2017 Hugo Tallineau
** Last update Sun Apr  2 17:26:17 2017 Hugo Tallineau
*/

#include <unistd.h>
#include "proto.h"
#include "op.h"
#include <sys/types.h>

long     convert_big_endian_magic_number(long nb)
{
  long   i;

  i = (nb >> 24) | ((nb << 8) & 0x00ff0000) |
    ((nb >> 8) & 0x0000ff00) | (nb << 24);
  return (i);
}

void	write_prog_size(const int fd, header_t header)
{
  lseek(fd, 0, SEEK_SET);
  header.magic = (int)convert_big_endian_magic_number(COREWAR_EXEC_MAGIC);
  header.prog_size = (int)convert_big_endian_magic_number(g_size);
  write(fd, &header, sizeof(header));
}

void	write_header(const int fd, header_t header)
{
  write(fd, &header, sizeof(header));
}

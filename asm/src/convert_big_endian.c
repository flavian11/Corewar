/*
** convert_big_endian.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Mon Mar 27 16:13:19 2017 Hugo Tallineau
** Last update Tue Mar 28 16:23:35 2017 
*/

int	convert_big_endian(int nb)
{
  int   i;
  int	b0;
  int	b1;

  b1 = nb >> 8;
  b0 = nb;
  i = (b0 << 8) + b1;
  return (i);
}

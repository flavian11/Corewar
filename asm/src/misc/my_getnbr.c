/*
** my_getnbr.c for  in /home/hugo.tallineau/CPE_2016_corewar/asm
** 
** Made by Hugo Tallineau
** Login   <hugo.tallineau@epitech.net>
** 
** Started on  Sun Mar 26 20:16:25 2017 Hugo Tallineau
** Last update Sun Apr  2 17:14:32 2017 Hugo Tallineau
*/

long	my_getnbr(const char *str)
{
  int   i;
  int   neg;
  long	res;
  int   bool;

  bool = neg = res = i = 0;
  while (str[i] != '\0' && str[i] != ' ' && str[i] != ':' && bool != 1)
    {
      if (str[i] == '-' && (str[i + 1] < 58 || str[i] > 47))
	neg = 1;
      if (str[i] <= '9' && str[i] >= '0')
	res = res * 10 + (str[i] - 48);
      else if (res != 0)
	bool = 1;
      i++;
    }
  if (neg == 1)
    res = res * (-1);
  return (res);
}

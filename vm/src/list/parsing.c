/*
** parsing.c for  in /home/flavian/epitech/CPE/CPE_2016_corewar/vm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Sun Apr  2 12:50:30 2017 
** Last update Sun Apr  2 17:09:21 2017 Léo COLIN VIMARD
*/

#include "vm.h"

static char	*my_strcat(const char *src, const char *dest)
{
  int	i;
  int	i_res;
  char	*res;

  i = i_res = 0;
  res = malloc(sizeof(char) * (my_strlen(src) + my_strlen(dest) + 2));
  if (res == NULL)
    exit(84);
  while (src[i] != '\0')
    {
      res[i_res] = src[i];
      i++;
      i_res++;
    }
  i = 0;
  res[i_res++] = ' ';
  while (dest[i] != '\0')
    {
      res[i_res] = dest[i];
      i++;
      i_res++;
    }
  res[i_res] = '\0';
  return (res);
}

char	*pars_args(char **av, int *i)
{
  char	*res;
  char	*tmp;

  res = NULL;
  if (my_strcmp(av[(*i)], "-n") == 0)
    {
      res = my_strdup(av[(*i) + 1]);
      (*i) += 2;
    }
  if (my_strcmp(av[(*i)], "-a") == 0)
    {
      tmp = my_strdup(av[*(i) + 1]);
      (*i) += 2;
    }
  res = my_strcat(res, tmp);
  res = my_strcat(res, av[(*i)]);
  free(tmp);
  return (res);
}

char	**get_champ(char **av)
{
  int	i;
  int	i_champ;
  char	**champ_info;

  i = 1;
  i_champ = 0;
  champ_info = malloc(sizeof(char *) * 5);
  if (champ_info == NULL)
    exit(84);
  champ_info[4] = NULL;
  if (my_strcmp(av[i], "-dump") == 0)
    while (i != 3 && av[i] != NULL)
      i++;
  while (av[i] != NULL)
    {
      champ_info[i_champ] = pars_args(av, &i);
      i_champ++;
      i++;
    }
  champ_info[i_champ] = NULL;
  return (champ_info);
}

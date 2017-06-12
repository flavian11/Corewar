/*
** parse_args.c for vm in /home/ZephX/Documents/CPE/corewar/vm_badass/vm
** 
** Made by Marigonez Estéban
** Login   <esteban.marigonez@epitech.eu>
** 
** Started on  Tue Mar 28 19:19:08 2017 Marigonez Estéban
** Last update Sun Apr  2 23:33:15 2017 Léo COLIN VIMARD
*/

#include "vm.h"

char	**build_tab(char **av, int nb_args)
{
  char	**tab;
  int	y;
  int	i;
  int	len;

  (av == NULL) ? exit(84) : 0;
  y = 0;
  i = 1;
  if ((tab = malloc(sizeof(char*) * (nb_args + 1))) == NULL)
    exit(84);
  my_memset(tab, 0, (size_t)nb_args + 1);
  while (i < nb_args)
    {
      len = my_strlen(av[i]);
      if ((tab[y] = malloc(sizeof(char) * len + 1)) == NULL)
	exit(84);
      my_memset(tab[y], 0, (size_t)len + 1);
      tab[y] = my_strcpy(tab[y], av[i]);
      y++;
      i++;
    }
  tab[y] = NULL;
  return (tab);
}

int	catch_nbr(char *str)
{
  int	nbr;

  if ((nbr = my_getnbr(str)) == -666)
    exit(84);
  else
    return (nbr);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    free(tab[i++]);
  free(tab);
}

t_list       *add_node_beg(t_list *e, t_champ champ)
{
  t_list     *list2;

  list2 = malloc(sizeof(*list2));
  if (list2 == NULL)
    exit(84);
  list2->champ = champ;
  list2->next = e;
  return (list2);
}

t_list		*make_list(int ac, char **av)
{
  t_ml		*v;

  if ((v = malloc(sizeof(t_ml))) == NULL)
    exit(84);
  v->len = ac;
  v->y = 0;
  v->tab = build_tab(av, v->len);
  if ((v->list = malloc(sizeof(t_list))) == NULL)
    exit(84);
  my_memset(v->list, 0, sizeof(t_list));
  v->details = my_str_to_wordtab(v->tab[v->y]);
  v->list->champ = add_champ(v->details[2], catch_nbr(v->details[0]),
			  (size_t)catch_nbr(v->details[1]));
  free_tab(v->details);
  v->y++;
  while (v->tab[v->y] != NULL)
    {
      v->details = my_str_to_wordtab(v->tab[v->y]);
      v->chp = add_champ(v->details[2], catch_nbr(v->details[0]),
		      (size_t)catch_nbr(v->details[1]));
      free_tab(v->details);
      v->list = add_node_beg(v->list, v->chp);
      v->y++;
    }
  return (v->list);
}

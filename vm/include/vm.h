/*
** vm.h for emcas in /home/leo.colin-vimard/commence_a_regarde_le_corewar/vm
**
** Made by Léo COLIN VIMARD
** Login   <leo.colin-vimard@epitech.eu>
**
** Started on  Sun Apr  2 03:21:23 2017 Léo COLIN VIMARD
** Last update Sun Apr  2 23:22:55 2017 Léo COLIN VIMARD
*/

#ifndef VM_H_
# define VM_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"

typedef struct		s_data
{
  char			champ_n;
  unsigned char		data;

}			t_data;

typedef struct	s_champ
{
  char		*path;
  char		*name;
  char		*comment;
  size_t	pos;
  int		*regs;
  int		nbr;
  int		wait;
  int		alive;

}		t_champ;

typedef struct  s_list
{
  t_champ       champ;
  struct s_list *next;

}               t_list;

typedef struct s_ml
{
  int           len;
  int           y;
  char          **tab;
  char          **details;
  t_list        *list;
  int           prg_nbr;
  int           add_nbr;
  t_champ       chp;

}t_ml;

typedef struct  s_getnbr
{
  int   i;
  int   nb;
  int   neg;
  int   err;

}t_getnbr;

int		get_value(t_data *, size_t, int *, int);
void		live(t_data *, t_list *, t_list *);
void		st(t_data *, t_list *, t_list *);
void		ld(t_data *, t_list *, t_list *);
void		add(t_data *, t_list *, t_list *);
void		sub(t_data *, t_list *, t_list *);
void		and(t_data *, t_list *, t_list *);
void		or(t_data *, t_list *, t_list *);
void		xor(t_data *, t_list *, t_list *);
void		zjmp(t_data *, t_list *, t_list *);
void		ldi(t_data *, t_list *, t_list *);
void		sti(t_data *, t_list *, t_list *);
void		fork_i(t_data *, t_list *, t_list *);
void		lld(t_data *, t_list *, t_list *);
void		lldi(t_data *, t_list *, t_list *);
void		lfork(t_data *, t_list *, t_list *);
void		aff(t_data *, t_list *, t_list *);
int		my_getnbr(char *);
int		my_strcmp(char *, char *);
char		**my_str_to_wordtab(char *);
void		my_memset(void *, char, size_t);
size_t		my_strlen(const char *);
char		*my_strncpy(char *, char *, size_t);
char		*my_strdup(char *);
char		*my_strcpy(char *, char *);
t_champ		add_champ(char *, int, size_t);
t_champ		fill_n_c(char  *);
header_t	fill_header(char *);
t_list		*make_list(int, char **);
void		clear_battlefield(t_data *, t_list *);
void		if_you_want_peace_prepare_for_war(t_data *, t_list *);
int		*decode_coding_byte(char);
void		print_winner(t_list *);
int		is_it_the_end(t_list *);
int		still_no_winner(t_list *);
int		read_value(t_data *, size_t, int);
int		move_forward(int *, int);
size_t		change_pos(t_data *, size_t, int *);
int		get_ind_value(t_data *, size_t, int);
int		get_value(t_data *, size_t, int *, int);
t_data		*set_arena(t_list *);
void		write_value(t_data *, int, size_t, int);
void		my_putchar(char);
void		my_put_nbr(int);
void		my_putstr(char *);
char		**get_champ(char **);
int		my_det_wordtab_length(char **);
void		my_memset(void *, char, size_t);

#endif

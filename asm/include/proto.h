/*
** proto.h for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
** 
** Made by 
** Login   <flavian.feugueur@epitech.eu>
** 
** Started on  Mon Mar 13 22:42:12 2017 
** Last update Sun Apr  2 17:01:09 2017 Hugo Tallineau
*/

#ifndef COR_PROTO_H
# define COR_PROTO_H

# include <stdlib.h>
# include <sys/types.h>
# include "op.h"
# include "struct.h"

size_t	my_strlen(const char* str);
int	my_strcmp(const char *s, const char *s2);
int	create_file(char *filename);
int	read_file(const char *filename, const int fd_cor);
int	get_command(const char *str);
int	get_params(char *str);
int	my_strncmp(const char *s1, const char *s2, size_t len);
int	get_byte(int params[4]);
int	convert_big_endian(int nb);
int     is_label_here(char **label, char *buf);
int     is_coding_byte(t_info info);
int     getsize(t_info info, int nb_arg, int l);
int     get_arg_rank(char *line, t_info info, int l);
long	convert_big_endian_magic_number(long nb);
long	my_getnbr(const char *str);
void	aff_usage(const char* binary_name);
void	my_putstr(const char *str, int fd);
void	my_xfree(char *str);
void	get_coding_bytes(char *str, t_info *info, int fd_cor);
void	my_write_in_cor(const t_info info, const int fd);
void	write_header(const int fd, header_t header);
void	write_prog_size(const int fd, header_t header);
void	compile_error(void);
void    write_diff(int pos, int fd, char *line, t_info info);
void    jump_and_write(const char *call, const char *label, int fd);
char	*my_addchar(char*, char);
char	*my_revstr(char *str);
char	*my_realloc(char*, int, int);
char	*my_xmalloc(size_t);
char	*my_strcat(char*, char*);
char	*epurestr(char*);
char	*get_next_line(const int fd);
char	*get_next_valide_line(const int fd_s);
char	*my_memset(char *ptr, int c, size_t len);
char	*my_strcpy(char *str);
char	*my_itoa(int nb);
char    *add_size_call(char *label, char *line, t_info info);
char    *add_size_label(char *label);
char    **check_previous_call(char **tab, const char *label, int fd);
char	**try_find_label(char *buf, char **label, int fd, t_info info);
char	**set_label_array(void);
char	**delete_line(char **tab, int x);
char	**add_line_in_array(char **label);
header_t	build_header(const int fd, const int fd_cor);

void	write_live(const t_info info, const int fd);
void	write_ld(const t_info info, const int fd);
void	write_st(const t_info info, const int fd);
void	write_st2(const t_info info, const int a, const int fd, int converted);
void	write_sti2(const t_info info, const int fd);
void	write_add(const t_info info, const int fd);
void	write_sub(const t_info info, const int fd);
void	write_and(const t_info info, const int fd);
void	write_or(const t_info info, const int fd);
void	write_xor(const t_info info, const int fd);
void	write_zjmp(const t_info info, const int fd);
void	write_ldi(const t_info info, const int fd);
void	write_sti(const t_info info, const int fd);
void	write_fork(const t_info info, const int fd);
void	write_aff(const t_info info, const int fd);

void	check_aff(const t_info info);
void	check_bin(const t_info info);
void	check_fork(const t_info info);
void	check_zjump(const t_info info);
void	check_ldi(const t_info info);
void	check_ld(const t_info info);
void	check_live(const t_info info);
void	check_op(const t_info info);
void	check_st(const t_info info);
void	check_sti(const t_info info);

#endif

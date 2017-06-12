##
## Makefile for  in /home/hugo.tallineau/CPE_2016_corewar/asm/src/misc
## 
## Made by Hugo Tallineau
## Login   <hugo.tallineau@epitech.net>
## 
## Started on  Sun Apr  2 18:30:35 2017 Hugo Tallineau
## Last update Sun Apr  2 20:17:36 2017 Hugo Tallineau
##

CC	=	gcc

RM	=	rm -f

SRC	=	add_line_in_array.c \
		my_addchar.c \
		my_realloc.c \
		my_strcpy.c \
		my_xmalloc.c \
		delete_line_in_array.c \
		my_getnbr.c \
		my_revstr.c \
		my_strlen.c \
		epurestr.c \
		my_itoa.c \
		my_strcat.c \
		my_strncmp.c \
		my_putstr.c \
		my_strcmp.c \
		my_xfree.c

OBJ	=	$(SRC:.c=.o)

LIB	=	ar rc

NAME	=	libmy.a

CFLAGS	+=	-I ../../include -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(LIB) $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(SRC:.c=.c~)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

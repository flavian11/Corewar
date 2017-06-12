##
## Makefile for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
## 
## Made by 
## Login   <flavian.feugueur@epitech.eu>
## 
## Started on  Mon Mar 13 21:14:57 2017 
## Last update Sun Apr  2 23:20:47 2017 Léo COLIN VIMARD
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

CC		=	gcc

RM		=	rm -f

SRC		=	./src/

MY		=	$(SRC)my/

LIST		=	$(SRC)list/

INSTRUCTIONS	=	$(SRC)instructions/

COREWAR		=	$(SRC)corewar/

SRCS		=	$(SRC)main.c \
			$(INSTRUCTIONS)instructions.c 	\
                        $(INSTRUCTIONS)instructions2.c 	\
                        $(INSTRUCTIONS)instructions3.c 	\
                        $(INSTRUCTIONS)instructions4.c 	\
			$(MY)tools.c 			\
			$(MY)my_getnbr.c 		\
			$(MY)my_strcmp.c 		\
			$(MY)my_str_to_wordtab.c	 \
			$(MY)my_wordtab_length.c	\
			$(MY)my_putstr.c		\
			$(MY)my_put_nbr.c		\
			$(LIST)add_champ.c 		\
			$(LIST)fill.c 			\
			$(LIST)parse_args.c 		\
			$(LIST)parsing.c		\
			$(COREWAR)clear.c		 \
			$(COREWAR)corewar.c 		\
			$(COREWAR)decode_coding_byte.c 	\
			$(COREWAR)ending_conditions.c 	\
			$(COREWAR)get_value.c 		\
			$(COREWAR)set_arena.c 		\
			$(COREWAR)stock_value.c

OBJ		=	$(SRCS:.c=.o)

NAME		=	corewar

CFLAGS		+=	-I ./include -W -Wextra -Wall -g


all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(SRCS:.c=.c~)
	@$(RM) $(SRCS:.c=.c#)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

flav: re
	@make clean
	@mpg123 ../music/sys-login.mp3 2> /dev/null
	@echo -e "_________                                            \n\_   ___ \  ___________   ______  _  _______ _______ \n/    \  \/ /  _ \_  __ \_/ __ \ \/ \/ /\__  \\_  __ \\n\     \___(  <_> )  | \/\  ___/\     /  / __ \|  | \/\n \______  /\____/|__|    \___  >\/\_/  (____  /__|   \n        \/                   \/         "
.c.o:
		@gcc $(CFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[ OK ]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[ XX ]" $(TEAL) $< $(DEFAULT)

hugo:
	blih -u flavian.feugueur@epitech.eu repository setacl CPE_2016_corewar hugo.tallineau@epitech.eu

##
## Makefile for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
## 
## Made by 
## Login   <flavian.feugueur@epitech.eu>
## 
## Started on  Mon Mar 13 21:14:57 2017 
## Last update Sun Apr  2 18:52:45 2017 Hugo Tallineau
##

ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"

C_LIB	=	make re -C ./src/misc/

LIB	=	-L ./src/misc/ -l my

CC	=	gcc

RM	=	rm -f

SRC	=	./src/

AFF	=	$(SRC)aff/

FUNCT	=	$(WRITE)funct/

READ	=	$(SRC)read/

WRITE	=	$(SRC)write/

ERROR	=	$(SRC)error/

FILE	=	$(SRC)file/

MISC	=	$(SRC)misc/

HEADER	=	$(SRC)header/

CODING_BYTES	=	$(SRC)codding_bytes/

LABEL	=	$(SRC)label/

SRCS	=	$(SRC)main.c \
		$(SRC)op.c \
		$(SRC)convert_big_endian.c \
		$(CODING_BYTES)get_coding_bytes.c \
		$(CODING_BYTES)get_byte.c \
		$(FUNCT)aff.c \
		$(FUNCT)binary_op.c \
		$(FUNCT)binary_xor.c \
		$(FUNCT)fork.c \
		$(FUNCT)jump.c \
		$(FUNCT)ld.c \
		$(FUNCT)live.c \
		$(FUNCT)operator.c \
		$(FUNCT)st.c \
		$(FUNCT)st2.c \
		$(READ)read_file.c \
		$(READ)get_next_line.c \
		$(READ)get_command.c \
		$(WRITE)write_in_cor.c \
		$(ERROR)compile_error.c \
		$(AFF)aff_usage.c \
		$(HEADER)build_header.c \
		$(HEADER)write_header.c \
		$(FILE)creat_file.c \
		$(LABEL)set_label_array.c \
		$(LABEL)try_find_label.c \
		$(LABEL)try_find_label2.c \
		$(LABEL)try_find_label3.c

OBJ	=	$(SRCS:.c=.o)

NAME	=	asm

CFLAGS	+=	-I ./include -W -Wextra -Wall

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(C_LIB) > /dev/null
	@$(CC) $(OBJ) $(LIB) -o $(NAME)

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

##
## Makefile for  in /home/flavian/epitech/CPE/CPE_2016_corewar/asm
## 
## Made by 
## Login   <flavian.feugueur@epitech.eu>
## 
## Started on  Mon Mar 13 21:14:57 2017 
## Last update Wed May  3 10:30:17 2017 flav
##

all:
	make -C ./asm/

clean:
	make clean -C ./asm/ clean

fclean: clean
	make fclean -C ./asm/ fclean

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

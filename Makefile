##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for minishell1
##

CC = gcc

CFLAGS	=	-I./include -W -Wall -Wextra -lcriterion

CFLAGS += -g3

SRC	=	copy_env.c		\
		cd.c		\
		other.c		\
		main.c		\
		exec.c		\
		exit.c		\
		prompt.c		\
		cd_path.c		\
		unsetenv.c		\
		env_other.c		\
		path.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	./mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy -lgnl

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all

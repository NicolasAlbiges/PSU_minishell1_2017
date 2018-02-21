##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## LIB printf 
##

SRC	=	my_putchar.c	\
		my_isneg.c	\
		my_put_nbr.c	\
		my_swap.c	\
		my_putstr.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_revstr.c	\
		my_strcmp.c	\
		my_strcat.c	\
		my_strncat.c	\
		my_printf.c		\
		my_printf_bis.c		\
		my_put_long_long.c	\
		my_long_long_len.c	\
		my_put_unsg_ll.c	\
		base.c		\
		flag_base.c		\
		flag_base_bis.c		\
		flag_disp.c		\
		flag_nbr.c		\
		f_nbr.c		\
		f_nbr_bis.c		\
		flag_h_h.c		\
		flag_long_long.c		\

CC = gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -c $(SRC) -W -Wextra -Wall
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	make clean
	rm -f $(NAME)

re:
	fclean all

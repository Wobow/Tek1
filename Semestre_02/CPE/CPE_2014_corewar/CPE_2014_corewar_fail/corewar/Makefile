##
## Makefile for minishell1 in /home/cesar_a/rendu/PSU_2013_minishell1
## 
## Made by Aymeric CESAR
## Login   <cesar_a@epitech.net>
## 
## Started on  Mon Dec 16 10:44:54 2013 Aymeric CESAR
## Last update Sun Apr 13 14:10:31 2014 Alan BALBO
##

SRC =	checks.c \
	defs.c \
	fct_part1.c \
	fct_part2.c \
	fct_part3.c \
	fct_utilities.c \
	init.c \
	main.c \
	put_params.c \
	utilities.c \
	lib/my_strdup.c \
	lib/my_promptf.c \
	lib/my_printf.c \
	lib/my_put_things.c \
	lib/my_printf_ext.c \
	lib/xfunc.c \
	lib/get_next_line.c \
	lib/my_getnbr.c

OBJ =	$(SRC:.c=.o)

NAME =	corewar

CC =	cc -W -Wall -Werror -Wextra -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

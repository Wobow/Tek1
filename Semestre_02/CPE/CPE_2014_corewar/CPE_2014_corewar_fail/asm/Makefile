##
## Makefile for minishell1 in /home/cesar_a/rendu/PSU_2013_minishell1
## 
## Made by Aymeric CESAR
## Login   <cesar_a@epitech.net>
## 
## Started on  Mon Dec 16 10:44:54 2013 Aymeric CESAR
## Last update Sat Apr 12 16:12:35 2014 Aymeric CESAR
##

SRC =	main.c \
	asm.c \
	init.c \
	wr_in_folder.c \
	op.c \
	my/my_strncmp.c \
	my/my_strcmp.c \
	my/my_printf.c \
	my/my_strlen.c \
	my/my_putstr.c \
	my/get_next_line.c \
	my/my_putchar.c \
	my/my_put_nbr.c \
	my/my_strcocat.c \
	my/my_malloc.c \
	my/my_atoi.c \
	my/my_str_to_wordtab.c \
	my/my_arg_to_wordtab.c \
	my/my_strcpy.c

OBJ =	$(SRC:.c=.o)

NAME =	asm

CC =	cc -W -Wall -Werror -Wextra -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

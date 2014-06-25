##
## Makefile for ex_01 in /home/balbo_a/rendu/Piscine-C-lib/my
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Oct 21 10:11:40 2013 Alan Balbo
## Last update Tue Nov 12 22:07:52 2013 Alan Balbo
##

NAME	= my_mlx_lib.a

SRCS	= shapes.c

OBJS	= $(SRCS:.c=.o)

CP	= cp

all: $(NAME) copylib

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

copylib:
	mv ${NAME} ../

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all

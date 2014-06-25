##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Sun Apr 13 10:34:35 2014 Alan BALBO
##

NAME		= libmy.a

CC		= cc
RM		= rm -rf

SRCDIR		= my_lib_C/
SRC		= $(shell cat $(SRCDIR)list)

OBJDIR		= objs/
OBJ		= $(SRC:.c=.o)

MKDIR		= mkdir
AFF		= aff

CFLAGS		= -W -Wall -Werror -pedantic -ansi
LDFLAGS		= -I ../include/

all:		$(MKDIR) $(NAME)

$(MKDIR):
		$(MKDIR) -p $(OBJDIR)

$(OBJDIR)%.o:
		$(CC) $(CFLAGS) $(LDFLAGS) -c $(subst $(OBJDIR), $(SRCDIR), $(@:.o=.c)) -o $(@)

$(NAME):	$(addprefix $(OBJDIR), $(OBJ))
		ar rc $(NAME) $(addprefix $(OBJDIR), $(OBJ))
		ranlib $(NAME)

clean:
		$(RM) $(OBJDIR)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all


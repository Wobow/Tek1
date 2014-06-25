##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Mon Mar 17 00:55:20 2014 BALBO Alan
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

LDFLAGS		= -I ../include/

all:		$(MKDIR) $(NAME)

$(MKDIR):
		@ $(MKDIR) -p $(OBJDIR)

$(AFF):
		@ echo -en "Compilation of $(NAME) : "

$(OBJDIR)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGS) -c $(subst $(OBJDIR), $(SRCDIR), $(@:.o=.c)) -o $(@)

$(NAME):	$(AFF) $(addprefix $(OBJDIR), $(OBJ))
		@ echo "Done."
		@ ar rc $(NAME) $(addprefix $(OBJDIR), $(OBJ))
		@ ranlib $(NAME)

clean:
		@ $(RM) $(OBJDIR)

fclean:		clean
		@ $(RM) $(NAME)

re:		fclean all


##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Mon Jan 13 18:28:10 2014 BALBO Alan
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
		@ echo -e "Done."
		@ ar rc $(NAME) $(addprefix $(OBJDIR), $(OBJ))
		@ ranlib $(NAME)

clean:
		@ echo ""
		@ echo -en "Removing objs directory of $(NAME) : "
		@ $(RM) $(OBJDIR)
		@ echo -e "Done."

fclean:		clean
		@ echo -en "Removing $(NAME) file : "
		@ $(RM) $(NAME)
		@ echo -e "Done."

re:		fclean all


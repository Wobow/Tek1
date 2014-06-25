##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Mon Mar 17 00:35:40 2014 BALBO Alan
##

NAME		= lol

CC		= cc
RM		= rm -rf
MAKE		= make --no-print-directory -C lib/
MAKERE		= make --no-print-directory fclean -C lib/
MAKEC		= make --no-print-directory clean -C lib/

SRCDIR		= srcs/
SRC		= $(subst $(SRCDIR), , $(shell find $(SRCDIR)))

OBJDIR		= objs/
OBJ		= $(SRC:.c=.o)

MKDIR		= mkdir
AFF		= aff

LIB		= lib/libmy.a
INC		= -Iinclude
LDFLAGS		= -O3

all:		$(MKDIR) $(NAME)

$(MKDIR):
		@ echo ""
		@ $(MAKE)
		@ $(MKDIR) -p $(OBJDIR)

$(AFF):
		@ echo -en "Compilation of" $(NAME) ": "

$(OBJDIR)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGS) -c $(subst $(OBJDIR), $(SRCDIR), $(@:.o=.c)) -o $(@)

$(NAME):	$(AFF) $(addprefix $(OBJDIR), $(OBJ))
		@ echo -e "Done."
		@ $(CC) $(INC) $(addprefix $(OBJDIR), $(OBJ)) $(LIB) -o $(NAME)
		@ echo -en "\nProject "$(NAME) "ready to use ! Have fun \o/\n\n"

run:		re
		@ echo -e "Running "$(NAME)" now : \n"
		@ ./$(NAME)

clean:
		@ echo ""
		@ echo -en "Removing objs directory : "
		@ $(MAKEC)
		@ $(RM) $(OBJDIR)
		@ echo -e "Done."

fclean:		clean
		@ echo -en "Removing "$(NAME) "file : "
		@ $(MAKERE)
		@ $(RM) $(NAME)
		@ echo -e "Done."

relib:
		@ echo ""
		@ echo -en "Removing library : "
		@ $(MAKERE)
		@ echo -en "Done."

re:		relib fclean all


##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Fri Feb 21 09:33:57 2014 BALBO Alan
##

NAME		= 160bombyx

CC		= cc
RM		= rm -rf

SRCDIR		= srcs/
SRC		= $(subst $(SRCDIR), , $(shell find $(SRCDIR)))

OBJDIR		= objs/
OBJ		= $(SRC:.c=.o)

MKDIR		= mkdir
AFF		= aff

LIB		= lib/libmy.a lib/libmlx.a
INC		= -I/usr/X11R6/include -Iinclude
LDFLAGS		= -L/usr/lib64/X11 -lXext -lX11 -lm -O3

all:		$(MKDIR) $(NAME)

$(MKDIR):
		@ echo ""
		@ $(MAKELIB)
		@ $(MKDIR) -p $(OBJDIR)

$(AFF):
		@ echo -en "Compilation of" $(NAME) ": "

$(OBJDIR)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGS) -c $(subst $(OBJDIR), $(SRCDIR), $(@:.o=.c)) -o $(@)

$(NAME):	$(AFF) $(addprefix $(OBJDIR), $(OBJ))
		@ echo -e "Done."
		@ $(CC) $(INC) $(addprefix $(OBJDIR), $(OBJ)) $(LIB) $(LDFLAGS) -o $(NAME)
		@ echo -en "\nProject "$(NAME) "ready to use ! Have fun \o/\n\n"

run:		re
		@ echo -e "Running "$(NAME)" now : \n"
		@ ./$(NAME)

clean:
		@ echo ""
		@ echo -en "Removing objs directory : "
		@ $(RM) $(OBJDIR)
		@ echo -e "Done."

fclean:		clean
		@ echo -en "Removing "$(NAME) "file : "
		@ $(RM) $(NAME)
		@ echo -e "Done."

relib:
		@ echo ""
		@ $(MAKERE)

re:		relib fclean all

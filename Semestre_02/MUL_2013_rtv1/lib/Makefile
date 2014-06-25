##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Sun Mar 16 19:32:39 2014 BALBO Alan
##

NAME		= libs

LIB		= libmy.a

CC		= gcc
RM		= rm -rf

SRCDIR		= my_lib_C/
SRC		= $(shell cat my_lib_C/list)

OBJDIR		= objs/my_lib_C/
OBJ		= $(SRC:.c=.o)

MKDIR		= mkdir
AFF		= aff
LDFLAGS		= -I ../include/

all:		$(MKDIR) $(LIB)

$(MKDIR):
		@ $(MKDIR) -p $(OBJDIR)

$(AFF):
		@ echo -en "Compilation of $(LIB) : "

$(OBJDIR)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGS) -c $(subst $(OBJDIR), $(SRCDIR), $(@:.o=.c)) -o $(@)

$(LIB):		$(AFF) $(addprefix $(OBJDIR), $(OBJ))
		@ echo -e "Done."
		@ ar rc $(LIB) $(addprefix $(OBJDIR), $(OBJ))
		@ ranlib $(LIB)

clean:
		@ echo ""
		@ echo -en "Removing objs directory of libmy : "
		@ $(RM) objs
		@ echo -e "Done."

fclean:		clean
		@ $(RM) $(LIB)

re:		fclean all


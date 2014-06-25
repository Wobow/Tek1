##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Thu Jan  9 16:38:38 2014 BALBO Alan
##

NAME		= libs

LIBA		= libmy.a
LIBB		= libmlx.a

CC		= gcc
RM		= rm -rf

SRCDIRA		= my_lib_C/
SRCA		= $(shell cat my_lib_C/list)

OBJDIRA		= objs/my_lib_C/
OBJA		= $(SRCA:.c=.o)


SRCDIRB		= my_mlx_lib/
SRCB		= $(shell cat my_mlx_lib/list)

OBJDIRB		= objs/my_mlx_lib/
OBJB		= $(SRCB:.c=.o)

MKDIR		= mkdir
AFFA		= affa
AFFB		= affb

LDFLAGSA	= -I ../include/
LDFLAGSB	= -I ../include/  -I/usr/X11R6/include -Wno-deprecated-declarations -O3

all:		$(MKDIR) $(LIBA) $(LIBB)

$(MKDIR):
		@ $(MKDIR) -p $(OBJDIRA) $(OBJDIRB)

$(AFFA):
		@ echo -en "Compilation of $(LIBA) : "
$(AFFB):
		@ echo -en "Compilation of $(LIBB) : "

$(OBJDIRA)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGSA) -c $(subst $(OBJDIRA), $(SRCDIRA), $(@:.o=.c)) -o $(@)

$(OBJDIRB)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGSB) -c $(subst $(OBJDIRB), $(SRCDIRB), $(@:.o=.c)) -o $(@)

$(LIBA):	$(AFFA) $(addprefix $(OBJDIRA), $(OBJA))
		@ echo -e "Done."
		@ ar rc $(LIBA) $(addprefix $(OBJDIRA), $(OBJA))
		@ ranlib $(LIBA)

$(LIBB):	$(AFFB) $(addprefix $(OBJDIRB), $(OBJB))
		@ echo -e "Done."
		@ ar rc $(LIBB) $(addprefix $(OBJDIRB), $(OBJB))
		@ ranlib $(LIBB)

clean:
		@ echo ""
		@ echo -en "Removing objs directory of libs : "
		@ $(RM) objs
		@ echo -e "Done."

fclean:		clean
		@ echo -en "Removing .a files : "
		@ $(RM) $(LIBA) $(LIBB)
		@ echo -e "Done."

re:		fclean all


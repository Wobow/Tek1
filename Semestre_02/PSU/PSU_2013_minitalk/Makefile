##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Fri Mar 21 13:45:51 2014 BALBO Alan
##

NAME		= lol

CLI		= client
SER		= server

CC		= cc
RM		= rm -rf
MAKE		= make --no-print-directory -C lib/
MAKERE		= make --no-print-directory fclean -C lib/
MAKEC		= make --no-print-directory clean -C lib/

SRCDIRC		= srcs_client/
SRCC		= $(subst $(SRCDIRC), , $(shell find $(SRCDIRC)))
SRCDIRS		= srcs_server/
SRCS		= $(subst $(SRCDIRS), , $(shell find $(SRCDIRS)))

OBJDIRC		= objs_client/
OBJC		= $(SRCC:.c=.o)
OBJDIRS		= objs_server/
OBJS		= $(SRCS:.c=.o)

MKDIR		= mkdir
MKDIRC		= mkcli
MKDIRS		= mkser
AFF		= aff

LIB		= lib/libmy.a
INC		= -Iinclude
LDFLAGS		= -O3

all:		$(MKDIR) $(NAME)

$(MKDIR):
		@ $(MAKE)
		@ $(MKDIR) -p bin
		@ $(MKDIR) -p bin/client
		@ $(MKDIR) -p $(OBJDIRC)
		@ $(MKDIR) -p bin/server
		@ $(MKDIR) -p $(OBJDIRS)


$(MKDIRC):
		@ $(MAKE)
		@ $(MKDIR) -p bin
		@ $(MKDIR) -p bin/client
		@ $(MKDIR) -p $(OBJDIRC)

$(MKDIRS):
		@ $(MAKE)
		@ $(MKDIR) -p bin
		@ $(MKDIR) -p bin/server
		@ $(MKDIR) -p $(OBJDIRS)

affcli:
		@ echo -ne "Compilation of client  : "

affser:
		@ echo -ne "Compilation of server  : "

done:
		@ echo "Done."

$(OBJDIRC)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGS) -c $(subst $(OBJDIRC), $(SRCDIRC), $(@:.o=.c)) -o $(@)

$(OBJDIRS)%.o:
		@ echo -ne ".."
		@ $(CC) $(INC) $(LDFLAGS) -c $(subst $(OBJDIRS), $(SRCDIRS), $(@:.o=.c)) -o $(@)

$(NAME):	affcli $(addprefix $(OBJDIRC), $(OBJC)) done affser $(addprefix $(OBJDIRS), $(OBJS))
		@ echo -ne "Done.\n\n\tCreation of client binary : "
		@ $(CC) $(INC) $(addprefix $(OBJDIRC), $(OBJC)) $(LIB) -o bin/client/$(CLI)
		@ echo -ne "OK.\n\tCreation of server binary : "
		@ $(CC) $(INC) $(addprefix $(OBJDIRS), $(OBJS)) $(LIB) -o bin/server/$(SER)
		@ echo -ne "OK.\n"
		@ echo -en "\nProject ready to use ! Have fun \o/\n\n"

$(CLI):		$(MKDIRC) affcli $(addprefix $(OBJDIRC), $(OBJC)) done
		@ echo -ne "\n\tCreation of client binary : "
	        @ $(CC) $(INC) $(addprefix $(OBJDIRC), $(OBJC)) $(LIB) -o bin/client/$(CLI)
		@ echo -ne "OK.\n"

$(SER):		$(MKDIRS) affser $(addprefix $(OBJDIRS), $(OBJS)) done
		@ echo -ne "\n\tCreation of server binary : "
	        @ $(CC) $(INC) $(addprefix $(OBJDIRS), $(OBJS)) $(LIB) -o bin/server/$(SER)
		@ echo -ne "OK.\n"

clean:
		@ echo ""
		@ echo -en "Removing objs directories : "
		@ $(MAKEC)
		@ $(RM) $(OBJDIRC)
		@ $(RM) $(OBJDIRS)
		@ echo -e "Done."

fclean:		clean
		@ echo -en "Removing binary files : "
		@ $(MAKERE)
		@ $(RM) bin
		@ echo -e "Done."

re:		fclean all


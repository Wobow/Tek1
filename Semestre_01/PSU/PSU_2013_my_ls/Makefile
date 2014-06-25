##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Mon Nov 18 13:45:08 2013 Alan Balbo
##

NAME		= NAME

CC		= cc
RM		= rm -f

SRC		= SRCS

OBJ		= $(SRC:.c=.o)

LIB		= Includes/lib/libmy.a
INC		= -I Includes/include
FLAGS		= 

all:		$(NAME)

caca:
		@ echo -e "\n\e[01;32mStart creating objects...\n\e[00m"
.c.o:
		@ echo -en "\e[33m -- |  Creation of" $(<:.c=.o) "...\e[31m"
		@ $(CC) $(INC) -c $< -o $(<:.c=.o)
		@ echo -e " \e[33mSuccess.\e[00m"

$(NAME):	caca $(OBJ)
		@ echo -e "\n\e[01;32mObjects created\e[00m\n"
		@ echo -e "\e[01;35mStart compilation\e[00m\n...\e[31m"
		@ $(CC) $(OBJ) $(LIB) $(FLAGS) -o $(NAME)
		@ echo -e "\e[01;35m\e[01;35mCompilation of" $(NAME) "complete !\e[00m\n"

clean:
		@ echo -en "\n\e[31mRemoving objects ... "
		@ $(RM) $(OBJ)
		@ echo -en "Success.\n\e[00m"

fclean:		clean
		@ echo -en "\n\e[31mRemoving binary file\e[01;31m" $(NAME) "\e[00m\e[31m... "
		@ $(RM) $(NAME)
		@ echo -en "Success.\n\e[00m"

re:		fclean all


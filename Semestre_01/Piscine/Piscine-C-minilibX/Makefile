##
## Makefile for Makefile in /home/balbo_a/rendu/Piscine-C-Jour_13/cat
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Wed Oct 23 09:03:05 2013 Alan Balbo
## Last update Fri Oct 25 09:28:59 2013 Alan Balbo
##

NAME	= p4

SRCS	= main.c \
	  action.c \
	  shapes.c \
	  events.c

OBJS	= ${SRCS:.c=.o}

PATHLIB	= ../Piscine-C-lib/
NAMELIB	= my

CC	= gcc
RM	= rm -f

all:	${NAME} clean

${NAME}:	${OBJS}
	${CC} ${OBJS} -L${PATHLIB} -l${NAMELIB} -L/usr/lib64 -lmlx_${HOSTTYPE} -L/usr/lib64/X11 -lXext -lX11 -lm -o ${NAME}

clean:	
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

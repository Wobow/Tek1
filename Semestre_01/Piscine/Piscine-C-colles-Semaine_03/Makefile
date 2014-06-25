NAME		= colle3

SRC		= colle3.c \
		  aff_soluce.c

OBJ		= $(SRC:.c=.o)

PATHLIB 	= ../Piscine-C-lib/
NAMELIB 	= my

CC		= cc
RM		= rm -f

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -L$(PATHLIB) -l$(NAMELIB) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

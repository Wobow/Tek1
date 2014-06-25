##
## Makefile for Makefile in /home/balbo_a/rendu/Maths/101pong
## 
## Made by Alan Balbo
## Login   <balbo_a@epitech.net>
## 
## Started on  Mon Nov  4 19:59:27 2013 Alan Balbo
## Last update Sun Apr 13 14:27:20 2014 Alan BALBO
##

NAME	= CPE

COREWAR = corewar
ASM	= asm

all:	$(NAME)

$(NAME):
	@echo -ne "\nMake corewar\n"
	@make --no-print-directory -C ./corewar
	@echo -ne "Done.\n\nMake asm\n"
	@make --no-print-directory -C ./asm
	@echo -ne "Done.\n"

$(COREWAR):	part1

part1:
	@echo -ne "Make corewar\n"
	@make --no-print-directory -C ./corewar
	@echo -ne "Done.\n"

$(ASM):	part2

part2:
	@echo -ne "Make asm\n"
	@make --no-print-directory -C ./asm
	@echo -ne "Done.\n"

clean:
	@echo -ne "Cleaning\n\n"
	@make --no-print-directory clean -C ./corewar
	@make --no-print-directory clean -C ./asm
	@echo -ne "Done.\n"

fclean:
	@echo -ne "Full Cleaning\n\n"
	@make --no-print-directory fclean -C ./corewar
	@make --no-print-directory fclean -C ./asm
	@echo -ne "Done.\n"

re:	fclean all



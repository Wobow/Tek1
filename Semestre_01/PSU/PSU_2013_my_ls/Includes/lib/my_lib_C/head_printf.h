/*
** head.h for head in /home/balbo_a/rendu/Piscine-C-eval_expr
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Oct 27 18:01:07 2013 Alan Balbo
** Last update Sat Nov 16 00:11:16 2013 Alan Balbo
*/

#ifndef HEAD_H_
# define HEAD_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

# define NB_FLAGS 13

typedef struct	s_apin
{
  char		*pandore;
  va_list	ap;
  int		i;
  char		*s;
  void		(**f)();
}		t_apin;

void	my_putfloat(float);
void	my_errno(void*);
void	my_put_ptr(int);
void	my_putbin(int);
void	my_putstr_nb(char*);
void	my_putnbr(int);
void	my_putunbr(unsigned int);
void	my_putoctal(int);
void	my_puthexa(int);
void	my_puthexa_up(int);
void	my_putchar(char);
void	my_putstr(char*);

#endif /* HEAD_H_ */

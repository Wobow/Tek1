/*
** my.h for my in /home/balbo_a/rendu/Piscine-C-include
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct 10 11:01:58 2013 Alan Balbo
** Last update Fri Mar 21 14:32:43 2014 BALBO Alan
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

/*
** basic functions
*/

int	my_putchar(char c);
int	my_putnbr(int n);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_getnbr_base(char *str, char *base);
int	my_strcmp(char *s1, char *s2);

#endif /* MY_H_ */

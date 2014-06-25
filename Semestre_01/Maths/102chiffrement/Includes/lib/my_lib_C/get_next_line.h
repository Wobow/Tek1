/*
** get_next_line.h for get_next_line.h in /home/balbo_a/rendu/get_next_line-2018-balbo_a
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Nov 18 13:49:06 2013 Alan Balbo
** Last update Sat Nov 23 19:24:58 2013 Alan Balbo
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#define BUFF_SIZE 42

#include <stdlib.h>

int	my_strlen2(char*);
char	*my_concat(char*, char);
char	*get_next_line(const int);
int	clean_buffer(char *);

#endif /* GET_NEXT_LINE_H_ */

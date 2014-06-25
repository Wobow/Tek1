/*
** head.h for head.h in /home/balbo_a/rendu/102chiffrement-2018-balbo_a
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Nov 18 17:00:00 2013 Alan Balbo
** Last update Fri Nov 29 08:27:52 2013 BALBO Alan
*/

#ifndef HEAD_H_
# define HEAD_H_

#include <my.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

char	**my_str_to_wordtab(char*);
char	**split_expr(char*);
void	my_printf(char*, ...);

typedef struct	s_ruc
{
  float		*matrice;
  char		*base;
  int		*message;
  int		*convert_matrice;
}		t_ruc;

#endif /* HEAD_H_ */

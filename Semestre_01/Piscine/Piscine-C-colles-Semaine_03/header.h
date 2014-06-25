/*
** header.h for header in /home/balbo_a/rendu/Piscine-C-colles-Semaine_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Sun Oct 27 00:58:44 2013 Alan Balbo
** Last update Sun Oct 27 10:18:18 2013 berenger leclere
*/

#ifndef HEADER_H_
# define HEADER_H_

#include <unistd.h>
#include <stdlib.h>
#include "../Piscine-C-include/my.h"

typedef struct  s_infos
{
  int		x;
  int		y;
}               t_infos;

void		clear_buff(char *buff);
void		find_colls(char *str, t_infos *infos, int last_char);
int		what_is_this_glue(char *str);
void		put_in_tab(char *tab, int i);
void		put_in_tab_bis(char *tab, int i);
void		put_result(int i, t_infos *infos);
void		my_print_soluce(t_infos *infos, char *str, char *lcolumn, char *lchar);

#endif /* HEADER_H_ */

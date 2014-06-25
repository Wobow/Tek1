/*
** ia.c for ia in /home/balbo_a/rendu/Allum1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Feb 16 12:13:42 2014 BALBO Alan
** Last update Sun Feb 16 12:24:31 2014 BALBO Alan
*/

#include "head.h"

void	go_ia(t_a *t)
{
  t_l	*cur;
  int	i;
  int	j;

  i = rand() % 100;
  cur = t->head;
  while (i > 0 || !cur->nb_alum)
    {
      cur = cur->next;
      i--;
    }
  j = rand() % cur->nb_alum;
  delete_alum(j, cur, t->nb_col);
  t->turn = -t->turn + 3;
  if (count_alum(t->head) == 0)
    win_game(t);
  display_board(t);
}

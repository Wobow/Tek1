/*
** waiting.c for waiting in /home/balbo_a/rendu/Allum1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Feb 16 18:16:36 2014 BALBO Alan
** Last update Sun Feb 16 18:16:43 2014 BALBO Alan
*/

#include "head.h"

void		change_select(int type, t_l *cur)
{
  if (type)
    cur->next->selected = 1;
  else
    cur->prev->selected = 1;
  cur->selected = 0;
}

void		get_wait(t_a *t)
{
  static int	move = 0;
  char		s[4];
  t_l		*cur;

  cur = t->head;
  read(0, s, 4);
  while (cur->selected != 1)
    cur = cur->next;
  if (s[2] == 'B' && !move)
    change_select(1, cur);
  else if (s[2] == 'A' && !move)
    change_select(0, cur);
  else if (s[0] == ' ')
    {
      move = 1;
      delete_alum(1, cur, t->nb_col);
    }
  else if (move && s[0] == '\n')
    {
      move = 0;
      t->turn = -t->turn + 3;
      if (count_alum(t->head) == 0)
	win_game(t);
    }
  display_board(t);
}

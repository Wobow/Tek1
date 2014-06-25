/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Sun Feb 16 18:19:46 2014 BALBO Alan
*/

#include "head.h"

void		display_board(t_a *t)
{
  t_l		*cur;
  int		i;

  cur = t->head;
  i = 0;
  tgetent(NULL, "xterm");
  tputs(tgetstr("cl", NULL), 1, put_behave);
  my_printf("\n\tJOUE, HUMAIN !\n\n");
  while (cur != t->head || !i)
    {
      i = 1;
      if (cur->selected == 1)
	tputs(tgetstr("mr", NULL), 1, put_behave);
      my_printf("\t%s\n", cur->content);
      if (cur->selected == 1)
	tputs(tgetstr("me", NULL), 1, put_behave);
      cur = cur->next;
    }
  my_putstr("\n\t[FLECHES] Sélectionner ligne  [SPACE] Retirer une");
  my_putstr(" allumette [ENTER] Finir son tour  [ESC] Quitter\n\n");
  if (t->turn == 1)
    get_wait(t);
  else
    go_ia(t);
}

int		check_case(t_a *t, t_l *cur, int i)
{
  int		j;

  j = 0;
  while (j < t->nb_col)
    {
      if (CUR_CASE != ' ' && CUR_CASE != '|')
	return (1);
      if (CUR_CASE == '|')
	cur->nb_alum++;
      cur->content = my_strncat(cur->content, &CUR_CASE, 1);
      cur->selected = 0;
      j++;
    }
  return (0);
}

int		init_board(t_a *t)
{
  int		i;
  t_l		*cur;

  i = 0;
  cur = t->head;
  while (i < t->nb_line)
    {
      cur->content = my_strdup("");
      cur->nb_alum = 0;
      if (check_case(t, cur, i))
	return (1);
      if (i != t->nb_line - 1)
	cur->next = xmalloc(sizeof(*cur->next));
      else
	cur->next = t->head;
      cur->next->prev = cur;
      cur = cur->next;
      i++;
    }
  t->head->selected = 1;
  return (0);
}

int		main(int ac, char **av)
{
  t_a		*t;

  t = xmalloc(sizeof(*t));
  t->nb_line = NB_LINE;
  t->nb_col = NB_COL;
  t->turn = 1;
  t->board = my_strdup("   |     |||   ||||| |||||||");
  t->head = xmalloc(sizeof(*t->head));
  init_tc(t);
  if (init_board(t))
    return (my_putstr(BOR_ERR));
  display_board(t);
  t->term.c_lflag |= ECHO;
  t->term.c_lflag |= ICANON;
  xtcset(t);
  return (0);
}

/*
** game_utilities.c for game in /home/balbo_a/rendu/Allum1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Feb 16 12:13:10 2014 BALBO Alan
** Last update Sun Feb 16 18:31:59 2014 BALBO Alan
*/

#include "head.h"

void	my_exit(t_a *t)
{
  int	i;
  t_l	*cur;

  i = 0;
  cur = t->head;
  reinit_tc(t);
  if (t->board)
    free(t->board);
  if (t->head)
    {
      while (i != t->nb_line - 1)
	{
	  cur = cur->next;
	  free(cur->prev);
	  i++;
	}
      free(t->head);
    }
  if (t)
    free(t);
  exit(0);
}

int	put_behave(int c)
{
  write(0, &c, 1);
}

void	delete_alum(int nb, t_l *cur, int col)
{
  int	i;

  i = 0;
  while (cur->content[i] != '|' && i < col - 1)
    i++;
  cur->content[i] = ' ';
  cur->nb_alum--;
}

void	win_game(t_a *t)
{
  tputs(tgetstr("cl", NULL), 1, put_behave);
  if (t->turn == 1)
    my_printf("Félicitation, humain. Tu as gagné ! :)\n");
  else
    my_printf("Tu es vraiment mauvais... :(\n");
  my_exit(t);
}

int	count_alum(t_l *cur)
{
  int	total;
  t_l	*head;

  head = cur;
  total = 0;
  while (cur->next != head)
    {
      total += cur->nb_alum;
      cur = cur->next;
    }
  total += cur->nb_alum;
  my_putnbr(total);
  return (total);
}

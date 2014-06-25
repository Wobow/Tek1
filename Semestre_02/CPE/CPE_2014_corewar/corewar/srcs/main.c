/*
** main.c for main in /home/gotti_q/My_Work/Tek1/corewar
**
** Made by quentin gotti
** Login   <gotti_q@epitech.net>
**
** Started on  Thu Apr 10 23:39:01 2014 quentin gotti
** Last update Sun Apr 13 11:09:01 2014 Alan BALBO
*/

#include "vm.h"

void		redf(t_prog *cur, t_info *s)
{
  if (cur->np != 0)
    cur->exec = (s->vm + cur->pc)[0];
  if (cur->exec > 0 && cur->exec <= 16 && does_it_look_well(s, cur) == 0
      && s->verif[cur->np - 1] != -1 && cur->np != 0)
    {
      cur->ncycle = look_cycle(cur->exec - 1, s->cycle);
      def_arg(cur, s);
    }
}

void		go_exec(t_info *s, t_prog *lp, int (**tab_fct)())
{
  t_prog	*cur;
  int		temp;

  cur = lp;
  while (cur != NULL)
    {
      if (cur->exec < 1 || cur->exec > 16 || cur->np == 0)
	{
	  cur->pc = (cur->pc + 1) % MEM_SIZE;
	  redf(cur, s);
	}
      else if (cur->ncycle == s->cycle)
	{
	  tab_fct[cur->exec - 1](s, cur);
	  if ((temp = cur->exec) != 9)
	    cur->pc = (cur->pc + cur->lenp) % MEM_SIZE;
	  redf(cur, s);
	}
      cur = cur->next;
    }
}

void		my_fwin(t_prog *lp, int x, int max)
{
  int		i;

  i = 0;
  if (x >= max)
    my_printf("IT'S A DRAW\n");
  else
    {
      while (i < x)
	{
	  lp = lp->next;
	  i = i + 1;
	}
      my_printf("le joueur %d(%s) a gagne\n", lp->np, lp->head.prog_name);
    }
}

int		main(int ac, char **av)
{
  t_prog	*lp;
  t_info	*s;
  int		i;
  int		(**tab_fct)();

  if (ac < 3)
    return (write(1, "Quel combat passionant\n", 23));
  s = def_info(ac);
  i = 0;
  lp = def_prog(ac, av, s);
  def_proglist(ac - 1, s, lp);
  tab_fct = def_tab();
  while (check_verif(s) > 1)
    {
      go_exec(s, lp, tab_fct);
      s->cycle = s->cycle + 1;
    }
  while (s->verif[i] == -1)
    i = i + 1;
  my_fwin(lp, i, ac - 1);
  return (0);
}

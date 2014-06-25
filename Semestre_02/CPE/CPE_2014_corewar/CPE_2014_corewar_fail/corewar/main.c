/*
** main.c for main in /home/gotti_q/My_Work/Tek1/corewar
**
** Made by quentin gotti
** Login   <gotti_q@epitech.net>
**
** Started on  Thu Apr 10 23:39:01 2014 quentin gotti
** Last update Sun Apr 13 19:09:41 2014 Alan BALBO
*/

#include "vm.h"

void		redf(t_prog *cur, t_info *s)
{
  if (cur->np != 0)
    {
      cur->exec = (s->vm + cur->pc)[0];
    }
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
      else if (s->cycle >= cur->ncycle)
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

int		get_nbj(int ac, char **av)
{
  int		i;
  int		out;

  i = 1;
  out = 0;
  while (i < ac)
    {
      if (av[i][0] != '-')
	out++;
      else
	i++;
      i++;
    }
  if (out < 2)
    exit(my_printf("Not enough players\n"));
  else if (out > 4)
    exit(my_printf("Too many players\n"));
  return (out + 1);
}

t_pars		*new_prog()
{
  t_pars	*cur;

  cur = xmalloc(sizeof(*cur));
  cur->nbj = 0;
  cur->name = NULL;
  cur->pos = -1;
  cur->next = NULL;
  return (cur);
}


t_pars		*init_prog(char *name, t_pars *cur, t_pars *head)
{
  t_pars	*l;

  cur->name = name;
  l = head;
  if (cur->nbj == 0)
    {
      cur->nbj = 1;
      while (l != NULL)
	{
	  if (cur->nbj == l->nbj && l != cur)
	    {
	      cur->nbj++;
	      l = head;
	    }
	  else
	    l = l->next;
	}
    }
  cur->next = new_prog();
  return (cur->next);
}

void		check_prog_list(t_pars *head, int nbj)
{
  t_pars	*cur;
  int		j[4];
  int		i;

  j[0] = 0;
  j[1] = 0;
  j[2] = 0;
  j[3] = 0;
  cur = head;
  while (cur != NULL)
    {
      if (cur->nbj >= 10)
	{
	  if (j[cur->nbj / 10 - 1] == 0)
	    j[cur->nbj / 10 - 1] = 1;
	  else
	    exit(my_printf("Player number %d picked twice.\n", cur->nbj / 10));
	  cur->nbj = cur->nbj / 10;
	}
      cur = cur->next;
    }
  i = -1;
  cur = head;
  while (++i && j[i]);
  while (cur != NULL && i < nbj)
    {
      my_printf("[%d] - [%d, %d, %d, %d]\n", i, j[0], j[1], j[2], j[3]);
      if (cur->nbj == i + 1)
	{
	  j[i] = 1;
	  while (++i && j[i]);
	  cur = head;
	}
      else
	cur = cur->next;
    }
  i = 0;
  while (i < nbj - 1)
    {
      if (j[i] == 0)
	{
	  cur = head;
	  while (cur != NULL && j[i] == 0)
	    {
	      if (cur->nbj == -1)
		{
		  j[i] = 1;
		  cur->nbj = i + 1;
		}
	      cur = cur->next;
	    }
	  if (cur == NULL)
	    my_printf("Player %d not set\n", i + 1);
	}
      i++;
    }
}

t_pars		*check_line(int ac, char **av)
{
  int		i;
  t_pars	*cur;
  t_pars	*head;

  cur = new_prog();
  head = cur;
  i = 1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  if (my_strlen(av[i]) == 2 && (my_strcmp(av[i], "-a") & my_strcmp(av[i], "-n")) == 0)
	    {
	      if (av[i][1] == 'a' && av[i + 1])
		cur->pos = my_getnbr(av[i + 1]) % MEM_SIZE;
	      else if (av[i][1] == 'n' && av[i + 1])
		cur->nbj = my_getnbr(av[i + 1]) * 10;
	      else
		exit(my_printf("Syntax error\n"));
	    }
	  else
	    exit(my_printf("unknown option %s\n", av[i] + 1));
	  i++;
	}
      else
	cur = init_prog(av[i], cur, head);
      i++;
    }
  cur->nbj = -1;
  cur = head;
  while (cur->next->nbj != -1)
    cur = cur->next;
  free(cur->next);
  cur->next = NULL;
  check_prog_list(head, get_nbj(ac, av));
  return (head);
}

int		main(int ac, char **av)
{
  t_prog	*lp;
  t_info	*s;
  int		i;
  int		(**tab_fct)();

  if (ac < 3)
    return (write(1, "Quel combat passionant\n", 23));
  s = def_info(get_nbj(ac, av));
  i = 0;
  lp = def_prog(check_line(ac, av), s);
  def_proglist(get_nbj(ac, av), s, lp);
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

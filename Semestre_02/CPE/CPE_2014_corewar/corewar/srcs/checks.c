/*
** checks.c for checks in /home/balbo_a/rendu/CPE_2014_corewar/corewar/srcs
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Apr 13 11:01:56 2014 Alan BALBO
** Last update Sun Apr 13 11:12:50 2014 Alan BALBO
*/

#include "vm.h"

int		look_cycle(int exec, int cycle)
{
  int		tab[16];

  tab[0] = 10;
  tab[1] = 5;
  tab[2] = 5;
  tab[3] = 10;
  tab[4] = 10;
  tab[5] = 6;
  tab[6] = 6;
  tab[7] = 6;
  tab[8] = 20;
  tab[9] = 25;
  tab[10] = 25;
  tab[11] = 25;
  tab[12] = 800;
  tab[13] = 50;
  tab[14] = 1000;
  tab[15] = 2;
  return (tab[exec] + cycle);
}

int		check_verif(t_info *s)
{
  int		i;
  int		t;

  i = 0;
  t = 0;
  if (s->cycle >= s->nice)
    {
      while (i < s->nbj)
	{
	  if (s->verif[i] > 0)
	    t = t + 1;
	  s->verif[i] = s->verif[i] - 1;
	  i = i + 1;
	}
      s->nice = s->nice + CYCLE_TO_DIE - s->delta;
      return (t);
    }
  else
    return (2);
}

int		return_dilw(t_info *s, t_prog *lp, int i, int t)
{
  if (s->vm[(lp->pc + 1 + i + t) % MEM_SIZE] < 1
      || s->vm[(lp->pc + 1 + i + t) % MEM_SIZE] > 16)
    return (1);
  return (0);
}

int		does_it_look_well(t_info *s, t_prog *lp)
{
  int		x;
  int		temp;
  int		t;
  int		i;

  t = 0;
  x = 64;
  temp = s->vm[(lp->pc + 1) % MEM_SIZE];
  if ((i = my_exept(lp)) == 1)
    temp = s->vm[lp->pc + 1];
  else
    temp = lp->mem;
  if (s->vm[(lp->pc + 1) % MEM_SIZE] < 0)
    temp = temp + 256;
  while (x >= 1)
    {
      if (temp / x % 4 == 3)
	t = t + IND_SIZE;
      else if (temp / x % 4 == 2)
	t = t + DIR_SIZE;
      else if (temp / x % 4 == 1)
	t = t + 1;
      x = x / 4;
    }
  return (return_dilw(s, lp, i, t));
}

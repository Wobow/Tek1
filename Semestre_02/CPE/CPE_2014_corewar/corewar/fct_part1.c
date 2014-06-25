/*
** fct_part1.c for fct_part1.c in /home/balbo_a/rendu/corewar
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sat Apr 12 12:57:14 2014 Alan BALBO
** Last update Sat Apr 12 13:29:36 2014 Alan BALBO
*/

#include "my.h"

int		my_live(t_info *t, t_prog *p)
{
  t->nb_live++;
  if (p->param[0] && p->param[0] < 4)
    {
      my_printf("le joueur %d(%s) est en vie\n", p->param[0],
		t->prog_list[p->param[0]]);
      t->verif[p->param[0]] = 1;
    }
  if (t->nb_live % NBR_LIVE == 0)
    t->delta += CYCLE_DELTA;
  return (0);
}

int		my_ld(t_info *t, t_prog *p)
{
  int		pos;
  int		i;

  if (p->param[0] && p->param[1] && p->param[2] < REG_NUMBER)
    {
      if (TYPE_PARAM1 == P_DIR)
	PC = p->param[0];
      else
	PC = get_index(PC, p->param[0], IDX_MOD);
      i = 0;
      while (i < REG_SIZE)
	{
	  p->reg[p->param[1] * REG_SIZE + i] = t->vm[PC + i];
	  i++;
	}
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int		my_st(t_info *t, t_prog *p)
{
  int		i;

  if (p->param[0] && p->param[0] < REG_NUMBER && p->param[1])
    {
      if (TYPE_PARAM2 == P_IND)
	while (i < REG_SIZE)
	  {
	    t->vm[get_index(PC, p->param[1] + i,
			    IDX_MOD)] = p->reg[p->param[0] * REG_SIZE + i];
	    i++;
	  }
      else if (p->param[1] < REG_NUMBER)
	while (i < REG_SIZE)
	  {
	    p->reg[p->param[1] * REG_SIZE + i] = p->reg[p->param[0] + i];
	    i++;
	  }
      return (0);
    }
  return (1);
}

int		my_add(t_info *t, t_prog *p)
{
  if (p->param[0] && p->param[1] && p->param[2] &&
      p->param[0] > 0 && p->param[1] > 0 && p->param[2] > 0 &&
      p->param[0] <= REG_NUMBER && p->param[1] <= REG_NUMBER &&
      p->param[2] <= REG_NUMBER)
    {
      p->reg[p->param[2] * REG_SIZE] = p->reg[p->param[0] * REG_SIZE];
      p->reg[p->param[2] * REG_SIZE] += p->reg[p->param[1] * REG_SIZE];
    }
  else
    return (1);
  return (0);
}

int		my_sub(t_info *t, t_prog *p)
{
  if (p->param[0] && p->param[1] && p->param[2] &&
      p->param[0] > 0 && p->param[1] > 0 && p->param[2] > 0 &&
      p->param[0] <= REG_NUMBER && p->param[1] <= REG_NUMBER &&
      p->param[2] <= REG_NUMBER)
    {
      p->reg[p->param[2] * REG_SIZE] = p->reg[p->param[0] * REG_SIZE];
      p->reg[p->param[2] * REG_SIZE] -= p->reg[p->param[1] * REG_SIZE];
    }
  else
    return (1);
  return (0);
}

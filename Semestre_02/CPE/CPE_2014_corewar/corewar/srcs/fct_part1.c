/*
** fct_part1.c for fct_part1.c in /home/balbo_a/rendu/corewar
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sat Apr 12 12:57:14 2014 Alan BALBO
** Last update Sun Apr 13 09:53:24 2014 Alan BALBO
*/

#include "vm.h"

int		my_live(t_info *t, t_prog *p)
{
  int		i;
  int		jo;

  t->nb_live++;
  jo = 0;
  i = 0;
  while (i < 4)
    {
      jo += p->param[i] * my_power_rec(2, (3 - i) * 8);
      i++;
    }
  if (jo > 0 && jo <= 4)
    {
      my_printf("le joueur %d(%s) est en vie\n", jo,
  		t->prog_list[jo - 1]);
      t->verif[jo - 1] = 1;
    }
  if (t->nb_live % NBR_LIVE == 0)
    t->delta += CYCLE_DELTA;
  return (0);
}

int		my_ld(t_info *t, t_prog *p)
{
  int		i;

  if (TYPE_PARAM1 == P_DIR)
    PC = PARAM1;
  else
    PC = get_index(PC, PARAM1, IDX_MOD);
  i = 0;
  while (i < REG_SIZE)
    {
      p->reg[PARAM2 * REG_SIZE + i] = t->vm[PC + i];
      i++;
    }
  t->carry = 0 - t->carry + 1;
  return (0);
}

int		my_st(t_info *t, t_prog *p)
{
  int		i;

  if (PARAM1 && PARAM1 < REG_NUMBER && PARAM2)
    {
      if (TYPE_PARAM2 == P_IND)
	while (i < REG_SIZE)
	  {
	    t->vm[get_index(PC, PARAM2 + i,
			    IDX_MOD)] = p->reg[PARAM1 * REG_SIZE + i];
	    i++;
	  }
      else if (PARAM2 < REG_NUMBER)
	while (i < REG_SIZE)
	  {
	    p->reg[PARAM2 * REG_SIZE + i] = p->reg[PARAM1 + i];
	    i++;
	  }
      return (0);
    }
  return (1);
}

int		my_add(t_info *t, t_prog *p)
{
  if (t != NULL && PARAM1 && PARAM2 && PARAM3 &&
      PARAM1 > 0 && PARAM2 > 0 && PARAM3 > 0 &&
      PARAM1 <= REG_NUMBER && PARAM2 <= REG_NUMBER &&
      PARAM3 <= REG_NUMBER)
    {
      p->reg[PARAM3 * REG_SIZE] = p->reg[PARAM1 * REG_SIZE];
      p->reg[PARAM3 * REG_SIZE] += p->reg[PARAM2 * REG_SIZE];
    }
  else
    return (1);
  return (0);
}

int		my_sub(t_info *t, t_prog *p)
{
  if (t != NULL && PARAM1 && PARAM2 && PARAM3 &&
      PARAM1 > 0 && PARAM2 > 0 && PARAM3 > 0 &&
      PARAM1 <= REG_NUMBER && PARAM2 <= REG_NUMBER &&
      PARAM3 <= REG_NUMBER)
    {
      p->reg[PARAM3 * REG_SIZE] = p->reg[PARAM1 * REG_SIZE];
      p->reg[PARAM3 * REG_SIZE] -= p->reg[PARAM2 * REG_SIZE];
    }
  else
    return (1);
  return (0);
}

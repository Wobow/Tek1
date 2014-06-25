/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Sun Apr 13 09:56:25 2014 Alan BALBO
*/

#include "vm.h"

int		my_sti(t_info *t, t_prog *p)
{
  int		i;
  int		s;

  if (PARAM1 && PARAM2 && PARAM3 && PARAM1 < REG_NUMBER)
    {
      s = 0;
      if (TYPE_PARAM2 == P_DIR)
	s += PARAM2;
      else if (TYPE_PARAM2 == P_IND)
	s += get_ind_value(t, p, 1, IDX_MOD);
      else
	s += get_reg_value(p, 1);
      if (TYPE_PARAM3 == P_DIR)
	s += PARAM3;
      else
	s += get_reg_value(p, 2);
      i = -1;
      PC = get_index(PC, s, IDX_MOD);
      while (++i && i < REG_SIZE)
	t->vm[PC + i] = p->reg[PARAM1 * REG_SIZE + i];
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int		my_lld(t_info *t, t_prog *p)
{
  int		i;

  if (PARAM1 && PARAM2 && PARAM3 < REG_NUMBER)
    {
      if (TYPE_PARAM1 == P_DIR)
	PC = PARAM1;
      else
	PC = get_index(PC, PARAM1, 1);
      i = 0;
      while (i < REG_SIZE)
	{
	  p->reg[PARAM2 * REG_SIZE + i] = t->vm[PC + i];
	  i++;
	}
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int		my_lldi(t_info *t, t_prog *p)
{
  int		i;
  int		s;

  if (PARAM1 && PARAM2 && PARAM3 && PARAM3 < REG_NUMBER)
    {
      s = 0;
      if (TYPE_PARAM1 == P_DIR)
	s += PARAM1;
      else if (TYPE_PARAM1 == P_IND)
	s += get_ind_value(t, p, 0, 1);
      else
	s += get_reg_value(p, 0);
      if (TYPE_PARAM2 == P_DIR)
	s += PARAM2;
      else
	s += get_reg_value(p, 1);
      i = -1;
      PC = get_index(PC, s, IDX_MOD);
      while (++i && i < REG_SIZE)
	p->reg[PARAM3 * REG_SIZE + i] = t->vm[PC + i];
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int		my_fork(t_info *t, t_prog *p)
{
  t_prog	*cur;
  int		i;

  i = -1;
  cur = p;
  while (t != NULL && cur->next != NULL)
    cur = cur->next;
  cur->next = xmalloc(sizeof(*cur));
  cur = cur->next;
  cur->next = NULL;
  while (++i && i < REG_SIZE * REG_NUMBER)
    cur->reg[i] = 0;
  cur->exec = 0;
  cur->ncycle = 0;
  cur->pc = get_index(PC, p->param[0], IDX_MOD);
  cur->np = p->np;
  cur->mem = 0;
  cur->lenp = 0;
  i = -1;
  while (++i && i <= MAX_ARGS_NUMBER * 4)
    cur->param[i] = 0;
  return (0);
}

int		my_lfork(t_info *t, t_prog *p)
{
  t_prog	*cur;
  int		i;

  i = -1;
  cur = p;
  while (t != NULL && cur->next != NULL)
    cur = cur->next;
  cur->next = xmalloc(sizeof(*cur));
  cur = cur->next;
  cur->next = NULL;
  while (++i && i < REG_SIZE * REG_NUMBER)
    cur->reg[i] = 0;
  cur->exec = 0;
  cur->ncycle = 0;
  cur->pc = get_index(PC, p->param[0], 1);
  cur->np = p->np;
  cur->mem = 0;
  cur->lenp = 0;
  i = -1;
  while (++i && i <= MAX_ARGS_NUMBER * 4)
    cur->param[i] = 0;
  return (0);
}

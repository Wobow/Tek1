/*
** fct_part2.c for fct_part2 in /home/balbo_a/rendu/corewar
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sat Apr 12 12:57:48 2014 Alan BALBO
** Last update Sun Apr 13 15:04:09 2014 Alan BALBO
*/

#include "vm.h"

int		my_and(t_info *t, t_prog *p)
{
  int		i;
  int		part[2];

  i = -1;
  while (++i && p->param[i] && i < 3);
  if (i != 3)
    return (1);
  if (TYPE_PARAM1 == T_REG)
    part[0] = p->reg[PARAM1 * REG_SIZE];
  else if (TYPE_PARAM1 == T_IND)
    part[0] = t->vm[get_index(PC, PARAM1, 1)];
  else
    part[0] = PARAM1;
  if (TYPE_PARAM2 == T_REG)
    part[1] = p->reg[PARAM2 * REG_SIZE];
  else if (TYPE_PARAM2 == T_IND)
    part[1] = t->vm[get_index(PC, PARAM2, 1)];
  else
    part[1] = PARAM2;
  p->reg[PARAM3 * REG_SIZE] = part[0] & part[1];
  t->carry = -t->carry + 1;
  return (0);
}

int		my_or(t_info *t, t_prog *p)
{
  int		i;
  int		part[2];

  i = -1;
  while (++i && p->param[i] && i < 3);
  if (i != 3)
    return (1);
  if (TYPE_PARAM1 == T_REG)
    part[0] = p->reg[PARAM1 * REG_SIZE];
  else if (TYPE_PARAM1 == T_IND)
    part[0] = t->vm[get_index(PC, PARAM1, 1)];
  else
    part[0] = PARAM1;
  if (TYPE_PARAM2 == T_REG)
    part[1] = p->reg[PARAM2 * REG_SIZE];
  else if (TYPE_PARAM2 == T_IND)
    part[1] = t->vm[get_index(PC, PARAM2, 1)];
  else
    part[1] = PARAM2;
  p->reg[PARAM3 * REG_SIZE] = part[0] | part[1];
  t->carry = -t->carry + 1;
  return (0);
}

int		my_xor(t_info *t, t_prog *p)
{
  int		i;
  int		part[2];

  i = -1;
  while (++i && p->param[i] && i < 3);
  if (i != 3)
    return (1);
  if (TYPE_PARAM1 == T_REG)
    part[0] = p->reg[PARAM1 * REG_SIZE];
  else if (TYPE_PARAM1 == T_IND)
    part[0] = t->vm[get_index(PC, PARAM1, 1)];
  else
    part[0] = PARAM1;
  if (TYPE_PARAM2 == T_REG)
    part[1] = p->reg[PARAM2 * REG_SIZE];
  else if (TYPE_PARAM2 == T_IND)
    part[1] = t->vm[get_index(PC, PARAM2, 1)];
  else
    part[1] = PARAM2;
  p->reg[PARAM3 * REG_SIZE] = part[0] ^ part[1];
  t->carry = -t->carry + 1;
  return (0);
}

int		my_zjmp(t_info *t, t_prog *p)
{
  int		i;

  if (p->param[0])
    {
      if (t->carry == 1)
	{
	  i = p->param[0];
	  while (i != 0)
	    {
	      if (PC % MEM_SIZE >= 1)
		PC = 0;
	      else
		PC++;
	      i--;
	    }
	}
      return (0);
    }
  return (1);
}

int		my_ldi(t_info *t, t_prog *p)
{
  int		i;
  int		s;

  if (PARAM1 && PARAM2 && PARAM3 && PARAM3 < REG_NUMBER)
    {
      s = 0;
      if (TYPE_PARAM1 == P_DIR)
	s += PARAM1;
      else if (TYPE_PARAM1 == P_IND)
	s += get_ind_value(t, p, 0, IDX_MOD);
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

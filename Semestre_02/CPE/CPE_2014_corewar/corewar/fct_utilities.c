/*
** fct_utilities.c for fct_utilities in /home/balbo_a/rendu/corewar
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sat Apr 12 12:56:31 2014 Alan BALBO
** Last update Sat Apr 12 12:58:25 2014 Alan BALBO
*/

#include "my.h"

int		get_index(int pc, int ind, int mod)
{
  if (mod != 0)
    ind = ind % mod;
  while (ind != 0)
    {
      if (pc == MEM_SIZE)
	pc = 0;
      else
	pc++;
      ind--;
    }
  return (pc);
}

int		get_ind_value(t_info *t, t_prog *p, int param, int mod)
{
  int		i;
  int		p;
  int		out;

  i = 0;
  out = 0;
  pos = get_index(PC, p->param[param], mod);
  while (i < IND_SIZE)
    {
      out += t->vm[pos + i] * my_power_rec(2, (IND_SIZE - i) * 8);
      i++;
    }
  return (out);
}

int		get_reg_value(t_info *t, t_prog *p, int param)
{
  int		i;
  int		p;
  int		out;
  int		t;

  i = 0;
  out = 0;
  while (i < REG_SIZE)
    {
      t = p->reg[p->param[param] * REG_SIZE + i];
      s += t * my_power_rec(2, (REG_SIZE - i) * 8);
      i++;
    }
  return (out);
}

int		my_aff(t_info *t, t_prog *p)
{
  int		s;
  int		i;

  s = 0;
  if (p->param[0] < REG_SIZE)
    {
      my_putchar(get_reg_value(t, p, 0) % 256);
      return (0);
    }
  return (1);
}

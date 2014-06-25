/*
** fct_utilities.c for fct_utilities in /home/balbo_a/rendu/corewar
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sat Apr 12 12:56:31 2014 Alan BALBO
** Last update Sun Apr 13 09:51:45 2014 Alan BALBO
*/

#include "vm.h"

int		get_param(t_prog *p, int n)
{
  int		out;
  int		i;
  int		sizes[3];
  int		pos;
  int		par[3];

  par[0] = TYPE_PARAM1;
  par[1] = TYPE_PARAM2;
  par[2] = TYPE_PARAM3;
  sizes[P_DIR] = DIR_SIZE;
  sizes[P_REG] = REG_SIZE;
  sizes[P_IND] = IND_SIZE;
  pos = 0;
  out = 0;
  i = -1;
  while (++i && i < n)
    pos += sizes[par[i]];
  i = -1;
  while (++i && i < sizes[par[n]])
    out += p->param[pos + i] * my_power_rec(2, (sizes[par[n]] - i) * 8);
  my_printf("-- %d --\n", out);
  return (out);
}

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
  int		pos;
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

int		get_reg_value(t_prog *p, int param)
{
  int		i;
  int		out;
  int		tmp;

  i = 0;
  out = 0;
  while (i < REG_SIZE)
    {
      tmp = p->reg[p->param[param] * REG_SIZE + i];
      out += tmp * my_power_rec(2, (REG_SIZE - i) * 8);
      i++;
    }
  return (out);
}

int		my_aff(t_info *t, t_prog *p)
{
  if (t != NULL && p->param[0] < REG_SIZE)
    {
      my_putchar(get_reg_value(p, 0) % 256);
      return (0);
    }
  return (1);
}

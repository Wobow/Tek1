/*
** utilities.c for utilities in /home/balbo_a/rendu/CPE_2014_corewar/corewar/srcs
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Apr 13 11:00:07 2014 Alan BALBO
** Last update Sun Apr 13 11:09:05 2014 Alan BALBO
*/

#include "vm.h"

int		b_to_l(int nb)
{
  int		result;

  result = ((nb & 0x000000FF) << 24) + ((nb & 0xFF000000) >> 24);
  result += ((nb & 0x0000FF00) << 8) + ((nb & 0x00FF0000) >> 8);
  return (result);
}

void		clear_arg(t_prog *lp)
{
  int		i;

  i = 0;
  while (i < MAX_ARGS_NUMBER * 4)
    {
      lp->param[i] = 0;
      i = i + 1;
    }
}

int		my_exept(t_prog *lp)
{
  if (lp->exec == 1)
    lp->mem = 128;
  else if (lp->exec == 9 || lp->exec == 12 || lp->exec == 15)
    lp->mem = 192;
  else
    return (1);
  return (0);
}

void		my_affect(t_prog *lp, int temp, int t)
{
  lp->mem = temp;
  lp->lenp = t;
}

/*
** put_params.c for put_params in /home/balbo_a/rendu/CPE_2014_corewar/corewar/srcs
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Apr 13 11:01:20 2014 Alan BALBO
** Last update Sun Apr 13 11:07:43 2014 Alan BALBO
*/

#include "vm.h"

int		put_ind(t_info *s, t_prog *lp, int t, int x)
{
  int		i;

  i = 0;
  while (i < IND_SIZE)
    {
      lp->param[t + i] = s->vm[lp->pc + 1 + x + (i) + t];
      i = i + 1;
    }
  return (i);
}

int		put_dir(t_info *s, t_prog *lp, int t, int x)
{
  int		i;

  i = 0;
  while (i < DIR_SIZE)
    {
      lp->param[t + i] = s->vm[lp->pc + 1 + x + (i) + t];
      i = i + 1;
    }
  return (i);
}

int		put_reg(t_info *s, t_prog *lp, int t, int x)
{
    int		i;

  i = 0;
  lp->param[t + i] = s->vm[lp->pc + 1 + x + t];
  i = i + 1;
  return (i);
}

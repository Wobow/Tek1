/*
** calc.c for calc in /home/balbo_a/rendu/MUL_2013_rtv1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Mar 16 19:37:14 2014 BALBO Alan
** Last update Sun Mar 16 23:05:41 2014 BALBO Alan
*/

#include "head.h"

int		spot_light(int (*inter[4])(), int i, int j, t_o *cur)
{
  t_v		*vect;
  int		out;

  vect = xmalloc(sizeof(*vect));
  vect->vx = (100) - SPOTX;
  vect->vy = (i - H / 2) - SPOTY;
  vect->vz = (j - W / 2) - SPOTZ;
  out = inter[cur->shape](vect, cur);
  if (out == -1)
    return (cur->color);
  return (cur->color - (out / 1000));
}

t_v		*get_vecteur(int i, int j)
{
  t_v		*vect;

  vect = xmalloc(sizeof(*vect));
  vect->vx = (100) - XO;
  vect->vy = (i - H / 2) - YO;
  vect->vz = (j - W / 2) - ZO;
  return (vect);
}

t_o		*calc_part(int (*inter[4])(), int min, t_o *cur, t_v *vect)
{
  t_o		*tmp;
  int		out;

  out = 0;
  tmp = cur;
  while (cur != NULL)
    {
      if ((out = inter[cur->shape](vect, cur)) != -1)
	if (out < min || min == -1)
	  {
	    tmp = cur;
	    min = out;
	  }
      cur = cur->next;
    }
  if (min == -1)
    return (NULL);
  return (tmp);
}

int		calc(t_t *t, int i, int j)
{
  t_v		*vect;
  t_o		*cur;
  int	        (*inter[4])();
  t_o		*tmp;
  int		min;

  vect = get_vecteur(i, j);
  cur = t->head;
  min = -1;
  inter[0] = intersect_sphere;
  inter[1] = intersect_plan;
  inter[2] = intersect_cone;
  inter[3] = intersect_cylindre;
  if ((tmp = calc_part(inter, min, cur, vect)) == NULL)
    return (0);
  else
    return (spot_light(inter, i, j, tmp));
}

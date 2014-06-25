/*
** intersect.c for intersect in /home/balbo_a/rendu/MUL_2013_rtv1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Mar 16 19:35:57 2014 BALBO Alan
** Last update Sun Mar 16 21:07:39 2014 BALBO Alan
*/

#include "head.h"

int		get_dist(double a, double b, double c)
{
  double	k1;
  double	k2;
  double	delta;

  delta = b * b - 4.0 * a * c;
  if (delta < 0)
    return (-1);
  k1 = (-b - sqrt(delta)) / (2 * a) * 1000;
  k2 = (-b + sqrt(delta)) / (2 * a) * 1000;
  if (k1 < k2)
    return (k1 * 1000);
  return (k2 * 1000);
}

int		intersect_cylindre(t_v *vect, t_o *cur)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = vect->vx * vect->vx + vect->vy * vect->vy;
  b = 2 * (XO * vect->vx + YO * vect->vy);
  c = XO * XO + YO * YO - cur->l * cur->l;
  return (get_dist(a, b, c));
}

int		intersect_cone(t_v *vect, t_o *cur)
{
  double	a;
  double	b;
  double	c;
  double	delta;

  a = vect->vx * vect->vx + vect->vy * vect->vy - vect->vz * vect->vz;
  b = (XO - cur->posx) * vect->vx + (YO - cur->posy) * vect->vy;
  b = (b - (ZO - cur->posz) * vect->vz) * 2;
  c = pow(XO - cur->posx, 2) + pow(YO - cur->posy, 2) - pow(YO - cur->posz, 2);
  return (get_dist(a, b, c));
}

int		intersect_plan(t_v *vect, t_o *cur)
{
  double	k;

  if (ZO > 0 && vect->vz < 0 || ZO < 0 && vect->vz > 0)
    return ((int)((float)(- (float)ZO / vect->vz) * 100000));
  if (ZO == 0 && vect->vz == 0)
    return (0);
  return (-1);
}

int		intersect_sphere(t_v *vect, t_o *cur)
{
  double	delta;
  double	a;
  double	b;
  double	c;

  a = vect->vx * vect->vx + vect->vy * vect->vy + vect->vz * vect->vz;
  b = vect->vx * (XO - cur->posx) + vect->vy * (YO - cur->posy);
  b = (b + vect->vz * (ZO - cur->posz)) * 2;
  c = pow(XO - cur->posx, 2) + pow(YO - cur->posy, 2);
  c = c + pow(ZO - cur->posz, 2) - pow(cur->l, 2);
  return (get_dist(a, b, c));
}

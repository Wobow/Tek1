/*
** events.c for events in /home/balbo_a/rendu/MUL_2013_rtv1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Feb 27 13:40:50 2014 BALBO Alan
** Last update Thu Feb 27 13:41:12 2014 BALBO Alan
*/

#include "head.h"

int    init_mlx(t_t *t)
{
  if ((t->mlx = mlx_init()) == NULL)
    return (1);
  if ((t->win = mlx_new_window(t->mlx, W, H, "RTV1")) == NULL)
    return (1);
  if ((t->img = mlx_new_image(t->mlx, W, H)) == NULL)
    return (1);
  return (0);
}

int	gere_key(int k, t_t *t)
{
  if (k == ESC_KEY)
    exit(0);
}

int	expose(t_t *t)
{
  mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}

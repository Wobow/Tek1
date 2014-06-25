/*
** misc.c for misc in /home/balbo_a/rendu/106bombyx/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Feb 21 14:20:12 2014 BALBO Alan
** Last update Fri Feb 21 14:20:27 2014 BALBO Alan
*/

#include "head.h"

int	expose(t_t *t)
{
  mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}

void	init_graph(t_t *t)
{
  int	x;
  int	y;

  x = 50;
  y = 50;
  while (y <= H - 50)
    {
      my_pixel_put_image(t->img, x, y, 0x00FFFFFF);
      y++;
    }
  while (x <= W - 50)
    {
      my_pixel_put_image(t->img, x, y, 0x00FFFFFF);
      x++;
    }
}

int	gere_key(int k, t_t *t)
{
  if (k == 65307)
    exit(1);
}

/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Sun Mar 16 19:54:56 2014 BALBO Alan
*/

#include "head.h"

int	my_exit(t_t *t)
{
  exit(0);
}

void	my_rt(t_t *t)
{
  int	i;

  while (i <= W * H)
    {
      my_pixel_put_image(t->img, i / W, i % W, calc(t, i / W, i % W));
      i++;
    }
  expose(t);
  my_putchar('\n');
}

int	main(int ac, char **av)
{
  t_t	*t;

  if (ac != 2)
    return (ARG_ERR);
  t = xmalloc(sizeof(*t));
  if (init_mlx(t))
    return (MLX_ERR);
  get_objs(t, av[1]);
  my_rt(t);
  mlx_expose_hook(t->win, expose, t);
  my_key_hook(t->win, gere_key, t);
  mlx_loop(t->mlx);
  return (0);
}

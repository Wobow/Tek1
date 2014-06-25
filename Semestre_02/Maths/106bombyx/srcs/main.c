/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Fri Feb 21 14:22:08 2014 BALBO Alan
*/

#include "head.h"

void	first_case(t_t *t, int k)
{
  int	i;
  int	x;
  int	x0;

  init_graph(t);
  if (k < 0)
    t->k = 0;
  else if (k > 400)
    t->k = 400;
  else
    t->k = k;
  i = 0;
  x0 = 0;
  x = 10;
  while (i <= 100)
    {
      draw_line(t->img, ((W - 100) / 100) * (i - 1) + 50, H - x0 - 50,
		((W - 100) / 100) * i + 50, H - x - 50, COLOR1);
      x0 = x;
      x = (float)K * (float)x * ((1000.0 - (float)x) / 1000.0);
      i++;
    }
}

int	second_case(t_t *t, int start, int stop)
{
  int	i;
  int	x;

  t->k = 100;
  init_graph(t);
  if (start > stop)
    return (1);
  while (t->k <= 400)
    {
      i = 0;
      x = 10;
      while (i <= stop)
      	{
      	  if (i >= start)
	    my_pixel_put_image(t->img, ((W - 100) / 300) * (t->k - 100) + 50,
			       H - (int)x - 50, COLOR2);
      	  x = (float)K * (float)x * ((1000.0 - (float)x) / 1000.0);
      	  i++;
      	}
      t->k++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_t	*t;

  t = xmalloc(sizeof(*t));
  if ((t->mlx = mlx_init()) == NULL)
    return (MLX_ERR);
  t->win = mlx_new_window(t->mlx, W, H, "Bombyyyyyyyx");
  if ((t->img = mlx_new_image(t->mlx, W, H)) == NULL)
    return (MLX_ERR);
  if (ac == 2)
    first_case(t, atof(av[1]) * 100);
  else if (ac == 3)
    {
      if (second_case(t, atoi(av[1]), atoi(av[2])) == 1)
	return (SEC_ERR);
    }
  else
    return (ARG_ERR);
  mlx_key_hook(t->win, gere_key, t);
  mlx_expose_hook(t->win, expose, t);
  mlx_loop(t->mlx);
}

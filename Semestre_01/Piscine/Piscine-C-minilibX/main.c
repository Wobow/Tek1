/*
** test.c for test in /home/balbo_a/rendu/Piscine-C-minilibX
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct 24 09:14:44 2013 Alan Balbo
** Last update Thu Nov 21 13:08:44 2013 Alan Balbo
*/

#include "head.h"

int		p4_init(int nbr, t_info *infos)
{
  if (!(infos->mlx_ptr = mlx_init()))
    return (1);
  infos->height = nbr * 100;
  infos->width = nbr * 100;
  my_putchar(10);
  if (!(infos->win_ptr = mlx_new_window(infos->mlx_ptr, infos->width, infos->height, "Puissance 4")))
    return (1);
  if (!(infos->img = mlx_new_image(infos->mlx_ptr, infos->width, infos->height)))
    return (1);
  if (!(infos->data = malloc(infos->width * infos->height * 32)))
    return (1);
  infos->data = (int*)mlx_get_data_addr(infos->img, &infos->bpp, &infos->sizeline, &infos->endian);
  infos->joueur = 1;
  if (!(infos->cols = malloc(nbr)))
    return (1);
  return (0);
}

int		main(int argc, char **argv)
{
  t_info	*infos;
  int		nbr;

  if (argc == 2)
    {
      if (my_getnbr(argv[1]) > 1 && my_getnbr(argv[1]) <= 11)
	{
	  nbr = my_getnbr(argv[1]);
	  if (!(infos = malloc(sizeof(*infos))))
	    return (1);
	  p4_init(nbr, infos);
	  start_game(infos);
	  mlx_mouse_hook(infos->win_ptr, get_mouse, infos);
	  mlx_key_hook(infos->win_ptr, get_key, infos);
	  mlx_expose_hook(infos->win_ptr, expose, infos);
	  mlx_loop(infos->mlx_ptr);
	  return (0);
	}
    }
  my_putstr("Usage : ./test [nb_colums]\n/!\\ nb_colums : must be >1 and <12.\n");
  return (1);
}

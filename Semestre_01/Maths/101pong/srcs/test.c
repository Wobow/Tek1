/*
** test.c for test in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Nov 17 19:14:05 2013 Alan Balbo
** Last update Sun Nov 17 19:31:38 2013 Alan Balbo
*/

#include <stdlib.h>
#include <mlx_int.h>
#include <mlx.h>

int	main()
{
  int	fd;
  void	*img;
  void	*mlx;
  void	*win;
  int	c;
  int	v;

  c = 900;
  v = 800;
  mlx = mlx_init();
  win = mlx_new_window(mlx, 900, 800, "cacac");
  img = mlx_xpm_file_to_image(mlx, "lol.xpm", &c, &v);
  mlx_put_image_to_window(mlx, win, img, 0, 0);
  mlx_loop(mlx);
}

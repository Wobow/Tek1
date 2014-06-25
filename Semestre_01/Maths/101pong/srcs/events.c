/*
** events.c for events  in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov 13 23:53:58 2013 Alan Balbo
** Last update Sun Nov 17 14:10:24 2013 Alan Balbo
*/

#include "head.h"

int	my_key_hook(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[KeyPress].hook = funct;
  win->hooks[KeyPress].param = param;
  win->hooks[KeyPress].mask = KeyPressMask;
}

int	my_pointer_hook(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[MotionNotify].hook = funct;
  win->hooks[MotionNotify].param = param;
  win->hooks[MotionNotify].mask = PointerMotionMask;
}

int	get_pointer(int x, int y, t_ole *t)
{
  float	nx;
  float	ny;
  float	Nv;
  float	Nn;
  float	cos;
  float	sca;
  float	angle;

  if (t->state)
    {
      nx = (float)x - (float)t->pos_xpit;
      ny = (float)y - (float)t->pos_xpit;
      Nv = -1.0;
      Nn = sqrt(nx*nx + ny*ny);
      sca = nx * -1.0;
      cos = sca/(Nv*Nn);
      angle = (float)acos(cos);
      if (y <= t->pos_ypit)
	angle = -angle;
      angle = angle * (180 / 3.1416);
      t->pit = (int)angle;
    }
}

int	expose(t_ole *t)
{
  mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
}


int	get_key(int keycode, t_ole *t)
{
  if (keycode == 65307)
    {
      if (t->colors)
	free(t->colors);
      if (t->hitbox)
	free(t->hitbox);
      if (t)
	free(t);
      exit(1);
    }
  if (t->state == 1 && keycode == 'r')
    {
      init_game(t);
    }
  if (t->state == 0 && keycode)
    {
      init_game(t);
    }
  if (keycode == 65451)
    {
      if (t->color_picked == 9)
	t->color_picked = 0;
      else
	t->color_picked = t->color_picked + 1;
    }
  if (keycode == 65453)
    {
      if (t->color_picked == 0)
	t->color_picked = 9;
      else
	t->color_picked = t->color_picked - 1;
    }
}

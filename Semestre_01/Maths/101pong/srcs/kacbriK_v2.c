/*
** kacbriK.c for kasbrIk in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov 13 17:16:38 2013 Alan Balbo
** Last update Sat Nov 16 14:13:56 2013 Alan Balbo
*/

#include "head_v3.h"

void		you_lose(t_ole *t)
{
  t->state = 1;
  my_fill_area(t->img, 0, 0, W, H, 0);
  expose(t);
}

void            my_draw_arc(void *img_ptr, int rayon, int color, t_ole *t)
{
  float         angle;
  int           j;
  int           i;
  float		pos;

  pos = t->pit * (3.14 / 180);
  angle = -(3.14 / 6);
  while (angle <= 3.14 / 6)
    {
      i = W / 2 + (rayon * cos(pos - angle));
      j = H / 2 + (rayon * sin(pos - angle));
      my_pixel_put_image(img_ptr, i, j, color);
      angle = angle + (float)1 / (float)rayon;
    }
}

void		my_get_hitbox(void *img, t_ole *t)
{
  float         angle;
  int           j;
  int           i;
  int		u;
  float		pos;
  float		caca;

  pos = t->pit * (3.14 / 180);
  angle = -(3.14 / 6);
  caca = angle;
  u = 0;
  while (caca <= 3.14 / 6)
    {
      u = u + 1;
      caca = caca + (float)1 / (float)(W / 10 + 2);
    }
  t->hitbox = xmalloc(sizeof(int) * (1 + u));
  t->hitbox[u] = 2;
  u = 0;
  while (angle <= 3.14 / 6)
    {
      i = W / 2 + ((W / 10 + 2) * cos(pos - angle));
      j = H / 2 + ((W / 10 + 2) * sin(pos - angle));
      t->hitbox[u] = i + j * W;
      u = u + 1;
      angle = angle + (float)1 / (float)(W / 10 + 2);
    }
}

void	draw_the_pit(t_ole *t)
{
  int	i;

  i = 0;
  my_draw_arc(t->img, W / 10 - 2, COLOR_PIT, t);
  my_draw_arc(t->img, W / 10 - 1, COLOR_PIT, t);
  my_draw_arc(t->img, W / 10 - 0, COLOR_PIT, t);
  my_draw_arc(t->img, W / 10 + 1, COLOR_PIT, t);
  my_draw_arc(t->img, W / 10 + 2, COLOR_PIT, t);
  my_get_hitbox(t->img, t);
  expose(t);
}

void	erase_ball(t_ole *t, int ball)
{
  int	i;
  int	j;

  i = 0;
  while (i < S_BALL)
    {
      j = 0;
      while (j < S_BALL)
	{
	  my_pixel_put_image(t->img, t->oball[ball] % W + i, t->oball[ball] / W + j, COLOR_BG);
	  j = j + 1;
	}
      i = i + 1;
    }
  expose(t);
}

void	put_ball(t_ole *t, int ball)
{
  int	i;
  int	j;

  erase_ball(t, ball);
  i = 0;
  while (i < S_BALL)
    {
      j = 0;
      while (j < S_BALL)
	{
	  if (i == 0 || i == S_BALL - 1 || j == 0 || j == S_BALL - 1)
	    my_pixel_put_image(t->img, t->ball[ball] % W + i, t->ball[ball] / W + j, COLOR_BD_BALL);
	  else
	    my_pixel_put_image(t->img, t->ball[ball] % W + i, t->ball[ball] / W + j, COLOR_BALL);
	  j = j + 1;
	}
      i = i + 1;
    }
  expose(t);
}

int	is_hit(t_ole *t, int ball)
{
  int	i;
  int	j;
  int	*data;
  int	sizeline;
  int	bpp;
  int	endian;
  int	n;

  n = SPEED_BALL;
  i = 0;
  j = 0;
  data = (int*)mlx_get_data_addr(t->img, &bpp, &sizeline, &endian);
  while (i <= S_BALL)
    {
      j = 0;
      while (j <= S_BALL)
	{
	  if ((t->ball[ball] + i + j * W)  % W + n * t->vx[ball] > W || (t->ball[ball] + i + j * W) % W + n * t->vx[ball] < 0)
	    return (1);
	  if ((t->ball[ball] + i + j * W) / W + n * t->vy[ball] > H || (t->ball[ball] + i + j * W) / W + n * t->vy[ball] < 0)
	    return (2);
	  if (data[t->ball[ball] + i + j * W] == COLOR_PIT)
	    return (t->ball[ball] + i + j * W + 3);
	  if (data[t->ball[ball] + i + j * W] == COLOR_CORE)
	    you_lose(t);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

void	draw_init(t_ole *t)
{
  my_draw_disc(t->img, W / 2, H / 2, W / 10 + SPEED_BALL, COLOR_BG, H, W);
  my_draw_circle(t->img, W / 2, H / 2, W / 10, COLOR_LINE);
  my_draw_disc(t->img, W / 2, H / 2, W / 12, COLOR_CORE, H, W);
  draw_the_pit(t);
}

void	get_vect(t_ole *t, int i, int u, int ball)
{
  int	nx;
  int	ny;
  int	ox;
  int	oy;
  int	c;

  my_putnbr(i);
  nx = t->hitbox[i] % W - W / 2;
  ny = t->hitbox[i] / W - H / 2;
  if (abs(nx) <= abs(ny) && nx)
    {
      ny = ny / abs(nx);
      nx = nx / abs(nx);
    }
  else if (ny)
    {
      nx = nx / abs(ny);
      ny = ny / abs(ny);
    }
  nx = nx + t->vx[ball];
  ny = ny + t->vy[ball];
  if (abs(nx) <= abs(ny) && nx)
    {
      ny = ny / abs(nx);
      nx = nx / abs(nx);
    }
  else if (ny)
    {
      nx = nx / abs(ny);
      ny = ny / abs(ny);
    }
  t->vx[ball] = nx;
  t->vy[ball] = ny;
}

int	move_ball(t_ole *t, int ball)
{
  int	x;
  int	y;
  int	n;
  int	i;
  int	u;

  n = SPEED_BALL;
  t->oball[ball] = t->ball[ball];
  if (is_hit(t, ball) == 1)
    t->vx[ball] = - t->vx[ball];
  else if (is_hit(t, ball) == 2)
    t->vy[ball] = - t->vy[ball];
  else if (is_hit(t, ball) >= 3)
    {
      u = 0;
      i = 0;
      while (t->hitbox[u] != 2)
	u = u + 1;
      while (i < u && t->hitbox[i] != is_hit(t, ball) - 3)
	i = i + 1;
      get_vect(t, i, u, ball);
    }
  if (t->state == 0)
    {
      x = t->ball[ball] % W + n * t->vx[ball];
      y = t->ball[ball] / W + n * t->vy[ball];
      t->ball[ball] = x + y * W;
      put_ball(t, ball);
    }
}

int	do_ball(t_ole *t)
{
  int	i;

  if (t->state == 0)
    {
      i = 0;
      usleep(NB_BALL * 4000 + 20000);
      draw_init(t);
      while (i < NB_BALL)
	{
	  move_ball(t, i);
	  i = i + 1;
	}
      expose(t);
    }
  else if (t->state == 1)
    {
      t->state = 2;
      usleep(1000000);
    }
}

void	init_balls(t_ole *t)
{
  int	i;
  int	r;
  int	*caca;

  r = 0;
  i = 0;
  caca = xmalloc(sizeof(int) * NB_BALL);
  caca[1] = W / 4;
  caca[2] = 2*W / 4;
  caca[3] = 3*W / 4;
  caca[4] = 4*W / 4;
  caca[5] = W / 4 + (H / 2) * W;
  caca[6] = 4*W / 4 + (H / 2) * W;
  caca[8] = W / 4 + (H - S_BALL) * W;
  caca[9] = 2*W / 4 + (H - S_BALL) * W;
  caca[0] = 3*W / 4 + (H - S_BALL) * W;
  caca[7] = 4*W / 4 + (H - S_BALL) * W;
  while (i < NB_BALL)
    {
      t->oball[i] = 0;
      t->ball[i] = caca[i];
      t->vx[i] = 1;
      t->vy[i] = 1;
      i = i + 1;
    }
}

void	init_game(t_ole *t)
{
  int	i;

  t->pit = -90;
  t->vx = xmalloc(sizeof(float) * (NB_BALL));
  t->vy = xmalloc(sizeof(float) * (NB_BALL));
  t->oball = xmalloc(sizeof(int) * (NB_BALL));
  t->ball = xmalloc(sizeof(int) * (NB_BALL));
  mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
  i = 0;
  t->state = 0;
  my_draw_disc(t->img, W / 2, H / 2, W / 10 + SPEED_BALL, COLOR_BG, H, W);
  my_draw_circle(t->img, W / 2, H / 2, W / 10, COLOR_LINE);
  my_draw_disc(t->img, W / 2, H / 2, W / 12, COLOR_CORE, H, W);
  draw_the_pit(t);
  init_balls(t);
  while (i < NB_BALL)
    {
      put_ball(t, i);
      i = i + 1;
    }
  expose(t);
}

int	main(int argc, char **argv)
{
  t_ole	*t;

  t = xmalloc(sizeof(*t));
  if (!(t->mlx = mlx_init()))
    {
      my_putstr("J'ai pas env -i :)\n");
      exit(0);
    }
  if(!(t->win = mlx_new_window(t->mlx, W, H, "Caca")))
    exit(0);
  if (!(t->img = mlx_new_image(t->mlx, W, H)))
    exit(0);
  init_game(t);
  mlx_expose_hook(t->win, expose, t);
  my_key_hook(t->win, get_key, t);
  mlx_loop_hook(t->mlx, do_ball, t);
  mlx_loop(t->mlx);
}

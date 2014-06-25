/*
** kacbriK.c for kasbrIk in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov 13 17:16:38 2013 Alan Balbo
** Last update Sun Nov 17 19:43:46 2013 Alan Balbo
*/

#include <stdlib.h>
#include <stdio.h>
#include "head.h"

void		you_lose(t_ole *t)
{
  my_fill_area(t->img, 0, 0, W, H, 0);
  t->state = 0;
  my_putstr("Score final : ");
  my_putnbr(t->score);
  my_putstr("\n");
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
      i = t->pos_xpit + (rayon * cos(pos - angle));
      j = t->pos_ypit + (rayon * sin(pos - angle));
      my_pixel_put_image(img_ptr, i, j, color);
      angle = angle + (float)1 / (float)rayon;
    }
}

void		get_hitbox(t_ole *t)
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
  my_draw_circle(t->img, abs(t->pit) + W / 30, abs(t->pit) + W / 30, W / 30, t->colors[t->color_picked]);
  my_draw_circle(t->img, W - abs(t->pit) - W / 30, H - abs(t->pit) - W / 30, W / 30, t->colors[t->color_picked]);
  my_draw_circle(t->img, W - abs(t->pit) - W / 30, abs(t->pit) + W / 30, W / 30, t->colors[t->color_picked]);
  my_draw_circle(t->img, abs(t->pit) + W / 30, H - abs(t->pit) - W / 30, W / 30, t->colors[t->color_picked]);
  my_draw_arc(t->img, W / 10 - 2, t->colors[t->color_picked], t);
  my_draw_arc(t->img, W / 10 - 1, t->colors[t->color_picked], t);
  my_draw_arc(t->img, W / 10 - 0, t->colors[t->color_picked], t);
  my_draw_arc(t->img, W / 10 + 1, t->colors[t->color_picked], t);
  my_draw_arc(t->img, W / 10 + 2, t->colors[t->color_picked], t);
  get_hitbox(t);
  expose(t);
}

void	erase_ball(t_ole *t)
{
  int	i;
  int	j;

  i = 0;
  while (i < S_BALL)
    {
      j = 0;
      while (j < S_BALL)
	{
	  my_pixel_put_image(t->img, t->oball % W + i, t->oball / W + j, COLOR_BG);
	  j = j + 1;
	}
      i = i + 1;
    }
  expose(t);
}

void	draw_init(t_ole *t)
{
  int	i;

  i = 0;
  my_fill_area(t->img, 0, 0, W, H, COLOR_BG);
  my_draw_circle(t->img, t->pos_xpit, t->pos_ypit, SIZE_SHIP, COLOR_LINE);
  my_draw_disc(t->img, t->pos_xpit, t->pos_ypit, SIZE_CORE, COLOR_CORE, H, W);
  draw_the_pit(t);
}

void	put_ball(t_ole *t)
{
  int	i;
  int	j;

  erase_ball(t);
  draw_init(t);
  i = 0;
  while (i < S_BALL)
    {
      j = 0;
      while (j < S_BALL)
	{
	  if (i == 0 || i == S_BALL - 1 || j == 0 || j == S_BALL - 1)
	    my_pixel_put_image(t->img, t->ball % W + i, t->ball / W + j, COLOR_BD_BALL);
	  else
	    my_pixel_put_image(t->img, t->ball % W + i, t->ball / W + j, COLOR_BALL);
	  j = j + 1;
	}
      i = i + 1;
    }
  expose(t);
}

int	is_hit(t_ole *t)
{
  int	i;
  int	j;
  int	*data;
  int	sizeline;
  int	bpp;
  int	endian;
  int	n;
  int	pos;

  n = SPEED_BALL;
  i = 0;
  j = 0;
  data = (int*)mlx_get_data_addr(t->img, &bpp, &sizeline, &endian);
  while (i <= S_BALL + 1)
    {
      j = 0;
      while (j <= S_BALL + 1)
	{
	  if ((t->ball + i + j * W)  % W + n * t->vx > W || (t->ball + i + j * W) % W + n * t->vx < 0)
	    return (1);
	  if ((t->ball + i + j * W) / W + n * t->vy > H || (t->ball + i + j * W) / W + n * t->vy < 0)
	    return (2);
	  if (data[t->ball + i + j * W] == t->colors[t->color_picked])
	    return (t->ball + i + j * W + 3);
	  if (data[t->ball + i + j * W] == COLOR_CORE)
	    you_lose(t);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

void	get_vect(t_ole *t, int i, int u)
{
  int	nx;
  int	ny;
  int	ox;
  int	oy;
  int	c;

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
  nx = nx + t->vx;
  ny = ny + t->vy;
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
  t->vx = nx;
  t->vy = ny;
}

int	move_ball(t_ole *t)
{
  int	x;
  int	y;
  int	n;
  int	i;
  int	u;

  usleep(5000);
  n = SPEED_BALL;
  t->oball = t->ball;
  if (is_hit(t) == 1)
    t->vx = - t->vx;
  else if (is_hit(t) == 2)
    t->vy = - t->vy;
  else if (is_hit(t) >= 3)
    {
      u = 0;
      i = 0;
      while (t->hitbox[u] != 2)
	u = u + 1;
      while (i < u && t->hitbox[i] != is_hit(t) - 3)
	i = i + 1;
      get_vect(t, i, u);
    }
  if (t->state == 1)
    {
      x = t->ball % W + n * t->vx;
      y = t->ball / W + n * t->vy;
      t->ball = x + y * W;
      put_ball(t);
    }
  expose(t);
}

void	init_colors(t_ole *t)
{
  t->colors[0] = 0x00D8005F;
  t->colors[1] = 0x00336698;
  t->colors[2] = 0x00FF0011;
  t->colors[3] = 0x00DDDDDD;
  t->colors[4] = 0x00CCFF00;
  t->colors[5] = 0x0000CC5F;
  t->colors[6] = 0x00F0F0F0;
  t->colors[7] = 0x00A62F00;
  t->colors[8] = 0x00009999;
  t->colors[9] = 1;
}

void	init_game(t_ole *t)
{
  t->pit = -90;
  t->vx = 0;
  t->vy = 2;
  t->state = 1;
  t->oball = 0;
  t->ball = t->pos_xpit + (H / 5) * W + 20;
  t->score = 0;
  mlx_put_image_to_window(t->mlx, t->win, t->img, 0, 0);
  my_draw_disc(t->img, t->pos_xpit, t->pos_ypit, SIZE_SHIP + SPEED_BALL, COLOR_BG, H, W);
  my_draw_circle(t->img, t->pos_xpit, t->pos_ypit, SIZE_SHIP, COLOR_LINE);
  my_draw_disc(t->img, t->pos_xpit, t->pos_ypit, SIZE_CORE, COLOR_CORE, H, W);
  draw_the_pit(t);
  put_ball(t);
  expose(t);
}

int	main(int argc, char **argv)
{
  t_ole	*t;

  t = xmalloc(sizeof(*t));
  if (!(t->mlx = mlx_init()))
    exit(0);
  if(!(t->win = mlx_new_window(t->mlx, W, H, "Caca")))
    exit(0);
  if (!(t->img = mlx_new_image(t->mlx, W, H)))
    exit(0);
  t->colors = xmalloc(sizeof(int) * (NB_COLORS + 1));
  init_colors(t);
  t->color_picked = 0;
  t->pos_xpit = W / 2;
  t->pos_ypit = H / 2;
  my_pointer_hook(t->win, get_pointer, t);
  init_game(t);
  mlx_expose_hook(t->win, expose, t);
  my_key_hook(t->win, get_key, t);
  mlx_loop_hook(t->mlx, move_ball, t);
  mlx_loop(t->mlx);
}

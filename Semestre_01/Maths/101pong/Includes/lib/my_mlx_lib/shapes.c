/*
** shapes.c for shapes in /home/balbo_a/rendu/Piscine-C-minilibX
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Oct 25 08:45:59 2013 Alan Balbo
** Last update Sun Nov 17 16:20:40 2013 Alan Balbo
*/

#include <mlx_int.h>
#include <mlx.h>
#include <math.h>

int     my_power_rec(int nb, int p)
{
   if (p > 1)
     nb = nb * my_power_rec(nb, p - 1);
   else nb = 1;
}

int     my_pixel_put_image(void *img_ptr, int x, int y, int color)
{
  int   i;
  int	bpp;
  int	sizeline;
  int	endian;
  int	*data;

  data = (int*)mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);
  i = y * (sizeline / 4) + x;
  data[i] = color;
  return (0);
}


void    my_fill_area(void *img_ptr,
		     int x_start, int y_start, int x_stop, int y_stop, int color)
{
  int   x;
  int   y;

  x = x_start;
  y = y_start;
  while (y <= y_stop)
    {
      x = x_start;
      while (x <= x_stop)
        {
          my_pixel_put_image(img_ptr, x, y, color);
          x = x + 1;
        }
      y = y + 1;
    }
}

void            my_draw_circle(void *img_ptr, int x, int y, int rayon, int color)
{
  float         angle;
  int           j;
  int           i;

  angle = 0.0;
  while (angle < 7)
    {
      i = x + (rayon * cos(angle));
      j = y + (rayon * sin(angle));
      my_pixel_put_image(img_ptr, i, j, color);
      angle = angle + (float)1 / (float)rayon;
    }
}

void		my_draw_disc(void *img_ptr, int x_center, int y_center, int rayon, int color, int height, int width)
{
  int   x;
  int   y;
  int   x2;
  int   y2;
  int   i;

  i = 0;
  x = 0;
  y = 0;
  while (y < height)
    {
      while (x < width)
        {
          x2 = my_power_rec(x - x_center, 2);
          y2 = my_power_rec(y - y_center, 2);
          if (x2 + y2 - my_power_rec(rayon, 2) <= 0)
            {
              my_pixel_put_image(img_ptr, x, y, color);
            }
          x = x + 1;
        }
      x = 0;
      y = y + 1;
    }
}

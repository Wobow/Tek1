/*
** shapes.c for shapes in /home/balbo_a/rendu/Piscine-C-minilibX
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Oct 25 08:45:59 2013 Alan Balbo
** Last update Tue Nov 12 21:49:18 2013 Alan Balbo
*/

#include "head.h"

void    my_fill_area(t_info *infos, int x_start, int y_start, int x_stop, int y_stop, int color)
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
          my_pixel_put_image(infos, x, y, color);
          x = x + 1;
        }
      y = y + 1;
    }
}

void            my_draw_circle(t_info *infos, int x, int y, int rayon, int color)
{
  float         angle;
  int           j;
  int           i;

  angle = 0.0;
  while (angle < 7)
    {
      i = x + (rayon * cos(angle));
      j = y + (rayon * sin(angle));
      my_pixel_put_image(infos, i, j, color);
      angle = angle + (float)1 / (float)rayon;
    }
}

void    my_draw_disc(t_info *infos, int x_center, int y_center, int rayon, int color)
{
  int   x;
  int   y;
  int   x2;
  int   y2;
  int   i;

  i = 0;
  x = 0;
  y = 0;
  while (y < infos->height)
    {
      while (x < infos->width)
        {
          x2 = my_power_rec(x - x_center, 2);
          y2 = my_power_rec(y - y_center, 2);
          if (x2 + y2 - my_power_rec(rayon, 2) <= 0)
            {
              my_pixel_put_image(infos, x, y, color);
            }
          x = x + 1;
        }
      x = 0;
      y = y + 1;
    }
}

int     my_aff_rainbow(t_info *infos)
{
  int   rb[7];
  int   i;
  int   j;

  rb[0] = 0x00FF0000;
  rb[1] = 0x00FF5F00;
  rb[2] = 0x00FFFF00;
  rb[3] = 0x0038DA00;
  rb[4] = 0x0001939A;
  rb[5] = 0x001B1BB3;
  rb[6] = 0x00B900F1;
  i = 0;
  j = infos->height / 7;
  while (i < 7)
    {
      my_fill_area(infos, 0, i * j, infos->width, (i + 1) * j, rb[i]);
      i = i + 1;
    }
}

int     draw_line(t_info *infos, int x0, int y0, int x1, int y1)
{
  int   i;
  int   j;

  i = x0;
  j = y0;
  while (i != x1 || j != y1)
    {
      my_pixel_put_image(infos, i, j, 0x00FFFFFF);
      if (i != x1)
        i = i + 1;
      if (j != y1)
        j = j + 1;
    }
}

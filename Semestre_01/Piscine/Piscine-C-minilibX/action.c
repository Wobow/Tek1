/*
** action.c for action in /home/balbo_a/rendu/Piscine-C-minilibX
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Fri Oct 25 08:47:21 2013 Alan Balbo
** Last update Fri Oct 25 09:26:52 2013 Alan Balbo
*/

#include "head.h"

int	start_game(t_info *infos)
{
  int	i;

  i = 0;
  while (i < infos->height / 100)
    {
      infos->cols[i] = 0;
      i = i + 1;
    }
  draw_grid(infos);
  return (0);
}

int     draw_grid(t_info *infos)
{
  int   i;

  i = 0;
  while (i <= (infos->height / 100) - 1)
    {
      draw_line(infos, i * 100, 0, i * 100, infos->height);
      i = i + 1;
    }
}

int     put_in_cols(t_info *infos, int col)
{
  int   lvl;
  int   mid;
  int   color;

  if (infos->cols[col] < (infos->height / 100) - 1)
    {
      if (infos->joueur == 1)
        color = 0x00FF0000;
      else if (infos->joueur == -1)
        color = 0x00FFCC00;
      else if (infos->joueur == 3 || infos->joueur == -3)
        {
          color = 0;
          infos->joueur = -infos->joueur / 3;
        }
      lvl = infos->height - 50 - 105 * infos->cols[col];
      mid = ((col * 99) + ((col + 1) * 99)) / 2 + col;
      my_draw_disc(infos, mid, lvl, 49, color);
      infos->midlast = col;
      if (color != 0)
        infos->cols[col] = infos->cols[col] + 1;
    }
  else
    return (1);
  return (0);
}

int             my_pixel_put_image(t_info *infos, int x, int y, int color)
{
  int   i;

  i = y * infos->width + x;
  infos->data[i] = color;
  return (0);
}

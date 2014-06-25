/*
** events.c for events in /home/balbo_a/rendu/Piscine-C-minilibX
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Oct 25 08:48:05 2013 Alan Balbo
** Last update Thu Nov 21 13:08:05 2013 Alan Balbo
*/

#include "head.h"

int             expose(t_info *infos)
{
  mlx_put_image_to_window(infos->mlx_ptr, infos->win_ptr, infos->img, 0, 0);
}

int             get_key(int keycode, t_info *infos)
{
  if (keycode == 65307)
    {
      exit(0);
    }
  if (keycode == 114)
    {
      my_fill_area(infos, 0, 0, infos->width, infos->height, 0);
      expose(infos);
      start_game(infos);
    }
  if (keycode == 65455)
    {
      my_aff_rainbow(infos);
      expose(infos);
      start_game(infos);
    }
}

int             get_mouse(int button, int x, int y, t_info *infos)
{
  int           choice;

  if (button == 1)
    {
      choice = x / 100;
      if (!(put_in_cols(infos, choice)))
        {
          infos->joueur = -infos->joueur;
          expose(infos);
        }
    }
  else if (button == 3)
    {
      if (infos->midlast != -1)
        {
          infos->cols[infos->midlast] = infos->cols[infos->midlast] - 1;
          infos->joueur = infos->joueur * 3;
          put_in_cols(infos, infos->midlast);
          expose(infos);
          infos->midlast = -1;
        }
    }
}

/*
** head.h for head in /home/balbo_a/rendu/Piscine-C-minilibX
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Fri Oct 25 08:49:30 2013 Alan Balbo
** Last update Fri Oct 25 08:58:11 2013 Alan Balbo
*/

#ifndef HEAD_H
# define HEAD_H

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "../Piscine-C-include/my.h"

typedef struct  s_info
{
  int           joueur;
  int           *data;
  int           bpp;
  int           sizeline;
  int           endian;
  void          *mlx_ptr;
  void          *win_ptr;
  void          *img;
  int           width;
  int           height;
  int           *cols;
  int           midlast;
}               t_info;

int	start_game(t_info*);
int	draw_grid(t_info*);
int	put_in_cols(t_info*, int);
int	my_pixel_put_image(t_info*, int, int, int);

void	my_fill_area(t_info*, int, int, int, int, int);
void	my_draw_circle(t_info*, int, int, int, int);
void	my_draw_disc(t_info*, int, int, int, int);
int	my_aff_rainbow(t_info*);
int	draw_line(t_info*, int, int, int, int);

int	expose(t_info*);
int	get_key(int, t_info*);
int	get_mouse(int, int, int, t_info*);

#endif /* HEAD_H */

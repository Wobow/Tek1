/*
** head.h for head in /home/balbo_a/rendu/Maths/101pong
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Nov  4 20:04:51 2013 Alan Balbo
** Last update Wed Nov 13 13:25:58 2013 Alan Balbo
*/

#include <stdlib.h>
#include <mlx_int.h>
#include <mlx.h>
#include <my_lib_C.h>

# define SIZE_BALL 10

typedef struct	s_oussa
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  int		width;
  int		height;
  int		x_pos_t;
  int		y_pos_t;
  int		z_pos_t;
  int		vx_dir;
  int		vy_dir;
  int		vz_dir;
  int		n;
}		t_oussa;

/*
** head.h for head in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Nov 14 00:00:25 2013 Alan Balbo
** Last update Fri Nov 15 13:01:31 2013 Alan Balbo
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <my_lib_C.h>
#include <mlx_int.h>
#include <mlx.h>

# define S_BALL 5
# define W 900
# define H 800
# define T W*H
# define COLOR_PIT 0x00D8005F
# define COLOR_BG 0
# define COLOR_CORE 0x00336699
# define COLOR_BALL 0x00CCCCCC
# define COLOR_BD_BALL 0x00D8005E
# define COLOR_LINE 0x00666666
# define SPEED_BALL 15
# define PIT_SPEED 20
# define NB_BALL 1

typedef struct	s_ole
{
  void		*mlx;
  void		*win;
  void		*img;
  int		pit;
  int		*oball;
  int		*ball;
  int		*vx;
  int		*vy;
  int		*hitbox;
  int		state;
}		t_ole;

int	get_pointer(int, int, t_ole*);
int	caca(int, t_ole*);
int	expose(t_ole*);
int	get_key(int, t_ole*);

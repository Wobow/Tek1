/*
** head.h for head in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Nov 14 00:00:25 2013 Alan Balbo
** Last update Sun Nov 17 16:45:50 2013 Alan Balbo
*/

#ifndef HEAD_H_

# define HEAD_H_

#include <math.h>
#include <stdlib.h>
#include <my_lib_C.h>
#include <mlx_int.h>
#include <mlx.h>

# define S_BALL 10
# define W 900
# define H 800
# define T W*H
# define COLOR_PIT 0x00D8005F
# define COLOR_BG 0
# define COLOR_CORE 0x00336699
# define COLOR_BALL 0x00CCCCCC
# define COLOR_BD_BALL 0x00D8005E
# define COLOR_LINE 0x00666666
# define COLOR_FRAME 0x00A62F00
# define SPEED_BALL 5
# define PIT_SPEED 20
# define NB_COLORS 10
# define SCORING_PIT 5
# define SCORING_TIP 1
# define SPEED_SHIP 20
# define SIZE_CORE W / 12
# define SIZE_SHIP W / 10

typedef struct	s_ole
{
  void		*mlx;
  void		*win;
  void		*img;
  int		pit;
  int		oball;
  int		ball;
  float		vx;
  float		vy;
  int		*hitbox;
  void		*img_lose;
  int		state;
  int		color_picked;
  int		*colors;
  int		score;
  int		pos_ypit;
  int		pos_xpit;
}		t_ole;

int	get_click(int, t_ole*);
int	get_pointer(int, int, t_ole*);
int	expose(t_ole*);
int	get_key(int, t_ole*);

#endif /* HEAD_H_ */

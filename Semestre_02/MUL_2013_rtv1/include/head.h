/*
** head.h for head in /home/balbo_a/rendu/PSU_2013_minishell1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Dec  9 05:36:26 2013 BALBO Alan
** Last update Sun Mar 16 21:21:17 2014 BALBO Alan
*/

#ifndef HEAD_H_
# define HEAD_H_

# include <mlx.h>
# include <mlx_int.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "my.h"

# define W 800
# define H 800
# define XO -300
# define YO 0
# define ZO 5
# define MLX_ERR my_putstr("Mlx error\n")
# define ARG_ERR my_putstr("rtv1 needs a conf file to run\n")
# define ESC_KEY 65307
# define SPOTX -300
# define SPOTY 0
# define SPOTZ 5

typedef struct	s_o
{
  int		shape;
  int		l;
  int		posx;
  int		posy;
  int		posz;
  int		color;
  struct s_o	*next;
}		t_o;

typedef struct	s_v
{
  double	vx;
  double	vy;
  double	vz;
}		t_v;

typedef struct	s_t
{
  void		*mlx;
  void		*win;
  void		*img;
  t_o		*head;
}		t_t;

int		expose(t_t*);
int		gere_key(int, t_t*);
int		intersect_plan(t_v*, t_o*);
int		intersect_sphere(t_v*, t_o*);
int		intersect_cone(t_v*, t_o*);
int		intersect_cylindre(t_v*, t_o*);

#endif /* HEAD_H_ */

/*
** head.h for head in /home/balbo_a/rendu/PSU_2013_minishell1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Dec  9 05:36:26 2013 BALBO Alan
** Last update Fri Feb 21 14:21:36 2014 BALBO Alan
*/

#ifndef HEAD_H_
# define HEAD_H_

# include <mlx.h>
# include <mlx_int.h>
# include <my.h>

# define K ((float)t->k / 100.0)
# define W 1000
# define H 1000

# define COLOR1 0x00FFFF00
# define COLOR2 0x00CCCC00

# define ARG_ERR my_putstr("Argument error.\n")
# define MLX_ERR my_putstr("Mlx error.\n")
# define SEC_ERR my_putstr("Error : check your arguments.\n")

typedef struct	s_t
{
  void		*mlx;
  void		*win;
  void		*img;
  int		k;
}		t_t;

int		expose(t_t*);
void		init_graph(t_t*);
int		gere_key(int, t_t*);

#endif /* HEAD_H_ */

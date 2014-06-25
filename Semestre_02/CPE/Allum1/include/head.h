/*
** head.h for head in /home/balbo_a/rendu/PSU_2013_minishell1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Dec  9 05:36:26 2013 BALBO Alan
** Last update Sun Feb 16 18:18:22 2014 BALBO Alan
*/

#ifndef HEAD_H_
# define HEAD_H_

# include <mlx.h>
# include <mlx_int.h>
# include <ncurses.h>
# include <term.h>
# include "my.h"

# define NB_LINE	4
# define NB_COL		7

# define CUR_CASE	t->board[j + i * t->nb_col]

# define BOR_ERR	"Map error, can't generate board\n"

typedef struct		s_l
{
  int			nb_alum;
  int			selected;
  char			*content;
  struct s_l		*prev;
  struct s_l		*next;
}			t_l;

typedef struct		s_a
{
  int			nb_line;
  int			nb_col;
  char			*board;
  t_l			*head;
  int			alive;
  int			turn;
  struct termios	term;
}			t_a;

void			display_board(t_a*);
void			change_select(int, t_l*);
void			get_wait(t_a*);
int			init_board(t_a*);
void			go_ia(t_a*);
int			count_alum(t_l*);
void			win_game(t_a*);
void			delete_alum(int, t_l*, int);
int			put_behave(int);
void			my_exit(t_a*);
void			xtcget(t_a*);
void			xtcset(t_a*);
int			init_tc(t_a*);
int			reinit_tc(t_a*);
int			check_case(t_a*, t_l*, int);

#endif /* HEAD_H_ */

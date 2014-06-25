/*
** my.h for header in /home/gotti_q/My_Work/Tek1/Corewar
**
** Made by quentin gotti
** Login   <gotti_q@epitech.net>
**
** Started on  Thu Apr  3 11:58:33 2014 quentin gotti
** Last update Sat Apr 12 12:23:22 2014 Alan BALBO
*/

#ifndef MY_H_
# define MY_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"

char	*get_next_line(int fd);
x
typedef struct	s_prog
{
  struct s_prog	*next;
  char		reg[REG_NUMBER * REG_SIZE];
  int		exec;
  int		ncycle;
  int		pc;
  char		np;
  char		mem;
  char		param[MAX_ARGS_NUMBER * 4];
}		t_prog;

typedef	struct	s_info
{
  char		carry;
  char		verif[4];
  char		nbj;
  char		*vm;
  int		nb_live;
  int		delta;
  int		cycle;
  int		nice;
}		t_info;

# define PC		p->pc
# define P_REG		0
# define P_DIR		1
# define P_IND		2
# define P_LAB		3

# define TYPE_PARAM1	(p->mem / 64)
# define TYPE_PARAM2	(p->mem / 16) % 4
# define TYPE_PARAM3	(p->mem / 4) % 4

int	my_live(t_info*, t_prog*);
int	my_ld(t_info*, t_prog*);
int	my_st(t_info*, t_prog*);
int	my_add(t_info*, t_prog*);
int	my_sub(t_info*, t_prog*);
int	my_and(t_info*, t_prog*);
int	my_or(t_info*, t_prog*);
int	my_xor(t_info*, t_prog*);
int	my_zjmp(t_info*, t_prog*);
int	my_ldi(t_info*, t_prog*);
int	my_sti(t_info*, t_prog*);
int	my_fork(t_info*, t_prog*);
int	my_lld(t_info*, t_prog*);
int	my_lldi(t_info*, t_prog*);
int	my_lfork(t_info*, t_prog*);
int	my_aff(t_info*, t_prog*);

# endif

/*
** my.h for header in /home/gotti_q/My_Work/Tek1/Corewar
**
** Made by quentin gotti
** Login   <gotti_q@epitech.net>
**
** Started on  Thu Apr  3 11:58:33 2014 quentin gotti
** Last update Sun Apr 13 11:12:48 2014 Alan BALBO
*/

#ifndef VM_H_
# define VM_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "my.h"
# include "op.h"

typedef struct	s_prog
{
  struct s_prog	*next;
  char		reg[REG_NUMBER * REG_SIZE];
  int		exec;
  int		ncycle;
  int		pc;
  char		np;
  int		mem;
  int		lenp;
  header_t	head;
  char		param[MAX_ARGS_NUMBER * 4];
}		t_prog;

typedef	struct	s_info
{
  char		carry;
  char		verif[4];
  char		nbj;
  char		*vm;
  char		*prog_list[4];
  int		nb_live;
  int		delta;
  int		cycle;
  int		nice;
}		t_info;

# define TYPE_PARAM1    (p->mem / 64)
# define TYPE_PARAM2    (p->mem / 16) % 4
# define TYPE_PARAM3    (p->mem / 4) % 4
# define PC		p->pc
# define P_REG		0
# define P_DIR		1
# define P_IND		2
# define P_LAB		3

# define PARAM1		get_param(p, 0)
# define PARAM2		get_param(p, 1)
# define PARAM3		get_param(p, 2)

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

int	get_param(t_prog*, int);
int	get_index(int, int, int);
int	get_ind_value(t_info*, t_prog*, int, int);
int	get_reg_value(t_prog*, int);

int	look_cycle(int exec, int cycle);
int    	check_verif(t_info *s);
int	return_dilw(t_info *s, t_prog *lp, int i, int t);
int	does_it_look_well(t_info *s, t_prog *lp);

void	*def_tab();
void	def_reg(t_prog *s, int i);
void	def_arg(t_prog *lp, t_info *s);
t_prog	*def_prog(int ac, char **av, t_info *s);
t_info	*def_info(int ac);

void	fill_this_vm(t_info *s, char *champ, int pc, t_prog *p);
void	def_proglist(int nbj, t_info *s, t_prog *p);

void	redf(t_prog *cur, t_info *s);
void	go_exec(t_info *s, t_prog *lp, int (**tab_fct)());
void	my_fwin(t_prog *lp, int x, int max);

int	put_ind(t_info *s, t_prog *lp, int t, int x);
int	put_dir(t_info *s, t_prog *lp, int t, int x);
int	put_reg(t_info *s, t_prog *lp, int t, int x);

int	b_to_l(int nb);
void	clear_arg(t_prog *lp);
int	my_exept(t_prog *lp);
void	my_affect(t_prog *lp, int temp, int t);

# endif /* VM_H */

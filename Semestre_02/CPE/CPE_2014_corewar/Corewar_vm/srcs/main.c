/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Wed Apr  9 16:42:01 2014 BALBO Alan
*/

#include "op.h"

typedef struct	s_info
{
  int		param[5];
  char		carry;
  char		verif[4];
  char		nbj;
  int		nb_live;
  int		delta;
}		t_info;

#define PC t->pc

//int	my_live(t_info*, t_prog*);
//int	my_ld(t_info*, t_prog*);
//int	my_st(t_info*, t_prog*);
//int	my_add(t_info*, t_prog*);
//int	my_sub(t_info*, t_prog*);
//int	my_and(t_info*, t_prog*);
//int	my_or(t_info*, t_prog*);
//int	my_xor(t_info*, t_prog*);
//int	my_zjump(t_info*, t_prog*);
//int	my_ldi(t_info*, t_prog*);
int	my_sti(t_info*, t_prog*);
int	my_fork(t_info*, t_prog*);
//int	my_lld(t_info*, t_prog*);
//int	my_lldi(t_info*, t_prog*);
int	my_lfork(t_info*, t_prog*);
int	my_aff(t_info*, t_prog*);


int	get_index(int pc, int ind, int mod)
{
  if (mod != 0)
    ind = ind % mod;
  while (ind != 0)
    {
      if (pc == MEM_SIZE)
	pc = 0;
      else
	pc++;
      ind--;
    }
  return (pc);
}

int	my_live(t_info *t, t_prog *p)
{
  t->nb_live++;
  if (t->param[0] < 4 && t->param[0])
    t->verif[t->param[0]] = 1;
  if (t->nb_live % NBR_LIVE == 0)
    t->delta += CYCLE_DELTA;
  return (0);
}

int	my_ld(t_info *t, t_prog *p)
{
  int	pos;
  int	i;

  if (t->param[0] && t->param[0] < 3 && t->param[0] > 0 &&
      t->param[2] < REG_NUMBER)
    {
      if (t->param[3] && t->param[3] < REG_NUMBER)
	{
	  if (my_getnbr(t->param[0]) == P_DIR)
	    PC = my_getnbr(t->param[1]);
	  else
	    PC = get_index(PC, my_getnbr(t->param[1]), IDX_MOD);
	  i = 0;
	  while (i < REG_SIZE)
	    {
	      p->reg[my_getnbr(t->param[2]) * REG_SIZE + i] = t->vm[PC + i];
	      i++;
	    }
	}
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int	my_st(t_info *t, t_prog *p)
{
  int	i;

  if (t->param[0] && t->param[0] < REG_NUMBER)
    {
      if (t->param[1] == P_IND)
	while (i < REG_SIZE)
	  {
	    t->vm[get_index(PC, my_getnbr(t->param[2]) + i, IDX_MOD)] = p->reg[my_getnbr(t->param[0]) + i];
	    i++;
	  }
      else if (t->param[2] < REG_NUMBER)
	while (i < REG_SIZE)
	  {
	    p->reg[my_getnbr(t->param[2]) + i] = p->reg[my_getnbr(t->param[0]) + i];
	    i++;
	  }
      return (0);
    }
  return (1);
}

int	my_add(t_info *t, t_prog *p)
{
  if (t->param[0] && t->param[1] && t->param[2] &&
      t->param[0] > 0 && t->param[1] > 0 && t->param[2] > 0 &&
      t->param[0] <= REG_NUMBER && t->param[1] <= REG_NUMBER &&
      t->param[2] <= REG_NUMBER)
    p->reg[t->param[2]] = p->reg[t->param[0]] + p->reg[t->param[1]];
  else
    return (1);
  return (0);
}

int	my_sub(t_info *t, t_prog *p)
{
  if (t->param[0] && t->param[1] && t->param[2] &&
      t->param[0] > 0 && t->param[1] > 0 && t->param[2] > 0 &&
      t->param[0] <= REG_NUMBER && t->param[1] <= REG_NUMBER &&
      t->param[2] <= REG_NUMBER)
    p->reg[t->param[2]] = p->reg[t->param[0]] - p->reg[t->param[1]];
  else
    return (1);
  return (0);
}

int	my_and(t_info *t, t_prog *p)
{
  int	i;
  int	p[2];

  i = -1;
  while (++i && t->param[i] && i < 6);
  if (i != 6)
    return (1);
  if (t->param[0] == T_REG)
    p[0] = p->reg[t->param[1]];
  else if (t->param[0] == T_IND)
    p[0] = t->vm[get_index(PC, t->param[1], 1)];
  else
    p[0] = t->param[1];
  if (t->param[2] == T_REG)
    p[1] = p->reg[t->param[3]];
  else if (t->param[2] == T_IND)
    p[1] = t->vm[get_index(PC, t->param[3], 1)];
  else
    p[1] = t->param[1];
  p->reg[t->param[5]] = p[0] & p[1];
  t->carry = -t->carry + 1;
  return (0);
}

int	my_or(t_info *t, t_prog *p)
{
  int	i;
  int	p[2];

  i = -1;
  while (++i && t->param[i] && i < 6);
  if (i != 6)
    return (1);
  if (t->param[0] == T_REG)
    p[0] = p->reg[t->param[1]];
  else if (t->param[0] == T_IND)
    p[0] = t->vm[get_index(PC, t->param[1], 1)];
  else
    p[0] = t->param[1];
  if (t->param[2] == T_REG)
    p[1] = p->reg[t->param[3]];
  else if (t->param[2] == T_IND)
    p[1] = t->vm[get_index(PC, t->param[3], 1)];
  else
    p[1] = t->param[1];
  p->reg[t->param[5]] = p[0] | p[1];
  t->carry = -t->carry + 1;
  return (0);
}

int	my_xor(t_info *t, t_prog *p)
{
  int	i;
  int	p[2];

  i = -1;
  while (++i && t->param[i] && i < 6);
  if (i != 6)
    return (1);
  if (t->param[0] == T_REG)
    p[0] = p->reg[t->param[1]];
  else if (t->param[0] == T_IND)
    p[0] = t->vm[get_index(PC, t->param[1], 1)];
  else
    p[0] = t->param[1];
  if (t->param[2] == T_REG)
    p[1] = p->reg[t->param[3]];
  else if (t->param[2] == T_IND)
    p[1] = t->vm[get_index(PC, t->param[3], 1)];
  else
    p[1] = t->param[1];
  p->reg[t->param[5]] = p[0] ^ p[1];
  t->carry = -t->carry + 1;
  return (0);
}

int	my_zjmp(t_info *t, t_prog *p)
{
  int	i;

  if (t->param[0])
    {
      if (t->carry == 1)
	{
	  i = my_getnbr(t->param[0]);
	  while (i != 0)
	    {
	      if (t->pc % MEM_SIZE >= 1)
		PC = 0;
	      else
		PC++;
	      i--;
	    }
	}
      return (0);
    }
  return (1);
}

int	my_ldi(t_info *t, t_prog *p)
{
  int	pos;
  int	i;

  if (t->param[0] && t->param[0] < 3 && t->param[0] > 0 &&
      t->param[2] < REG_NUMBER)
    {
      if (t->param[3] && t->param[3] < REG_NUMBER)
	{
	  if (my_getnbr(t->param[0]) == P_DIR)
	    PC = my_getnbr(t->param[1]);
	  else
	    PC = get_index(PC, my_getnbr(t->param[1]), IDX_MOD);
	  i = 0;
	  while (i < REG_SIZE)
	    {
	      p->reg[my_getnbr(t->param[2]) * REG_SIZE + i] = t->vm[PC + i];
	      i++;
	    }
	}
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int	my_sti(t_info *t, t_prog *p)
{

}

int	my_fork(t_info *t, t_prog *p)
{

}

int	my_lld(t_info *t, t_prog *p)
{
  int	pos;
  int	i;

  if (t->param[0] && t->param[0] < 3 && t->param[0] > 0 &&
      t->param[2] < REG_NUMBER)
    {
      if (t->param[3] && t->param[3] < REG_NUMBER)
	{
	  if (my_getnbr(t->param[0]) == P_DIR)
	    PC = my_getnbr(t->param[1]);
	  else
	    PC = get_index(PC, my_getnbr(t->param[1]), 1);
	  i = 0;
	  while (i < REG_SIZE)
	    {
	      p->reg[my_getnbr(t->param[2]) * REG_SIZE + i] = t->vm[PC + i];
	      i++;
	    }
	}
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int	my_lldi(t_info *t, t_prog *p)
{
  int	pos;
  int	i;

  if (t->param[0] && t->param[0] < 3 && t->param[0] > 0 &&
      t->param[2] < REG_NUMBER)
    {
      if (t->param[3] && t->param[3] < REG_NUMBER)
	{
	  if (my_getnbr(t->param[0]) == P_DIR)
	    PC = my_getnbr(t->param[1]);
	  else
	    PC = get_index(PC, my_getnbr(t->param[1]), 1);
	  i = 0;
	  while (i < REG_SIZE)
	    {
	      p->reg[my_getnbr(t->param[2]) * REG_SIZE + i] = t->vm[PC + i];
	      i++;
	    }
	}
      t->carry = 0 - t->carry + 1;
      return (0);
    }
  return (1);
}

int	my_lfork(t_info *t, t_prog *p)
{

}

int	my_aff(t_info *t, t_prog *p)
{

}

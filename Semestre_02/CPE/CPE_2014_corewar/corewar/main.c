/*
** main.c for main in /home/gotti_q/My_Work/Tek1/corewar
**
** Made by quentin gotti
** Login   <gotti_q@epitech.net>
**
** Started on  Thu Apr 10 23:39:01 2014 quentin gotti
** Last update Fri Apr 11 11:38:35 2014 Alan BALBO
*/

#include "my.h"

int		b_to_l(int nb)
{
  int		result;

  result = ((nb & 0x000000FF) << 24) + ((nb & 0xFF000000) >> 24);
  result += ((nb & 0x0000FF00) << 8) + ((nb & 0x00FF0000) >> 8);
  return (result);
}

void		*def_tab()
{
  int		(**tab_fct)();

  if ((tab_fct = malloc(sizeof(int*) * 16)) == NULL)
    exit(write(1, "Fail alloc\n", 11));
  tab_fct[0] = &my_live;
  tab_fct[1] = &my_ld;
  tab_fct[2] = &my_st;
  tab_fct[3] = &my_add;
  tab_fct[4] = &my_sub;
  tab_fct[5] = &my_and;
  tab_fct[6] = &my_or;
  tab_fct[7] = &my_xor;
  tab_fct[8] = &my_zjmp;
  tab_fct[9] = &my_ldi;
  tab_fct[10] = &my_sti;
  tab_fct[11] = &my_fork;
  tab_fct[12] = &my_lld;
  tab_fct[13] = &my_lldi;
  tab_fct[14] = &my_lfork;
  tab_fct[15] = &my_aff;
  return (tab_fct);
}

int		def_reg(t_prog *s, int i)
{
  int		j;

  j = 0;
  while (j < REG_NUMBER * REG_SIZE)
    {
      if (j == (i + 1) * REG_SIZE - 1)
	s->reg[j] = i + 1;
      else
	s->reg[j] = 0;
      j = j + 1;
    }
}

int		fill_this_vm(t_info *s, char *champ, int pc)
{
  int		fd;
  header_t	head;
  int		i;

  i = 0;
  if ((fd = open(champ, O_RDONLY)) == -1)
    exit(write(1, "I don't think all your champs exist\n", 36));
  if (read(fd, head, sizeof(head)) == -1)
    exit(write(1, "Can't read this\n", 16));
  if (b_to_l(head.magic) != COREWAR_EXEC_MAGIC)
    exit(write(1, "There's a champ that hasn't been compilated well\n", 49));
  while (read(fd, s->vm + pc + i, 1) != -1)
    i = i + 1;
}

int		look_cycle(int exec, int cycle)
{
  int		tab[16];

  tab[0] = 10;
  tab[1] = 5;
  tab[2] = 5;
  tab[3] = 10;
  tab[4] = 10;
  tab[5] = 6;
  tab[6] = 6;
  tab[7] = 6;
  tab[8] = 20;
  tab[9] = 25;
  tab[10] = 25;
  tab[11] = 25;
  tab[12] = 800;
  tab[13] = 50;
  tab[14] = 1000;
  tab[15] = 2;
  return (tab[exec] + cycle);
}

int		put_ind(t_info *s, t_prog *lp, int t)
{
  int		i;

  i = 0;
  while (i < IND_SIZE)
    {
      lp->param[t + i] = s->vm[lp->pc + 5 + (IND_SIZE - i - 1) + t];
      i = i + 1;
    }
  return (i);
}

int		put_dir(t_info *s, t_prog *lp, int t)
{
  int		i;

  i = 0;
  while (i < DIR_SIZE)
    {
      lp->param[t + i] = s->vm[lp->pc + 5 + (DIR_SIZE - i - 1) + t];
      i = i + 1;
    }
  return (i);
}

int		put_reg(t_info *s, t_prog *lp, int t)
{
    int		i;

  i = 0;
  lp->param[t + i] = s->vm[lp->pc + 5 + t];
  i = i + 1;
  return (i);
}

int		def_arg(t_prog *lp, t_info *s)
{
  int		i;
  int		x;
  int		y;
  unsigned char	temp;
  int		t;

  i = 0;
  t = 0;
  x = 64;
  temp = s->vm[lp->pc + 4];
  if (s->vm[lp->pc + 4] < 0)
    temp = temp + 256;
  while (i < 4)
    {
      if (temp / x % 4 == 3)
	t = t + put_ind(s, lp, t);
      else if (temp / x % 4 == 2)
	t = t + put_dir(s, lp, t);
      else if (temp / x % 4 == 1)
	t = t + put_reg(s, lp, t);
      x = x / 4;
      i = i + 1;
    }
  lp->mem = t + 5;
}

t_prog		*def_prog(int ac, char **av, t_info *s)
{
  int		i;
  t_prog	*first;
  t_prog	*cur;

  i = 0;
  if ((first = malloc(sizeof(*first))) == NULL)
    exit(write(1, "Fail alloc\n", 11));
  cur = first;
  while (i < ac - 1)
    {
      def_reg(cur, i);
      cur->pc = MEM_SIZE / 4 * i;
      fill_this_vm(s, av[i + 1], cur->pc);
      cur->exec = b_to_l(((int*)(s->vm + cur->pc))[0]);
      cur->ncycle = look_cycle(cur->exec - 1, s->cycle);
      def_arg(cur, s);
      cur->np = i + 1;
      if ((cur->next = malloc(sizeof(*first))) == NULL)
	exit(write(1, "Fail alloc\n", 11));
      cur = cur->next;
      i = i + 1;
    }
  cur = NULL;
  return (first);
}

t_info		*def_info(int ac)
{
  t_info	*s;
  int		i;

  i = 0;
  if ((s = malloc(sizeof(*s))) == NULL)
    exit(write(1, "Fail alloc\n", 11));
  if ((s->vm = malloc(MEM_SIZE + 1)) == NULL)
    exit(write(1, "Fail alloc\n", 11));
  while (i < MEM_SIZE)
    {
      s->vm[i] = 0;
      i = i + 1;
    }
  s->carry = 0;
  s->verif[0] = 0;
  s->verif[1] = 0;
  s->verif[2] = 0;
  s->verif[3] = 0;
  s->nbj = ac - 1;
  s->delta = 0;
  s->nb_live = 0;
  s->cycle = 0;
  return (s);
}

int		check_verif(t_info *s)
{
  int		i;
  int		t;

  i = 0;
  t = 0;
  if (s->cycle >= s->nice)
    {
      while (s->verif[i])
	{
	  if (s->verif[i] == 0)
	    s->verif[i] = -1;
	  else if (s->verif[i] > 0)
	    {
	      s->verif[i] = 0;
	      t = t + 1;
	    }
	  i = i + 1;
	}
      s->nice = s->nice + CYCLE_TO_DIE - s->delta;
      return (t);
    }
  else
    return (2);
}

int		redf(t_prog *cur, t_info *s)
{
  int		i;

  i = 0;
  cur->exec = b_to_l(((int*)(s->vm + cur->pc))[0]);
  if (cur->exec < 1 || cur->exec > 16)
    {
      cur->ncycle = look_cycle(cur->exec - 1, s->cycle);
      def_arg(cur, s);
    }
}

int		go_exec(t_info *s, t_prog *lp, int (**tab_fct)())
{
  t_prog	*cur;

  cur = lp;
  while (cur != NULL)
    {
      if (cur->exec == 0)
	{
	  cur->pc = (cur->pc + 1) % MEM_SIZE;
	  redf(cur, s);
	}
      else if (cur->ncycle == s->cycle)
	{
	  tab_fct[cur->exec](s, cur);
	  cur->pc = (cur->pc + cur->mem) % MEM_SIZE;
	  redf(cur, s);
	}
      cur = cur->next;
    }
}

int		main(int ac, char **av)
{
  t_prog	*lp;
  t_info	*s;
  int		nice;
  int		(**tab_fct)();

  if (ac < 3)
    return (write(1, "Quel combat passionant\n", 23));
  s = def_info(ac);
  nice = CYCLE_TO_DIE;
  lp = def_prog(ac, av, s);
  tab_fct = def_tab();
  while (check_verif(s) > 1)
    {
      go_exec(s, lp, tab_fct);
      s->cycle = s->cycle + 1;
    }
}

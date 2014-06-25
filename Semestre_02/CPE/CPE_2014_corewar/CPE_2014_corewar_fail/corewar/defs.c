/*
** defs.c for defs in /home/balbo_a/rendu/CPE_2014_corewar/corewar/srcs
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Apr 13 11:00:48 2014 Alan BALBO
** Last update Sun Apr 13 18:44:26 2014 Alan BALBO
*/

#include "vm.h"

void		*def_tab()
{
  int		(**tab_fct)();

  if ((tab_fct = malloc(sizeof(int*) * 16)) == NULL)
    exit(my_printf("Can't perform malloc\n"));
  tab_fct[0] = my_live;
  tab_fct[1] = my_ld;
  tab_fct[2] = my_st;
  tab_fct[3] = my_add;
  tab_fct[4] = my_sub;
  tab_fct[5] = my_and;
  tab_fct[6] = my_or;
  tab_fct[7] = my_xor;
  tab_fct[8] = my_zjmp;
  tab_fct[9] = my_ldi;
  tab_fct[10] = my_sti;
  tab_fct[11] = my_fork;
  tab_fct[12] = my_lld;
  tab_fct[13] = my_lldi;
  tab_fct[14] = my_lfork;
  tab_fct[15] = my_aff;
  return (tab_fct);
}

void		def_reg(t_prog *s, int i)
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

void		def_arg(t_prog *lp, t_info *s)
{
  int		x;
  int		temp;
  int		t;
  int		i;

  t = 0;
  x = 64;
  clear_arg(lp);
  if ((i = my_exept(lp)) == 1)
    temp = s->vm[lp->pc + 1];
  else
    temp = lp->mem;
  if (s->vm[lp->pc + 1] < 0)
    temp = temp + 256;
  while (x >= 1)
    {
      if (temp / x % 4 == 3)
	t = t + put_ind(s, lp, t, i);
      else if (temp / x % 4 == 2)
	t = t + put_dir(s, lp, t, i);
      else if (temp / x % 4 == 1)
	t = t + put_reg(s, lp, t, i);
      x = x / 4;
    }
  my_affect(lp, temp, t + 1 + i);
}

t_pars		*get_player(t_pars *head, int i)
{
  t_pars	*cur;

  cur = head;
  while (cur != NULL)
    {
      if (cur->nbj == i)
	return (cur);
      cur = cur->next;
    }
  return (cur);
}

void		aff_cur(t_prog *head)
{
  t_prog	*cur;

  cur = head;
  while (cur != NULL)
    {
      my_printf("{\n\tnext = %p\n\treg[0] = %c\n\texec = %d\n\tncycle = %d\n\tpc = %d\n\tnp = %d\n\tmem = %d\n\tlenp = %d\n\thead.name = %s\n\tfuck params\n}\n\n", cur->next, cur->reg[0], cur->exec, cur->ncycle, cur->pc, cur->np, cur->mem, cur->lenp, cur->head.prog_name);
      cur = cur->next;
    }
}

t_prog		*def_prog(t_pars *head, t_info *s)
{
  t_prog	*first;
  t_prog	*cur;
  int		i;
  t_pars	*tmp;

  if ((first = malloc(sizeof(*first))) == NULL)
    exit(my_printf("Can't perform malloc\n"));
  cur = first;
  tmp = head;
  i = 0;
  while ((tmp = get_player(head, i + 1)) != NULL)
    {
      def_reg(cur, tmp->nbj);
      cur->pc = tmp->pos;
      if (cur->pc == -1)
	cur->pc = MEM_SIZE / 4 * tmp->nbj;
      fill_this_vm(s, tmp->name, cur->pc, cur);
      cur->exec = (s->vm + cur->pc)[0];
      cur->ncycle = look_cycle(cur->exec - 1, s->cycle);
      def_arg(cur, s);
      cur->np = head->nbj;
      if ((cur->next = malloc(sizeof(*first))) == NULL)
	exit(my_printf("Can't perform malloc\n"));
      cur = cur->next;
      i++;
    }
  cur = first;
  while (cur->next->next != NULL)
    cur = cur->next;
  cur->next = NULL;
  return (first);
}

t_info		*def_info(int ac)
{
  t_info	*s;
  int		i;

  i = 0;
  if ((s = malloc(sizeof(*s))) == NULL)
    exit(my_printf("Can't perform malloc\n"));
  if ((s->vm = malloc(MEM_SIZE + 1)) == NULL)
    exit(my_printf("Can't perform malloc\n"));
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
  s->nice = CYCLE_TO_DIE;
  return (s);
}

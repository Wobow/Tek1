/*
** main.c for Corewar in /home/cesar_a/rendu/Coreware/ASM
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Tue Mar 18 10:25:47 2014 Aymeric CESAR
** Last update Sun Apr 13 09:52:46 2014 Aymeric CESAR
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "my/my.h"

void	my_chk_lab(char *s, lb_t **lb, int cur)
{
  lb_t	*tmp;

  if (*lb)
    {
      tmp = *lb;
      while (tmp->next)
	tmp = tmp->next;
      tmp = (tmp->next = my_malloc(sizeof(*tmp)));
    }
  else
    tmp = (*lb = my_malloc(sizeof(**lb)));
  s[my_strlen(s) - 1] = 0;
  tmp->next = 0;
  tmp->name = s;
  tmp->cur = cur;
}

char	my_get_type(char **str, int *cur, int cmd, int i)
{
  if (**str == DIRECT_CHAR)
    {
      (*str)++;
      if (op_tab[cmd].type[i] & T_DIR && (*cur += DIR_SIZE))
	return (2);
      my_putstr("Error: Wrong type of argument.");
      exit(1);
    }
  else if (**str == 'r')
    {
      (*str)++;
      if (op_tab[cmd].type[i] & T_REG && (++*cur))
	return (1);
      my_putstr("Error: Wrong type of argument.");
      exit(1);
    }
  if (op_tab[cmd].type[i] & T_IND && (*cur += IND_SIZE))
    return (3);
  my_putstr("Error: Wrong type of argument.");
  exit(1);
}

int	check_args(char *arg, bop_t *bop, int *cur)
{
  int	nb;
  int	lb;
  char	**arg_tab;
  int	i;

  i = 0;
  bop->args = (arg_tab = my_arg_to_wordtab(arg));
  *cur += 2;
  nb = 0;
  lb = 0;
  bop->type[0] = my_get_type(arg_tab, cur, bop->cmd, 0);
  while (arg_tab[++nb])
    bop->type[nb] = my_get_type(arg_tab + nb, cur, bop->cmd, nb);
  if (nb != op_tab[bop->cmd].nbr_args)
    return (-1 + i);
  while (nb < 4)
    bop->type[++nb] = 0;
  return (lb);
}

void	my_get_ls(char *s, bop_t **bop, int *cur, int cmd)
{
  bop_t	*tmp;

  if (*bop)
    {
      tmp = *bop;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = my_malloc(sizeof(*tmp));
      tmp = tmp->next;
    }
  else
    tmp = (*bop = my_malloc(sizeof(*tmp)));
  tmp->cmd = cmd;
  if ((tmp->label = check_args(s, tmp, cur)) == -1)
    {
      write(2, "Syntax error\n", 13);
      exit(1);
    }
  tmp->next = 0;
}

void	my_get_cmd(char **s, int *cur, bop_t **bop, lb_t **lb)
{
  int	i;

  if (*s && **s && **s != COMMENT_CHAR)
    {
      i = -1;
      if (*s && s[0][my_strlen(s[0]) - 1] == LABEL_CHAR)
	my_chk_lab(s++[0], lb, *cur);
      while (op_tab[++i].mnemonique && my_strcmp(s[0], op_tab[i].mnemonique));
      if (op_tab[i].mnemonique)
	my_get_ls(s[1], bop, cur, i);
      else
	my_printf("Error: Unrecognized %s\n", s[0]);
    }
}

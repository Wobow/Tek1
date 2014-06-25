/*
** wr_in_folder.c for corewar in /home/cesar_a/rendu/CPE_2014_corewar/ASM
**
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
**
** Started on  Fri Apr 11 23:45:03 2014 Aymeric CESAR
** Last update Sun Apr 13 14:31:10 2014 Alan BALBO
*/

#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "my/my.h"

void	my_wr_xo(int fd, int *nbr, int size)
{
  int	i;

  i = -1;
  while (++i < size)
    write(fd, (char*)nbr + 3 - i, 1);
}

int	my_be(int i)
{
  char	c1;
  char	c2;
  char	c3;
  char	c4;

  c1 = (i & 0xFF000000) / 0x1000000;
  c2 = (i & 0xFF0000) / 0x10000;
  c3 = (i & 0xFF00) / 0x100;
  c4 = i & 0xFF;
  return (((c4 * 0x1000000) & 0xFF000000) + ((c3 * 0x10000) & 0xFF0000) +
	  ((c2 * 0x100) & 0xFF00) + (c1 & 0xFF));
}

int	my_check_lab(char *lab, lb_t *lb, int cur)
{
  while (lb && my_strcmp(lab, lb->name))
    lb = lb->next;
  if (!lb)
    {
      my_printf("Undefined label %s\n", lab);
      exit(0);
    }
  return (lb->cur - cur);
}

void	my_wr_arg(bop_t *bop, int *cur, int *cur2, int c, lb_t *lb, int fd)
{
  int	i;

  if (bop->args[c][0] == LABEL_CHAR)
    i = my_be(my_check_lab(bop->args[c] + 1, lb, *cur));
  else
    i = my_be(my_atoi(bop->args[c]));
  if ((bop->type[c] == 1) && (++*cur2))
    {
      i /= 0x1000000;
      write(fd, &i, 1);
    }
  else if ((bop->type[c] == 2) && (*cur2 += DIR_SIZE))
    {
      write(fd, &i, DIR_SIZE);
    }
  else
    {
      *cur2 += IND_SIZE;
      write(fd, &i, IND_SIZE);
    }
}

void	my_wr(int fd, header_t head, bop_t *bop, lb_t *lb)
{
  char	c;
  int	cur;
  int	cur2;

  cur = 0;
  head.magic = my_be(COREWAR_EXEC_MAGIC);
  head.prog_size = my_be(head.prog_size);
  write(fd, &head, sizeof(head));
  while (bop && lb)
    {
      cur2 = 0;
      write(fd, &op_tab[bop->cmd].code, 1);
      ++cur2;
      if (bop->cmd != 0 && bop->cmd != 8 && bop->cmd != 11 && bop->cmd != 14)
	{
	  c = 0x40 * bop->type[0] + 0x10 * bop->type[1] + 0x04 * bop->type[2];
	  write(fd, &c, 1);
	  ++cur2;
	}
      c = -1;
      while (bop->type[(int)++c])
	my_wr_arg(bop, &cur, &cur2, (int)c, lb, fd);
      bop = bop->next;
      cur = cur + cur2;
    }
}

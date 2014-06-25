/*
** init_objs.c for init_objs in /home/balbo_a/rendu/MUL_2013_rtv1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Feb 27 13:41:26 2014 BALBO Alan
** Last update Sun Mar 16 20:56:41 2014 BALBO Alan
*/

#include "head.h"

void	fill_elem(char **tab, t_o *cur)
{
  cur->shape = my_getnbr(tab[0]);
  cur->l = my_getnbr(tab[1]);
  cur->posx = my_getnbr(tab[2]);
  cur->posy = my_getnbr(tab[3]);
  cur->posz = my_getnbr(tab[4]);
  cur->color = my_getnbr(tab[5]);
  cur->next = NULL;
}

int     parse_conf(int fd, t_o *cur)
{
  int	i;
  int	ok;
  char	*s;
  char	**tab;

  i = 0;
  ok = 0;
  while ((s = get_next_line(fd)) != NULL)
    {
      tab = my_str_to_wordtab(s, ';');
      i = 0;
      while (tab[i] != NULL)
	i++;
      if (i == 6)
	{
	  if (ok)
	    {
	      cur->next = xmalloc(sizeof(*cur));
	      cur = cur->next;
	    }
	  ok = 1;
	  fill_elem(tab, cur);
	}
    }
}

int	get_objs(t_t *t, char *file)
{
  t_o	*cur;
  int	fd;

  cur = xmalloc(sizeof(*cur));
  t->head = cur;
  fd = open(file, O_RDONLY);
  get_next_line(fd);
  parse_conf(fd, cur);
}

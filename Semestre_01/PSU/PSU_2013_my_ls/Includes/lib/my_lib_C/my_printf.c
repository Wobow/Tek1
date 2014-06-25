/*
** my_printf.c for my_printf in /home/balbo_a/rendu/CPE/my_printf
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov  6 00:09:39 2013 Alan Balbo
** Last update Sat Nov 16 00:15:25 2013 Alan Balbo
*/

#include "head_printf.h"

void		*xmalloc(unsigned int);
char		*my_strdup(char*);
void		*build_tab()
{
  void		(**tab)();

  tab = xmalloc(sizeof(void*) * (NB_FLAGS + 1));
  tab[0] = &my_putnbr;
  tab[1] = &my_putnbr;
  tab[2] = &my_putunbr;
  tab[3] = &my_putoctal;
  tab[4] = &my_puthexa;
  tab[5] = &my_puthexa_up;
  tab[6] = (void*)&my_putchar;
  tab[7] = &my_putstr;
  tab[8] = &my_putbin;
  tab[9] = &my_putstr_nb;
  tab[10] = &my_put_ptr;
  tab[11] = &my_errno;
  tab[12] = (void*)&my_putchar;
  tab[13] = 0;
  return (tab);
}

void		op_on_flag(t_apin *t)
{
  int		k;

  if (t->pandore[t->i + 1])
    {
      k = 0;
      while (t->pandore[t->i + 1] != t->s[k] && t->s[k])
	k = k + 1;
      if (k < my_strlen(t->s))
	t->f[k](va_arg(t->ap, void*));
      else
	my_putchar(t->pandore[t->i + 1]);
      t->i = t->i + 1;
    }
  else
    my_putchar(t->pandore[t->i]);
}

int		is_in_tab(char c, char *tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      if (c == tab[i])
	return (1);
      i = i + 1;
    }
  if (c == '%' || c == '#')
    return (2);
  return (0);
}

void		get_flag(t_apin *t)
{
  int	form;
  int	indent;
  int	u;

  form = 0;
  indent = 0;
  u = t->i + 1;
  while (t->pandore[u] && is_in_tab(t->pandore[u], t->s) != 1)
    {
      if (t->pandore[u] == '#')
	form = 1;
      if (t->pandore[u] == '+' || t->pandore[u] == '-')
	indent = 44 - t->pandore[u];
      u = u + 1;
    }
  op_on_flag(t);
}

void		my_printf(char *pandore, ...)
{
  t_apin	*t;

  t = xmalloc(sizeof(*t));
  t->pandore = my_strdup(pandore);
  t->i = 0;
  t->f = build_tab();
  t->s = my_strdup("iduoxXcsbSpmC");
  va_start(t->ap, pandore);
  while (t->pandore[t->i])
    {
      if (t->pandore[t->i] == '%' && is_in_tab(t->pandore[t->i + 1], t->s))
	get_flag(t);
      else
	my_putchar(t->pandore[t->i]);
      t->i = t->i + 1;
    }
  va_end(t->ap);
  free(t->f);
}

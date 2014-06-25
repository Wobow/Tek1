/*
** termcap_utilities.c for termcaps in /home/balbo_a/rendu/Allum1/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Feb 16 12:12:24 2014 BALBO Alan
** Last update Sun Feb 16 12:12:36 2014 BALBO Alan
*/

#include "head.h"

void    xtcget(t_a *t)
{
  if (tcgetattr(0, &t->term) == -1)
    exit(my_putstr("Can't get attributes.\n"));
}

void    xtcset(t_a *t)
{
  if (tcsetattr(0, 0, &t->term) == -1)
    my_putstr("Can't set attributes");
  xtcget(t);
}

int	init_tc(t_a *t)
{
  xtcget(t);
  t->term.c_cc[VMIN] = 1;
  t->term.c_cc[VTIME] = 0;
  t->term.c_lflag &= ~ECHO;
  t->term.c_lflag &= ~ICANON;
  xtcset(t);
}

int	reinit_tc(t_a *t)
{
  xtcget(t);
  t->term.c_lflag |= ECHO;
  t->term.c_lflag |= ICANON;
  xtcset(t);
}

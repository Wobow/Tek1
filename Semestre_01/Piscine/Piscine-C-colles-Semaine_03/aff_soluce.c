/*
** aff_soluce.c for aff_soluce in /home/balbo_a/rendu/Piscine-C-colles-Semaine_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Sun Oct 27 00:57:12 2013 Alan Balbo
** Last update Sun Oct 27 10:15:31 2013 berenger leclere
*/

#include "header.h"

void    put_in_tab(char *tab, int i)
{
  if (i)
    {
      tab[0] = 'o';
      tab[1] = '\\';
      tab[2] = 'A';
      tab[3] = 'C';
      tab[4] = 'C';
    }
  else
    {
      tab[0] = 'o';
      tab[1] = '/';
      tab[2] = 'C';
      tab[3] = 'C';
      tab[4] = 'A';
    }
}

void    put_in_tab_bis(char *tab, int i)
{
  if (i)
    {
      tab[0] = 'o';
      tab[1] = '*';
      tab[2] = 'B';
      tab[3] = 'B';
      tab[4] = 'B';
    }
  else
    {
      tab[0] = 'o';
      tab[1] = '*';
      tab[2] = 'B';
      tab[3] = 'B';
      tab[4] = 'B';
    }
}

void    put_result(int i, t_infos *infos)
{
  my_putstr("[colle1-");
  my_putnbr(i + 1);
  my_putstr("] ");
  my_putnbr(infos->y);
  my_putchar(' ');
  my_putnbr(infos->x);
}

void    my_print_soluce(t_infos *infos,
                        char *str, char *lcolumn, char *lchar)
{
  int   i;
  int   already_soluce;
  int	tmp;

  i = 0;
  already_soluce = 0;
  tmp = my_strlen(str) - 2;
  while (i < 5)
    {
      if (str[infos->y - 1] == lcolumn[i] && str[tmp] == lchar[i])
        {
          if (already_soluce)
	    {
	      my_putstr(" || ");
	    }
	  put_result(i, infos);
          already_soluce = 1;
        }
      i = i + 1;
    }
  if (already_soluce == 0)
    {
      my_putstr("aucune");
    }
}

void	aff_error(int error)
{
  char	c;

  if (error == 1)
    {
      my_putstr("[colle1-1] [0] [0] || [colle1-2] [0] [0] || [colle1-3] [0]");
      my_putstr(" [0] || [colle1-4] [0] [0] || [colle1-5] [0] [0]");
    }
}

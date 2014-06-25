/*
** colle3.c for colle3 in /home/balbo_a/rendu
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Sat Oct 26 18:48:34 2013 Alan Balbo
** Last update Sun Oct 27 10:11:55 2013 berenger leclere
*/

#include "header.h"

void		clear_buff(char *buff)
{
  int		i;

  i = 0;
  while (buff[i] != '\0')
    {
      buff[i] = 0;
      i = i + 1;
    }
}

void		find_colle(char *str, t_infos *infos)
{
  char		*lcolumn;
  char		*lchar;

  lcolumn = malloc(5);
  lchar = malloc(5);
  if (infos->x == 1 || infos->y == 1)
    {
      put_in_tab_bis(lcolumn, 1);
      put_in_tab_bis(lchar, 0);
    }
  else
    {
      put_in_tab(lcolumn, 1);
      put_in_tab(lchar, 0);
    }
  my_print_soluce(infos, str, lcolumn, lchar);
}

char		*my_strcat_buffer(char *s1, char *s2)
{
  char		*tmp;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tmp = malloc(sizeof(*tmp) * (my_strlen(s1) + my_strlen(s2) + 2));
  while (s1[i])
    {
      tmp[i] = s1[i];
      i = i + 1;
    }
  while (s2[j])
    {
      tmp[i] = s2[j];
      j = j + 1;
      i = i + 1;
    }
  tmp[i] = 0;
  free(s1);
  return (tmp);
}

int		what_is_this_glue(char *str)
{
  int		i;
  t_infos	*infos;

  infos = malloc(sizeof(*infos));
  infos->x = 0;
  infos->y = 0;
  i = -1;
  while (str[infos->y] != '\n' || str[infos->y + 1])
    {
      my_putnbr(infos->y + 1);
      infos->y = infos->y + 1;
    }
  my_putchar('l');
  while (str[i])
    {
      if (str[i] == '\n')
	{
	  infos->x = infos->x + 1;
	}
      i = i + 1;
    }
  if (infos->x == 0 || infos->y == 0)
    {
      aff_error(1);
      return (0);
    }
  find_colle(str, infos);
}

int		main(int argc, char **argv)
{
  char		*buffer;
  int		len;
  char		*buffer2;
  int		i;

  i = 1;
  buffer = malloc(sizeof(char) * 4097);
  buffer2 = malloc(sizeof(char));
  buffer2[0] = 0;
  while (len = read(0, buffer, 4096) > 0)
    {
      if (len != 0)
	{
	  buffer2 = my_strcat_buffer(buffer2, buffer);
	}
      clear_buff(buffer);
    }
  free(buffer);
  what_is_this_glue(buffer2);
  my_putchar(10);
  free(buffer2);
  return (0);
}

/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Wed Mar 26 21:04:13 2014 BALBO Alan
*/

#include "my.h"

char	*my_tkword(char *pandore)
{
  char	*out;
  int	i;
  char	*c;

  i = 0;
  out = my_strdup("");
  while (pandore[i])
    {
      c = xmalloc(2);
      c[0] = pandore[i];
      c[1] = 0;
      if (pandore[i] == '%' && pandore[i + 1] == '%')
	{
	  out = my_strconcat(out, get_next_line(0));
	  i++;
	}
      else
	out = my_strconcat(out, c);
      i++;
      free(c);
    }
  return (out);
}

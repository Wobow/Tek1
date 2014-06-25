/*
** my_str_ops.c for my_str_ops.c in /home/balbo_a/rendu/libs/IncludesC/lib/my_lib_C
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Jan 20 17:03:06 2014 BALBO Alan
** Last update Sun Apr 13 10:41:41 2014 Alan BALBO
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (++i && str[i]);
  return (i);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*out;
  int	len;

  len = my_strlen(src);
  out = xmalloc(sizeof(char) * len);
  out[len] = 0;
  i = 0;
  while (i < len)
    {
      out[i] = src[i];
      i = i + 1;
    }
  return (out);
}

/*
** my_strdup.c for my_strdup in /home/balbo_a/rendu/Piscine-C-Jour_08/ex_01
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Oct  9 09:25:51 2013 Alan Balbo
** Last update Sun Mar 16 20:59:17 2014 BALBO Alan
*/

#include "my.h"

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

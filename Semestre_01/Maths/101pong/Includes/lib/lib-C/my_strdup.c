/*
** my_strdup.c for my_strdup in /home/balbo_a/rendu/Piscine-C-Jour_08/ex_01
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Oct  9 09:25:51 2013 Alan Balbo
** Last update Mon Nov  4 17:26:59 2013 Alan Balbo
*/

#include <stdlib.h>

char	*my_strdup(char *src)
{
  int	i;
  char	*out;
  int	len;

  len = my_strlen(src);
  if (!(out = malloc(len)))
    exit(1);
  out[len] = 0;
  i = 0;
  while (i < len)
    {
      out[i] = src[i];
      i = i + 1;
    }
  return (out);
}

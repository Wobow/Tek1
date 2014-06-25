/*
** my_int_ops.c for my_int_ops in /home/balbo_a/rendu/CPE-2013-BSQ
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Tue Dec  3 13:19:46 2013 BALBO Alan
** Last update Sun Mar 16 20:58:53 2014 BALBO Alan
*/

#include "my.h"

int	*my_intdup(int *src)
{
  int	i;
  int	*out;
  int	len;

  len = 0;
  while (src[len] != -1)
    len = len + 1;
  out = xmalloc(sizeof(int) * (len + 1));
  out[len] = -1;
  i = 0;
  while (i < len)
    {
      out[i] = src[i];
      i = i + 1;
    }
  return (out);
}

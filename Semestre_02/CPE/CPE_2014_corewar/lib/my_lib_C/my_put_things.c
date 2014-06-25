/*
** my_put_things.c for my_put_things in /home/balbo_a/rendu/libs/IncludesC/lib/my_lib_C
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Jan 20 17:00:22 2014 BALBO Alan
** Last update Sun Apr 13 10:33:32 2014 Alan BALBO
*/

#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

int	my_putchar2(int n)
{
  char	c;

  c = n;
  return (write(1, &c, 1));
}

int	my_putnbr(int n)
{
  if (n < 0)
    {
      n = - n;
      my_putchar('-');
    }
  if (n >= 10)
    my_putnbr(n / 10);
  my_putchar(n % 10 + 48);
  return (1);
}

int	my_putnbr_base(int n, char *base)
{
  if (n < 0)
    {
      n = -n;
      my_putchar('-');
    }
  if (n >= my_strlen(base))
    my_putnbr_base(n / my_strlen(base), base);
  my_putchar(base[n % my_strlen(base)]);
  return (1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}

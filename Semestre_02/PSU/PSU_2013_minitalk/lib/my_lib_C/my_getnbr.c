/*
** my_getnbr.c for my_getnbr in /home/balbo_a/rendu/Piscine-C-Jour_04
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct  3 13:47:57 2013 Alan Balbo
** Last update Fri Mar 21 14:08:34 2014 BALBO Alan
*/

#include "my.h"

int	my_power_rec(int nb, int p)
{
  if (p > 1)
    nb = nb * my_power_rec(nb, p - 1);
  else nb = 1;
}

int	power_n(int n)
{
  int	i;
  int	out;

  i = 1;
  out = 1;
  while (i < n)
    {
      out = out * 10;
      i = i + 1;
    }
  return (out);
}

int	my_getnbr(char *str)
{
  int	str_len;
  int	i;
  int	nbr;
  int	minus;

  str_len = my_strlen(str);
  i = -1;
  nbr = 0;
  minus = 1;
  while (i < str_len)
    {
      i = i + 1;
      if (str[i] > 47 && str[i] < 58)
	  nbr = nbr + ((str[i] - 48) * power_n(str_len - i));
      else if (str[i] != 45 && str[i] != 43)
	{
	  nbr = nbr / power_n(str_len - i + 1);
	  i = str_len;
	}
      else if (str[i] == 45)
	  minus = 0 - minus;
    }
  if ((nbr > 2147483647) || nbr < (-2147483648))
      nbr = 0;
  return (nbr * minus);
}

/*
** my_atoi.c for lib in /home/cesar_a/rendu/Piscine-C-lib/my
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Tue Nov  5 19:47:13 2013 Aymeric CESAR
** Last update Sun Apr 13 09:58:57 2014 Aymeric CESAR
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	my_err(char *nbr, int err)
{
  write(1, "\"", 1);
  write(1, nbr, my_strlen(nbr));
  write(1, "\" is a wrong number ", 20);
  if (err == 0)
    write(1, "(no number given)\n", 18);
  else if (err == 1)
    write(1, "(incorrect character)\n", 22);
  else
    write(1, "(overflow)\n", 11);
  exit(0);
}

void	my_check_ovf(char *nbr, int nb)
{
  int	i;
  int	neg;
  int	ng;

  i = my_strlen(nbr) - 1;
  neg = 0;
  if (nb < 0)
    {
      nbr++;
      i--;
      nb = 0 - (nb + 1);
      neg = 1;
    }
  ng = neg;
  while (nb > 0)
    if (nbr[i] == (nb % 10 + neg) % 10 + 48)
      {
	neg = 0;
	nb = nb / 10;
	i--;
      }
    else
      my_err(nbr - neg, 2);
  if (ng && *(nbr - ng) != '-')
    my_err(nbr - 1, 2);
}

int	my_atoi(char *nbr)
{
  int	i;
  int	i2;
  int	nb;

  i = 0;
  i2 = 1;
  nb = 0;
  if (nbr[0] == '-')
    {
      i++;
      i2 = -1;
    }
  if (nbr[i] == 0)
    my_err(nbr, 0);
  while (nbr[i])
    if (nbr[i] < 48 || nbr[i] > 58)
      my_err(nbr, 1);
    else
      nb = nb * 10 + (nbr[i++] - '0');
  /* my_check_ovf(nbr, nb * i2); */
  return (nb * i2);
}

/*
** my_put_nbr.c for Piscine-C-Jour_03 in /home/cesar_a/rendu/Piscine-C-Jour_03
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Wed Oct  2 20:22:34 2013 Aymeric CESAR
** Last update Thu Jan 23 19:31:23 2014 Aymeric CESAR
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	i;
  int	min;

  min = 0;
  i = 1;
  if (nb < 0)
    {
      my_putchar('-');
      i = i + 1;
      if (nb == -2147483648)
      	{
      	  nb = nb + 1;
      	  min = 1;
      	}
      nb = -nb;
    }
  if (nb >= 0)
    {
      if (nb > 9)
	i = i + my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48 + min);
    }
  return (i);
}

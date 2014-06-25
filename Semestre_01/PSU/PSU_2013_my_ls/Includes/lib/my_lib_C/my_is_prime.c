/*
** my_is_prime.c for my_is_prime in /home/balbo_a/rendu/Piscine-C-Jour_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:09:39 2013 Alan Balbo
** Last update Tue Oct  8 10:28:12 2013 Alan Balbo
*/

int	my_is_prime(int nb)
{
  int	out;
  int	i;

  out = 0;
  i = 2;
  if (nb > 1)
    {
      while (nb % i != 0 && i <= nb)
	{
	  i = i + 1;
	  if (i == nb)
	    {
	      out = 1;
	    }
	}
    }
  return (out);
}

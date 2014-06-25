/*
** my_square_root.c for my_square_root in /home/balbo_a/rendu/Piscine-C-Jour_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Tue Oct  8 09:38:48 2013 Alan Balbo
** Last update Tue Oct  8 10:08:21 2013 Alan Balbo
*/

int	my_square_root(int nb)
{
  int	out;
  int	i;

  out = 0;
  i = 1;
  while  (nb / i >= i)
    {
      if (nb / i == i && nb % i == 0)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (0);
}

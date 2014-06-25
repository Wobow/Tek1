/*
** my_power_it.c for my_power_it in /home/balbo_a/rendu/Piscine-C-Jour_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Fri Oct  4 14:20:31 2013 Alan Balbo
** Last update Tue Oct  8 09:54:12 2013 Alan Balbo
*/

int	my_power_it(int nb, int p)
{
  int	i;
  int	out;

  i = 1;
  out = 1;
  while (i <= p)
    {
      out = out * nb;
      i = i + 1;
    }
  return (out);
}

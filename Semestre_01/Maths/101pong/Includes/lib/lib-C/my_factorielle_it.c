/*
** my_factorielle_it.c for my_factorielle_it in /home/balbo_a/rendu/Piscine-C-Jour_05
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Oct  4 08:58:06 2013 Alan Balbo
** Last update Fri Nov  8 16:18:12 2013 Alan Balbo
*/

int	my_factorielle_it(int nb)
{
  int	i;
  int	out;

  i = 1;
  out = 1;
  if (nb > 19 || nb < 0)
    {
      out = 0;
    }
  while (i <= nb)
    {
      out = out * i;
      i = i + 1;
    }
  return (out);
}

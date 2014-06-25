/*
** my_find_prime_sup.c for my_find_prime_sup in /home/balbo_a/rendu/Piscine-C-Jour_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Tue Oct  8 10:15:31 2013 Alan Balbo
** Last update Tue Oct  8 10:20:46 2013 Alan Balbo
*/

int	my_find_prime_sup(int nb)
{
  int	i;

  i = 0;
  while (!my_is_prime(nb + i))
    {
      i = i + 1;
    }
  return (nb + i);
}

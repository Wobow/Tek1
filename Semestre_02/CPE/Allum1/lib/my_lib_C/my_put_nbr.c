/*
** my_put_nbr.c for my_put_nbr in /home/balbo_a/rendu/Piscine-C-Jour_03
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Oct  2 20:24:28 2013 Alan Balbo
** Last update Thu Jan  9 16:00:32 2014 BALBO Alan
*/

void	my_putnbr(int n)
{
  if (n < 0)
    {
      n = - n;
      my_putchar('-');
    }
  if (n >= 10)
    my_putnbr(n / 10);
  my_putchar(n % 10 + 48);
}

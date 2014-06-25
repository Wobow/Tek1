/*
** my_putnbr_base.c for my_putnbr_base in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_15
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Oct  7 18:53:06 2013 Alan Balbo
** Last update Thu Jan  9 15:45:05 2014 BALBO Alan
*/

void	aff_base(int n, int i, char *base)
{
  int	rest;

  rest = 0;
  if (n > 0)
    {
      rest =  n % i;
      n = n / i;
      aff_base(n, i, base);
      my_putchar(base[rest]);
    }
  else if (n < 0)
    {
      my_putchar('-');
      n = 0 - n;
      aff_base(n, i, base);
    }
}

int	my_putnbr_base(int nbr, char *base)
{
  int	i;
  int	n;
  int	rest;

  i = 0;
  n = 0;
  rest = 0;
  while (base[i])
    i = i + 1;
  aff_base(nbr, i, base);
}

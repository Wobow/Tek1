/*
** my_aff_combn.c for my_aff_combn in /home/balbo_a/rendu/Piscine-C-Jour_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Wed Oct  2 21:23:27 2013 Alan Balbo
** Last update Thu Oct  3 21:43:24 2013 Alan Balbo
*/

int	my_aff_combn(int n)
{
  int	i;

  i = 5 - n;
  if (n != 0)
    {
      while ( i <= 10 - n)
	{
	  my_putchar(i + 48);
	  my_aff_combn(n - 1);
	  i = i + 1;
	  if (10 - n == 9)
	    {
	      my_putchar(44);
	      my_putchar(32);
	    }
	}
    }
}

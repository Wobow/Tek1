/*
** my_aff_comb2.c for my_aff_comb2 in /home/balbo_a/rendu/Piscine-C-Jour_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Wed Oct  2 12:00:58 2013 Alan Balbo
** Last update Tue Oct  8 11:08:25 2013 Alan Balbo
*/

int	my_split_nb(int n1, int n2)
{
  int   part2;
  int	part1;
  int	part3;
  int	part4;

  part2 = n1 % 10;
  part1 = (n1 - part2) / 10;
  part4 = n2 % 10;
  part3 = (n2 - part4) / 10;
  my_putchar(part1 + 48);
  my_putchar(part2 + 48);
  my_putchar(32);
  my_putchar(part3 + 48);
  my_putchar(part4 + 48);
  if (n1 != 98)
    {
      my_putchar(44);
      my_putchar(32);
    }
}

int	my_aff_comb2()
{
  int	nb1;
  int	nb2;

  nb1 = 0;
  nb2 = 1;
  while (nb1 <= 98)
    {
      nb2 = nb1 + 1;
      while (nb2 <= 99)
	{
	  my_split_nb(nb1, nb2);
	  nb2 = nb2 + 1;
	}
      nb1 = nb1 + 1;
    }
}

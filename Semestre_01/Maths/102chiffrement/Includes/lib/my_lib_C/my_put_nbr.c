/*
** my_put_nbr.c for my_put_nbr in /home/balbo_a/rendu/Piscine-C-Jour_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Wed Oct  2 20:24:28 2013 Alan Balbo
** Last update Wed Oct  9 20:49:36 2013 Alan Balbo
*/

int	my_aff_nbr(int nbr)
{
  char	part_unit;

  if (nbr < 0)
    {
      my_putchar('-');
      nbr = 0 - nbr;
    }
  if (nbr != 0)
    {
      part_unit = nbr % 10;
      nbr = (nbr - (nbr % 10)) / 10;
      my_aff_nbr(nbr);
      my_putchar(part_unit + 48);
    }
}

int	my_putnbr(int nbr)
{
  if (nbr == 0)
    {
      my_putchar(48);
    }
  else if (nbr == -2147483648)
    {
      my_aff_nbr((nbr + 8) / 10);
      my_putchar(56);
    }
  else
    {
      my_aff_nbr(nbr);
    }
}

/*
** my_promptf.c for my_promptf in /home/balbo_a/rendu/CPE/my_printf
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov  6 11:03:17 2013 Alan Balbo
** Last update Sun Mar 16 21:00:10 2014 BALBO Alan
*/

void	my_putstr_nb(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 32 || str[i] == 127)
	my_putoctal_form(str[i], 0);
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}

void	my_putunbr(unsigned int nbr)
{
  if (nbr >= 10)
    my_putunbr(nbr / 10);
  my_putchar(nbr % 10 + 48);
}

void	my_putoctal(unsigned int nbr)
{
  if (nbr < 0)
    {
      nbr = - nbr;
      my_putchar(45);
    }
  if (nbr >= 8)
    my_putoctal(nbr / 8);
  my_putchar(nbr % 8 + 48);
}

void	my_puthexa_up(unsigned int nbr)
{
  if (nbr < 0)
    {
      nbr = - nbr;
      my_putchar(45);
    }
  if (nbr >= 16)
      my_puthexa_up(nbr / 16);
  if (nbr % 16 >= 10)
    my_putchar(nbr % 16 + 55);
  else
    my_putchar(nbr % 16 + 48);
}

void	my_puthexa(unsigned int nbr)
{
  if (nbr < 0)
    {
      nbr = - nbr;
      my_putchar(45);
    }
  if (nbr >= 16)
    my_puthexa(nbr / 16);
  if (nbr % 16 >= 10)
    my_putchar(nbr % 16 + 87);
  else
    my_putchar(nbr % 16 + 48);
}

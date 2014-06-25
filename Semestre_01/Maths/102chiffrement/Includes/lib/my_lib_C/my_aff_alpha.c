/*
** my_aff_alpha.c for my_aff_alpha in /home/balbo_a/rendu/Piscine-C-Jour_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Wed Oct  2 09:28:52 2013 Alan Balbo
** Last update Wed Oct  9 20:41:52 2013 Alan Balbo
*/

int	my_aff_alpha()
{
  int	i;

  i = 97;
  while (i <= 122)
    {
      my_putchar(i);
      i = i + 1;
    }
}

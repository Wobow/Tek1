/*
** my_aff_revalpha.c for my_aff_revalpha in /home/balbo_a/rendu/Piscine-C-Jour_03
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Oct  2 09:42:14 2013 Alan Balbo
** Last update Fri Nov  8 16:17:45 2013 Alan Balbo
*/

int	my_aff_revalpha()
{
  int	i;

  i = 122;
  while (i > 96)
    {
      my_putchar(i);
      i = i - 1;
    }
}

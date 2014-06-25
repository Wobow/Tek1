/*
** my_aff_chiffre.c for my_aff_chiffre in /home/balbo_a/rendu/Piscine-C-Jour_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Wed Oct  2 10:09:00 2013 Alan Balbo
** Last update Thu Oct  3 21:25:08 2013 Alan Balbo
*/

int	my_aff_chiffre()
{
  int	i;

  i = 48;
  while (i <= 57)
    {
      my_putchar(i);
      i = i + 1;
    }
}

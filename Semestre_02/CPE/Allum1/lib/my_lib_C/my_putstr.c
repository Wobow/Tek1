/*
** my_putstr.c for my_putstr in /home/balbo_a/rendu/Piscine-C-Jour_04
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct  3 11:01:09 2013 Alan Balbo
** Last update Thu Jan  9 15:44:27 2014 BALBO Alan
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

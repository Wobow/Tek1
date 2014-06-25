/*
** my_putchar.c for my_putchar in /home/balbo_a/rendu/Piscine-C-lib/my
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Oct  9 20:37:22 2013 Alan Balbo
** Last update Thu Jan  9 15:46:37 2014 BALBO Alan
*/

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}

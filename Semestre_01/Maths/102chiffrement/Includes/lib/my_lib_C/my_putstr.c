/*
** my_putstr.c for my_putstr in /home/balbo_a/rendu/Piscine-C-Jour_04
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct  3 11:01:09 2013 Alan Balbo
** Last update Fri Nov  8 16:19:52 2013 Alan Balbo
*/

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

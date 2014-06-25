/*
** my_strlen.c for my_strlen in /home/balbo_a/rendu/Piscine-C-Jour_04
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Thu Oct  3 11:16:55 2013 Alan Balbo
** Last update Thu Oct  3 17:21:48 2013 Alan Balbo
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

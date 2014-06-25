/*
** my_revstr.c for my_revstr in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_03
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Oct  7 10:04:19 2013 Alan Balbo
** Last update Fri Nov  8 16:20:07 2013 Alan Balbo
*/

char	*my_revstr(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[j] != '\0')
    {
      j = j + 1;
    }
  while (i < j)
    {
      str[i] = str[i] + str[j];
      str[j] = str[i] - str[j];
      str[i] = str[i] - str[j];
      i = i + 1;
      j = j - 1;
    }
  return (str);
}

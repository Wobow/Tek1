/*
** my_strcmp.c for str_cmp in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_05
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Oct  7 11:40:56 2013 Alan Balbo
** Last update Thu Jan  9 15:44:16 2014 BALBO Alan
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 && s2)
    {
      while (s1[i] == s2[i] && s1[i])
	i++;
      return (s1[i] - s2[i]);
    }
  return (-1);
}

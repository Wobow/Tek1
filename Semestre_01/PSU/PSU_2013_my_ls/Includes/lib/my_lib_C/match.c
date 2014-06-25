/*
** match.c for match in /home/balbo_a/rendu/Piscine-C-lib/my
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct 21 12:16:43 2013 Alan Balbo
** Last update Mon Oct 21 12:19:02 2013 Alan Balbo
*/

int	match(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s1[i] == s2[i])
    {
      i = i + 1;
    }
  if (i == my_strlen(s1) && i == my_strlen(s2))
    {
      return (1);
    }
  return (0);
}

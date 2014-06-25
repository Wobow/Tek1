/*
** my_strcmp.c for str_cmp in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 11:40:56 2013 Alan Balbo
** Last update Mon Oct  7 13:44:11 2013 Alan Balbo
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 != 0 && s2 != 0)
    {
      while (s1[i] == s2[i] && s1[i] != '\0')
	{
	  i = i + 1;
	}
      return (s1[i] - s2[i]);
    }
}


/*
** my_strncmp.c for my_strncmp in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_06
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 11:59:56 2013 Alan Balbo
** Last update Mon Oct  7 13:57:54 2013 Alan Balbo
*/

int     my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  if (s1 != 0 && s2 != 0)
    {
      i = 0;
      while (s1[i] == s2[i] && s1[i] != '\0' && i <= n - 2)
	{
	  i = i + 1;
	}
      return (s1[i] - s2[i]);
    }
}

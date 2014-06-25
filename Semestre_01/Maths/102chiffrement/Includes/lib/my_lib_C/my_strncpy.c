/*
** my_putnstr.c for my_putnstr in /home/balbo_a/rendu/Piscine-C-Jour_06
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 09:39:01 2013 Alan Balbo
** Last update Thu Oct 10 20:14:54 2013 Alan Balbo
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (i <= n && src[i] != '\0')
    {
      if (i == n)
	{
	  dest[i] = '\0';
	}
      else
	{
	  dest[i] = src[i];
	}
      i = i + 1;
    }
  return (dest);
}

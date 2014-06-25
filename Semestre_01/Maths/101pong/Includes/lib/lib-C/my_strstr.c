/*
** my_strstr.c for my_strstr in /home/balbo_a/rendu/Piscine-C-Jour_06
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Oct  7 10:15:03 2013 Alan Balbo
** Last update Fri Nov  8 16:22:24 2013 Alan Balbo
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	to_find_len;

  i = 0;
  j = 0;
  to_find_len = 0;
  while (to_find[to_find_len] != '\0')
    {
      to_find_len = to_find_len + 1;
    }
  while (str[i] != '\0' && to_find_len != 1)
    {
      j = 0;
      while (to_find[j] == str[i + j])
	{
	  j = j + 1;
	}
      if (j >= to_find_len)
	{
	  return (&str[i]);
	}
      i = i + 1;
    }
  return (0);
}

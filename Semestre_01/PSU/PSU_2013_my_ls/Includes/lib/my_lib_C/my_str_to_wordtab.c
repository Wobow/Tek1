/*
** my_str_to_wordab.c for my_str_to_wordtab in /home/balbo_a/rendu/Piscine-C-Jour_08/ex_04
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct 10 11:13:23 2013 Alan Balbo
** Last update Fri Nov  8 16:22:44 2013 Alan Balbo
*/

#include <stdlib.h>

char	*my_strdup(char *str);

int	is_separator(char c)
{
  if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a'))
    {
      return (1);
    }
  else if (c > 'z')
    {
      return (1);
    }
  return (0);
}

int	count_words(char *str)
{
  int	i;
  int	total;

  i = 0;
  total = 0;
  while (str[i] != '\0')
    {
      if (is_separator(str[i]))
	{
	  total = total + 1;
	}
      i = i + 1;
    }
  return (total + 1);
}

void	put_str_in_case(char **wordtab, char *str, int u, int i)
{
  int	j;
  int	k;

  j = i + 1;
  while (!is_separator(str[j]))
    {
      j = j + 1;
    }
  wordtab[u] = malloc(j - 1);
  k = 0;
  while (k != j - i)
    {
      if (i != 0)
	wordtab[u][k] = str[i + k + 1];
      else
	wordtab[u][k] = str[i + k];
      k = k + 1;
    }
}

char	**my_str_to_wordtab(char *str)
{
  char	**wordtab;
  int	i;
  int	u;

  i = 0;
  u = 0;
  wordtab = malloc(count_words(str) * sizeof(str));
  while (str[i] != '\0')
    {
      if (is_separator(str[i]) || i == 0)
	{
	  put_str_in_case(wordtab, str, u, i);
	  u = u + 1;
	}
      i = i + 1;
    }
  wordtab[u] = '\0';
  return (wordtab);
}

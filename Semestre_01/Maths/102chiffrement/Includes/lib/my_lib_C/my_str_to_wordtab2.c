/*
** my_str_to_wordtab2.c for my_str_to_wordtab.c in /home/balbo_a/rendu/102chiffrement-2018-balbo_a
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Nov 18 19:47:51 2013 Alan Balbo
** Last update Mon Nov 18 20:01:07 2013 Alan Balbo
*/

#include <stdlib.h>
#include <string.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	count_words(char *str)
{
  int	i;
  int	j;


  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[i] == 32)
	j = j + 1;
      i = i + 1;
    }
  return (j);
}

int	my_strlen_perso(char *str, int i)
{
  int	j;

  j = 0;
  while (str[i + j] != 32)
    j = j + 1;
  return (j);
}

char	**my_str_to_wordab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  tab = malloc(sizeof(char*) * (count_words(str) + 1));
  tab[count_words(str)] = 0;
  i = 0;
  j = 0;
  k = 0;
  while (str[i])
    {
      if (str[i] == 32)
	j = j + 1;
      while (str[i] == 32)
	{
	  i = i + 1;
	  k = 0;
	}
      tab[j] = malloc(sizeof(char) * my_strlen_perso(str, i));
      my_putnbr(my_strlen_perso(str, i));
      tab[j][k] = str[i];
      i = i + 1;
      k = k + 1;
    }
}

int	main()
{
  char	*str;
  char	**lol;
  int	i;

  str = strdup("Bonjour connnard caca prout");
  lol = my_str_to_wordab(str);
  while (lol[i])
    {
      my_putstr(lol[i]);
      i = i + 1;
    }
}

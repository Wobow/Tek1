/*
** my_str_to_wordtab.c for lib in /home/cesar_a/rendu/lib/my
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Thu Jan 23 21:40:28 2014 Aymeric CESAR
** Last update Wed Apr  9 14:56:59 2014 Aymeric CESAR
*/

#include "my.h"

void	my_end_woords(char **wordtab)
{
  int	i;

  i = -1;
  while (*wordtab)
    {
      while ((*wordtab)[++i] && (*wordtab)[i] != ',');
      (*wordtab)[i] = 0;
      i = -1;
      wordtab++;
    }
}

char	**my_arg_to_wordtab(char *str)
{
  char	**wordtab;
  int	nb_wo;
  int	i;

  if (str)
    {
      nb_wo = 2;
      i = 0;
      while (str[++i])
	if (str[i] != ',' && str[i - 1] == ',')
	  nb_wo++;
      wordtab = my_malloc(nb_wo * sizeof(*wordtab));
      i = 0;
      nb_wo = 0;
      if (*str != ',')
	wordtab[nb_wo++] = str;
      while (str[++i])
	if (str[i] != ',' && str[i - 1] == ',')
	  wordtab[nb_wo++] = str + i;
      wordtab[nb_wo] = 0;
      my_end_woords(wordtab);
    }
  return (wordtab);
}

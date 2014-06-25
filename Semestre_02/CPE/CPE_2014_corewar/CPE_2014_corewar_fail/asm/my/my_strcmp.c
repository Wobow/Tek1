/*
** my_strcmp.c for Piscine-C-Jour_06 in /home/cesar_a/rendu/Piscine-C-Jour_06/ex_05
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Mon Oct  7 12:02:24 2013 Aymeric CESAR
** Last update Mon Mar 31 10:37:25 2014 Aymeric CESAR
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

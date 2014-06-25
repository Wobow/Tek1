/*
** my_strncmp.c for Piscine-C-Jour_06 in /home/cesar_a/rendu/Piscine-C-Jour_06/ex_06
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Mon Oct  7 14:22:35 2013 Aymeric CESAR
** Last update Fri Jan 24 18:45:13 2014 Aymeric CESAR
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (i < n))
    i++;
  return (s1[i] - s2[i]);
}

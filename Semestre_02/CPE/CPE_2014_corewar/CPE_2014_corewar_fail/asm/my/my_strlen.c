/*
** my_strlen.c for Piscine-C-Jour_04 in /home/cesar_a/rendu/Piscine-C-Jour_04
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Thu Oct  3 09:35:27 2013 Aymeric CESAR
** Last update Thu Jan 23 20:13:03 2014 Aymeric CESAR
*/

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

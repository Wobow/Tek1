/*
** my_strlcat.c for my_strlcat in /home/balbo_a/rendu/Piscine-C-Jour_07/ex_03
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Tue Oct  8 12:24:12 2013 Alan Balbo
** Last update Fri Nov  8 16:21:44 2013 Alan Balbo
*/

int	my_strlcat(char *dest, char *src, int size)
{
  int	i;

  i = 0;
  my_strcat(dest, src);
  while (dest[i] != '\0' && i < size)
    {
      i = i + 1;
    }
  return (i + 1);
}

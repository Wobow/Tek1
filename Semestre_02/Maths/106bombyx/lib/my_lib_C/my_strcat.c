/*
** my_strcat.c for my_strcat in /home/balbo_a/rendu/Piscine-C-Jour_07/ex_01
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Tue Oct  8 11:19:49 2013 Alan Balbo
** Last update Tue Oct  8 11:34:10 2013 Alan Balbo
*/

char	*my_strcat(char *dest, char *src)
{
  int	len_dest;
  int	len_src;
  int	i;

  i = 0;
  len_dest = my_strlen(dest);
  len_src = my_strlen(src);
  while (src[i] != '\0')
    {
      dest[len_dest + i] = src[i];
      i = i + 1;
    }
  return (dest);
}

/*
** my_strncat.c for my_strncat in /home/balbo_a/rendu/Piscine-C-Jour_07/ex_02
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Tue Oct  8 11:43:15 2013 Alan Balbo
** Last update Tue Oct  8 11:44:54 2013 Alan Balbo
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int   len_dest;
  int   len_src;
  int   i;

  i = 0;
  len_dest = my_strlen(dest);
  len_src = my_strlen(src);
  while (src[i] != '\0' && i < nb)
    {
      dest[len_dest + i] = src[i];
      i = i + 1;
    }
  return (dest);
}

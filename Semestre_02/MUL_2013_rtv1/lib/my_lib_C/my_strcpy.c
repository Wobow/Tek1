/*
** my_strcpy.c for my_strcpy in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_01
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 09:13:39 2013 Alan Balbo
** Last update Mon Oct  7 09:35:21 2013 Alan Balbo
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

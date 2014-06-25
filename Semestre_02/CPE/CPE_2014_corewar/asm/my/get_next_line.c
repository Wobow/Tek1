/*
** get_next_line.c for get_next_line in /home/cesar_a/rendu/get_next_line-2018-cesar_a
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Mon Nov 18 17:57:27 2013 Aymeric CESAR
** Last update Fri Jan 24 18:41:30 2014 Aymeric CESAR
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*my_linecpy(char *dest, char *src)
{
  char	*temp;

  temp = dest;
  while (*src && *src != 10)
    *(dest++) = *(src++);
  *dest = 0;
  return (temp);
}

char	*my_strinit(char *str, const int fd)
{
  char		buffer[BUFF_SIZE + 1];
  int		len;

  if (!(str = malloc(sizeof(*str))))
    {
      write(1, "Could not alloc", 15);
      exit(0);
    }
  *str = 0;
  while ((len = read(fd, buffer, BUFF_SIZE)) > 0)
    {
      buffer[len] = 0;
      str = my_strcocat(str, buffer);
    }
  if (len == -1)
    return (NULL);
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	*str;
  static int	i = 0;
  int		beg;
  char		*line;

  beg = i;
  if (i == 0)
      str = my_strinit(str, fd);
  if (str == 0)
    return (NULL);
  if (str[i] == 0)
    {
      free(str);
      return (NULL);
    }
  while (str[i] && str[i] != 10)
    i = i + 1;
  if (!(line = malloc((i - beg + 1) * sizeof(*line))))
    {
      write(1, "Could not alloc", 15);
      exit(0);
    }
  if (str[i])
      i = i + 1;
  return (my_linecpy(line, str + beg));
}

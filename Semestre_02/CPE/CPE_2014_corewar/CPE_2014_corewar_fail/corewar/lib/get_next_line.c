/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Fri Mar 28 21:09:54 2014 BALBO Alan
*/

#include "my.h"

void		clear_buffer(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i])
    {
      buffer[i] = 0;
      i++;
    }
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF_SIZE];
  static int	i = 0;
  int		k;
  char		*out;
  int		size_read;

  out = xmalloc(sizeof(char) * BUFF_SIZE);
  if (buffer == NULL || buffer[i] == 0)
    {
      i = 0;
      clear_buffer(buffer);
      if ((size_read = read(fd, buffer, BUFF_SIZE)) <= 0)
	return (NULL);
    }
  k = 0;
  while (buffer[i] && buffer[i] != '\n')
    {
      out[k] = buffer[i];
      k++;
      i++;
    }
  if (buffer[i] == '\n')
    i++;
  out[k] = 0;
  return (out);
}

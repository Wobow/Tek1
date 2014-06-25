/*
** get_next_line.c for get_next_line in /home/balbo_a/rendu/get_next_line-2018-balbo_a
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Nov 18 13:48:41 2013 Alan Balbo
** Last update Sat Nov 23 19:34:36 2013 Alan Balbo
*/

#include "get_next_line.h"

int		my_strlen2(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

char		*my_concat(char *s1, char s2)
{
  int		j;
  int		i;
  int		l1;
  int		lt;
  char		*out;

  j = 0;
  l1 = my_strlen2(s1);
  lt = l1 + 1;
  if (!(out = malloc(sizeof(char) * (1 + lt))))
    return (NULL);
  out[lt] = 0;
  i = 0;
  while (s1[i])
    {
      out[i] = s1[i];
      i = i + 1;
    }
  out[i] = s2;
  free(s1);
  return (out);
}

int		clean_buffer(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i])
    {
      buffer[i] = 0;
      i = i + 1;
    }
  return (1);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF_SIZE];
  static int	pos = 0;
  char		*content;

  if (!(content = malloc(sizeof(char) * 1)))
    return (NULL);
  content[0] = 0;
  while (buffer[pos] != '\n')
    {
      if (pos < BUFF_SIZE)
	content = my_concat(content, buffer[pos]);
      else
	{
	  pos = -1;
	  if (clean_buffer(buffer) && !(read(fd, buffer, BUFF_SIZE)))
	    {
	      if (my_strlen2(content))
		return (content);
	      return (NULL);
	    }
	}
      pos = pos + 1;
    }
  pos = pos + 1;
  return (content);
}

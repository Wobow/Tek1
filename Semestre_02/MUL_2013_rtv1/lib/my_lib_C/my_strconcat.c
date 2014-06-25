/*
** my_stroncat.c for my_strocat in /home/balbo_a
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Dec  5 15:07:25 2013 BALBO Alan
** Last update Sun Mar 16 20:59:12 2014 BALBO Alan
*/

#include "my.h"

int	my_super_strlen(char **s)
{
  int	i;

  i = 0;
  while (s[i])
    i++;
  return (i);
}

char	**my_super_strconcat(char **str1, char *str2)
{
  char	**temp;
  int	i;
  int	j;

  i = 0;
  temp = xmalloc(sizeof(char*) * (my_super_strlen(str1) + 2));
  while (str1[i])
    {
      temp[i] = my_strdup(str1[i]);
      i = i + 1;
    }
  temp[i] = my_strdup(str2);
  temp[i + 1] = 0;
  free(str2);
  free(str1);
  return (temp);
}

char	*my_strconcat(char *str1, char *str2)
{
  char	*temp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  temp = xmalloc((my_strlen(str1) + my_strlen(str2) + 2) * sizeof(*temp));
  while (str1[i])
    {
      temp[i] = str1[i];
      i = i + 1;
    }
  while (str2[j])
    {
      temp[i] = str2[j];
      j = j + 1;
      i = i + 1;
    }
  temp[i] = 0;
  free(str1);
  return (temp);
}

char	*get_file(char *input, int new_line)
{
  int	fd;
  char	*line;
  char	*file;

  fd = 0;
  file = xmalloc(1);
  file[0] = 0;
  if (input != "0")
    {
      if (!(fd = open(input, O_RDONLY)))
	exit(write(1, "open error !\n", my_strlen("open error !\n")));
    }
  while ((line = get_next_line(fd)))
    {
      file = my_strconcat(file, line);
      if (new_line)
	file = my_strconcat(file, "\n");
    }
  return (file);
}

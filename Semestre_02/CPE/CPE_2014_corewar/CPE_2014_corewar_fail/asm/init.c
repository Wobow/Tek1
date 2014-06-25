/*
** main.c for Corewar in /home/cesar_a/rendu/Coreware/ASM
**
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
**
** Started on  Tue Mar 18 10:25:47 2014 Aymeric CESAR
** Last update Sun Apr 13 14:01:18 2014 Alan BALBO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "my/my.h"

int	open_init(char *s, int l, header_t *head, int *src)
{
  char	**s2;

  s[my_strlen(s) - 1] = 0;
  if (my_strlen(s) <= PROG_NAME_LENGTH)
    my_strcpy(head->prog_name, s);
  else
    write(2, "Name too long\n", 17);
  l = my_strlen(COMMENT_CMD_STRING);
  while ((s2 = my_str_to_wordtab(get_next_line(*src))) && (*s2 == 0 || **s2 == COMMENT_CHAR));
  if (*s2 && my_strncmp(*s2, COMMENT_CMD_STRING, l - 1) == 0
      && s2[1][0] == '"')
    {
      ++(s2[1]);
      s2[1][my_strlen(s2[1]) - 1] = 0;
      if (my_strlen(s2[1]) <= COMMENT_LENGTH)
	my_strcpy(head->comment, s2[1]);
      else
	write(2, "Comment too long\n", 17);
    }
  else
    my_putchar(s2[1][my_strlen(s2[1]) - 1]);
  return (open(my_strcocat(s, ".cor"), O_WRONLY | O_CREAT, 0x1a4));
}

int	init(int *src, char *name, header_t *head)
{
  char	**s;
  int	l;

  if ((*src = open(name, O_RDONLY)) == -1)
    {
      my_printf("File %s not accessible\n", name);
      return (-1);
    }
  l = -1;
  while (++l < PROG_NAME_LENGTH)
    head->prog_name[l] = 0;
  l = -1;
  while (++l < COMMENT_LENGTH)
    head->comment[l] = 0;
  l = my_strlen(NAME_CMD_STRING);
  while ((s = my_str_to_wordtab(get_next_line(*src))) && (**s == 0 || **s == COMMENT_CHAR));
  if (*s && my_strncmp(*s, NAME_CMD_STRING, l - 1) == 0
      && s[1][0] == '"' && s[1][my_strlen(s[1]) - 1] == '"')
    return (open_init(s[1] + 1, l, head, src));
  write(2, "Syntax error: no name found\n", 28);
  return (-1);
}

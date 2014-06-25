/*
** main.c for Corewar in /home/cesar_a/rendu/Coreware/ASM
**
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
**
** Started on  Tue Mar 18 10:25:47 2014 Aymeric CESAR
** Last update Sun Apr 13 14:00:55 2014 Alan BALBO
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "op.h"
#include "corewar.h"
#include "my/my.h"

int		main(int argc, char **argv)
{
  int		src;
  int		core;
  int		i;
  char		*s;
  header_t	head;
  bop_t		*bop;
  lb_t		*label;

  if (argc == 2)
    {
      bop = 0;
      label = 0;
      i = 0;
      if ((core = init(&src, argv[1], &head)) == -1)
	return (1);
      while ((s = get_next_line(src)))
	if (*s)
	  my_get_cmd(my_str_to_wordtab(s), &i, &bop, &label);
      head.prog_size = i;
      my_wr(core, head, bop, label);
    }
  else
    write(1, "Wrong number of argument.\n", 26);
  return (0);
}

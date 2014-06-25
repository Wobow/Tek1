/*
** init.c for init in /home/balbo_a/rendu/CPE_2014_corewar/corewar/srcs
**
** Made by Alan BALBO
** Login   <balbo_a@epitech.net>
**
** Started on  Sun Apr 13 11:02:29 2014 Alan BALBO
** Last update Sun Apr 13 11:09:01 2014 Alan BALBO
*/

#include "vm.h"

void		fill_this_vm(t_info *s, char *champ, int pc, t_prog *p)
{
  int		fd;
  int		i;

  i = 0;
  if ((fd = open(champ, O_RDONLY)) == -1)
    exit(my_printf("File %s not accessible\n", champ));
  if (read(fd, &(p->head), sizeof(p->head)) == -1)
    exit(write(1, "Can't read this\n", 16));
  if (b_to_l(p->head.magic) != COREWAR_EXEC_MAGIC)
    exit(my_printf("%s is not a corewar executable", champ));
  while (read(fd, (s->vm + pc + i), 1) > 0)
    i = i + 1;
  close(fd);
}

void		def_proglist(int nbj, t_info *s, t_prog *p)
{
  int		i;
  t_prog	*cur;

  i = 1;
  cur = p;
  while (i != nbj)
    {
      s->prog_list[i - 1] = cur->head.prog_name;
      cur = cur->next;
      i = i + 1;
    }
}

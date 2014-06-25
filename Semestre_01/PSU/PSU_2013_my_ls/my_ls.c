/*
** my_ls.c for my_ls in /home/balbo_a/PSU_2013_my_ls
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov 20 15:00:01 2013 Alan Balbo
** Last update Wed Nov 20 15:32:12 2013 Alan Balbo
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int	stat(const char*, struct stat*);

int		main(int argc, char **argv)
{
  struct stat	sb;

  if (stat("lol", &sb) == -1)
    {
      my_putstr("Error : stat return an error value\n");
      return (1);
    }
  my_putstr("lol ok");
  my_putstr((int)*stat.st_ino);
}

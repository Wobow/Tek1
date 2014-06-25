/*
** xfunc.c for xfunc in /home/balbo_a/rendu/Includes/lib/lib-C
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov  6 19:48:56 2013 Alan Balbo
** Last update Sun Apr 13 10:10:17 2014 Alan BALBO
*/

#include "my.h"

void	*xmalloc(unsigned int size)
{
  void	*output;

  if ((output = malloc(size)) == NULL)
    {
      write(0, "!! Could not alloc !\n", 21);
      exit(0);
    }
  return (output);
}

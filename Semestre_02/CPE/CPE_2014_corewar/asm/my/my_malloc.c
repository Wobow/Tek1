/*
** my_malloc.c for libmy in /home/cesar_a/rendu/lib/my
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Tue Nov 26 05:14:06 2013 Aymeric CESAR
** Last update Tue Nov 26 05:19:09 2013 Aymeric CESAR
*/

#include <stdlib.h>
#include "my.h"

void	*my_malloc(size_t size)
{
  void	*dest;

  if ((dest = malloc(size)) == 0)
    {
      my_putstr("Couldn't alloc");
      exit(0);
    }
  return (dest);
}

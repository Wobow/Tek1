/*
** my_putstr.c for Piscine-C-Jour_04 in /home/cesar_a/rendu/Piscine-C-Jour_04
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Thu Oct  3 09:06:22 2013 Aymeric CESAR
** Last update Thu Jan 23 19:33:10 2014 Aymeric CESAR
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
  return (my_strlen(str));
}

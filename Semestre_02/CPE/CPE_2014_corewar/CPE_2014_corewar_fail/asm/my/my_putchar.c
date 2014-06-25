/*
** my_putchar.c for Piscine-C-Jour_07 in /home/cesar_a/rendu/Piscine-C-lib
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Wed Oct  9 11:07:43 2013 Aymeric CESAR
** Last update Thu Jan 23 19:23:52 2014 Aymeric CESAR
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

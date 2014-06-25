/*
** my_prout.c for my_prout in /home/balbo_a/rendu/CPE/my_printf
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Tue Nov 12 13:46:22 2013 Alan Balbo
** Last update Sun Apr 13 10:35:13 2014 Alan BALBO
*/

#include <my.h>

int	my_puthexa_form(unsigned int nbr)
{
  if (nbr >= 16)
    my_puthexa_form(nbr / 16);
  else
    my_putstr("0x");
  if (nbr % 16 > 9)
    my_putchar(nbr % 16 + 87);
  else
    my_putchar(nbr % 16 + 48);
  return (1);
}

int	my_put_ptr(int var)
{
  my_puthexa_form(var);
  return (1);
}

int	my_putoctal_form(unsigned int nbr, int i)
{
  if (nbr >= 8)
    my_putoctal_form(nbr / 8, i + 1);
  else
    my_putstr("\\0");
  my_putchar(nbr % 8 + 48);
  return (1);
}

int	my_puthexa_up_form(unsigned int nbr)
{
  if (nbr >= 16)
    my_puthexa_up_form(nbr / 16);
  else
    my_putstr("0x");
  if (nbr % 16 > 9)
    my_putchar(nbr % 16 + 87);
  else
    my_putchar(nbr % 16 + 48);
  return (1);
}

int	my_puthexa(unsigned int nbr)
{
  if (nbr >= 16)
    my_puthexa(nbr / 16);
  if (nbr % 16 >= 10)
    my_putchar(nbr % 16 + 87);
  else
    my_putchar(nbr % 16 + 48);
  return (0);
}

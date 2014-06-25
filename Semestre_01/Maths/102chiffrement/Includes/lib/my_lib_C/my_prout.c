/*
** my_prout.c for my_prout in /home/balbo_a/rendu/CPE/my_printf
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Tue Nov 12 13:46:22 2013 Alan Balbo
** Last update Sat Nov 16 00:09:32 2013 Alan Balbo
*/

#include "head_printf.h"

void	my_errno(void *truc)
{
  if(!strerror(errno))
    my_putstr("Fail");
  else
    my_putstr("Success");
}

void	my_puthexa_form(unsigned int nbr)
{
  if (nbr >= 16)
    my_puthexa_form(nbr / 16);
  else
    my_putstr("0x");
  if (nbr % 16 > 9)
    my_putchar(nbr % 16 + 87);
  else
    my_putchar(nbr % 16 + 48);
}

void	my_put_ptr(int var)
{
  my_puthexa_form(var);
}

void	my_putoctal_form(unsigned int nbr, int i)
{
  if (nbr >= 8)
    my_putoctal_form(nbr / 8, i + 1);
  else
    my_putstr("\\0");
  my_putchar(nbr % 8 + 48);
}

void	my_puthexa_up_form(unsigned int nbr)
{
  if (nbr >= 16)
    my_puthexa_up_form(nbr / 16);
  else
    my_putstr("0x");
  if (nbr % 16 > 9)
    my_putchar(nbr % 16 + 87);
  else
    my_putchar(nbr % 16 + 48);
}

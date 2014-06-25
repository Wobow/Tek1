/*
** my_prout.c for my_prout in /home/balbo_a/rendu/CPE/my_printf
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Tue Nov 12 13:46:22 2013 Alan Balbo
** Last update Sun Mar 16 21:00:04 2014 BALBO Alan
*/

#include <my.h>

void	my_putbin(unsigned int nbr)
{
  if (nbr < 0)
    {
      nbr = - nbr;
      my_putchar(45);
    }
  if (nbr >= 2)
    my_putbin(nbr / 2);
  my_putchar(nbr % 2 + 48);
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

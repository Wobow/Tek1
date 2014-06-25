/*
** my_printf.c for my_printf in /home/cesar_a/rendu/PSU_2013_my_printf
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Sun Nov 10 13:33:04 2013 Aymeric CESAR
** Last update Thu Jan 23 19:22:26 2014 Aymeric CESAR
*/

#include <stdarg.h>
#include "my.h"

int	my_put_ptr(long ptr)
{
  int	i;

  i = 0;
  if (ptr > 15)
    i = my_put_ptr(ptr / 16);
  ptr = ptr % 16;
  if (i == 0)
    {
      i = 2;
      my_putstr("0x");
    }
  if (ptr > 9)
    my_putchar(ptr + 'a' - 10);
  else
    my_putchar(ptr + '0');
  i = i + 1;
  return (i);
}

int	my_aff(va_list ap, const char *format, int i, int *c)
{
  if (format[i + 1] == 's')
    *c = *c + my_putstr(va_arg(ap, char*));
  else if (format[i + 1] == 'd')
    *c = *c + my_put_nbr(va_arg(ap, int));
  else if (format[i + 1] == 'c')
    *c = *c + my_putchar((char)va_arg(ap, int));
  else if (format[i + 1] == 'p')
    *c = *c + my_put_ptr((long)va_arg(ap, void*));
  else
    {
      *c = *c + 1;
      my_putchar(format[i++]);
      i = i - 1;
    }
  i = i + 2;
  return (i);
}

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
  int		c;

  va_start(ap, format);
  i = 0;
  c = 0;
  while (format[i])
    if (format[i] != '%')
      {
	my_putchar(format[i++]);
	c = c + 1;
      }
    else
      i = my_aff(ap, format, i, &c);
  va_end(ap);
  return (c);
}

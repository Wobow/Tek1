/*
** utilities.c for utilities in /home/balbo_a/rendu/PSU_2013_minitalk/srcs_client
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Mar 21 14:26:50 2014 BALBO Alan
** Last update Fri Mar 21 14:28:03 2014 BALBO Alan
*/

#include "client.h"

int	_sig_error(int pid)
{
  my_putstr("Can't send message to PID ");
  my_putnbr(pid);
  my_putchar(10);
  return (EXIT_FAILURE);
}

void	prompt_state(int i, int total)
{
  my_putstr("\r     \r[");
  my_putnbr((i * 100) / total);
  my_putstr("%]");
}

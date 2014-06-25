/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Sun Mar 23 18:20:10 2014 BALBO Alan
*/

#include "client.h"

void	prompt_help()
{
  my_putstr("Client for minitalk\n\n\tUsage : ./client [PID]");
  my_putstr(" [MSG] [[-s SPEED]]\n\n\t[PID] : PID of minitalk server.\n");
  my_putstr("\t[MSG] : Message to send to minitalk server\n\t");
  my_putstr("[[-s SPEED]] (optional) : change the delay between two signals");
  my_putstr(". By default, value is set to 500. SPEED must be over 100\n");
  my_putstr("\t!! WARNING : a low SPEED may cause errors while sending");
  my_putstr("the message.\n");
  exit(EXIT_SUCCESS);
}

void	xkill(int pid, int s)
{
  if (kill(pid, s) == -1)
    {
      my_putstr("\nError while sending signal to PID ");
      my_putnbr(pid);
      my_putchar(10);
      exit(EXIT_FAILURE);
    }
}

void	send_char(int pid, char c, int speed)
{
  int	pb;

  pb = 128;
  while (pb != 1)
    {
      if (c >= pb)
	{
	  c = c % pb;
	  xkill(pid, SIGUSR1);
	}
      else
	xkill(pid, SIGUSR2);
      usleep(speed);
      pb = pb / 2;
    }
  if (c == 1)
    xkill(pid, SIGUSR1);
  else
    xkill(pid, SIGUSR2);
  usleep(speed);
}

int	chk_opt(int ac, char **av)
{
  if (ac == 2)
    {
      if (my_strcmp(av[1], "--help") == 0)
	prompt_help();
      exit(my_putstr("Use ./client --help for help\n"));
    }
  else if (ac == 5)
    {
      if (my_strcmp(av[3], "-s") != 0)
	prompt_help();
      if (my_getnbr(av[4]) < 100)
	return (100);
      else
	return (my_getnbr(av[4]));
    }
  else if (ac == 3)
    return (500);
  else
    prompt_help();
}

int	main(int ac, char **av)
{
  int	i;
  int	total;
  int	speed;

  i = 0;
  if (ac < 2)
    {
      my_putstr("Usage : ./client [PID_SERVER] [MSG] [[-s SPEED] --help] \n");
      return (EXIT_FAILURE);
    }
  else
    speed = chk_opt(ac, av);
  total = my_strlen(av[2]);
  if (kill(my_getnbr(av[1]), 0) == -1)
    return (_sig_error(my_getnbr(av[1])));
  while (av[2][i])
    {
      send_char(my_getnbr(av[1]), av[2][i], speed);
      i++;
    }
  send_char(my_getnbr(av[1]), '\n', speed);
  my_putstr("\r        \rSent.\n");
  return (EXIT_SUCCESS);
}

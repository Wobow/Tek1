/*
** main.c for main in /home/balbo_a/rendu/libs/IncludesC/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Dec 13 14:25:28 2013 BALBO Alan
** Last update Sun Mar 23 18:21:16 2014 BALBO Alan
*/

#include "server.h"

char    g_letter[8] = "--------";

void	prompt_letter()
{
  int	c;

  c = my_getnbr_base(g_letter, "01");
  my_putchar(c);
  if (c > 127)
    exit(my_putstr("\n\nAn error has occur. Please retry.\n"));
  c = 0;
  while (c < 8)
    {
      g_letter[c] = '-';
      c++;
    }
}

void	decrypt(int s)
{
  int	i;

  i = 0;
  while (g_letter[i] != '-' && i < 8)
    i++;
  if (s == SIGUSR1)
    g_letter[i] = '1';
  else
    g_letter[i] = '0';
  if (i == 7)
    prompt_letter();
}

int	main(int ac, char **av)
{
  my_putstr("Server PID : ");
  my_putnbr(getpid());
  my_putchar(10);
  signal(SIGUSR1, decrypt);
  signal(SIGUSR2, decrypt);
  while (pause());
}

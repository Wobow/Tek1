/*
** test.c for test in /home/balbo_a/rendu/Maths/101pong
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Fri Nov 15 21:49:55 2013 Alan Balbo
** Last update Fri Nov 15 21:53:45 2013 Alan Balbo
*/

#include <stdio.h>

int	main()
{
  int	ux;
  int	uy;
  int	wx;
  int	wy;
  int	vx;
  int	vy;

  ux = 200;
  uy = -200;

  wx = 200;
  wy = 50;

  vx = 2 * (ux * wx + uy * wy) * wx - ux;
  vy = 2 * (ux * wx + uy * wy) * wy - uy;
  printf("Vecteur : (%d;%d)\n", vx, vy);
}

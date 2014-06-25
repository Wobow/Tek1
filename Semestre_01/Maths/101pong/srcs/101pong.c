/*
** 101pong.c for 101pong in /home/balbo_a/rendu/Maths/101pong/srcs
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Tue Nov 12 18:25:36 2013 Alan Balbo
** Last update Sat Nov 16 00:28:49 2013 Alan Balbo
*/

#include <stdio.h>
#include <math.h>

void		get_angle(int a, int b, int c)
{
  float		angle;
  float		cosa;
  float		hypo;
  float		hypo2;
  float		sin;

  hypo = sqrt((a * a) + (b * b));
  hypo2 = sqrt((hypo * hypo) + (c * c));
  cosa = c / hypo2;
  angle = (90 - (acos(cosa) * (180 / 3.1416)));
  if (c < 0)
    angle = - angle;
  printf("L'angle d'incidence est de %.2f degrés.\n", angle);
}

int		main(int argc, char **argv)
{
  int		vx;
  int		vy;
  int		vz;
  int		x1;
  int		y1;
  int		z1;
  int		n;

  if (argc == 8)
    {
      x1 = my_getnbr(argv[4]);
      y1 = my_getnbr(argv[5]);
      z1 = my_getnbr(argv[6]);
      n = my_getnbr(argv[7]);
      vx = x1 - my_getnbr(argv[1]);
      vy = y1 - my_getnbr(argv[2]);
      vz = z1 - my_getnbr(argv[3]);
      my_printf("Les coordonnées du vecteur vitesse sont (%d;%d;%d).\n", vx, vy, vz);
      my_printf("A l'instant t+%d, les coordonnées de la balle seront (%d;%d;%d).\n", n, x1 + (n * vx), y1 + (n * vy), z1 + (n * vz));
      get_angle(vx, vy, vz);
    }
  else
    my_putstr("Not enough params\n");
}

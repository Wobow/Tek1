/*
** my_power_rec.c for my_power_rec in /home/balbo_a/rendu/Piscine-C-Jour_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Fri Oct  4 14:26:50 2013 Alan Balbo
** Last update Tue Oct  8 09:55:15 2013 Alan Balbo
*/

int	my_power_rec(int nb, int p)
{
  if (p > 1)
    nb = nb * my_power_rec(nb, p - 1);
  else nb = 1;
}

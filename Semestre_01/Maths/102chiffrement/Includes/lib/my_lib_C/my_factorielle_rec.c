/*
** my_factorielle_rec.c for my_factorielle_rec in /home/balbo_a/rendu/Piscine-C-Jour_05
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Fri Oct  4 09:21:55 2013 Alan Balbo
** Last update Tue Oct  8 09:55:29 2013 Alan Balbo
*/

int	my_factorielle_rec(int nb)
{
  if (nb !=  1)
    nb = nb * my_factorielle_rec(nb - 1);
  return (nb);
}

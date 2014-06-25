/*
** my_swap.c for my_swap in /home/balbo_a/rendu/Piscine-C-Jour_04
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Thu Oct  3 10:14:41 2013 Alan Balbo
** Last update Fri Oct  4 20:14:25 2013 Alan Balbo
*/

int	my_swap(int *a, int *b)
{
  int	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

/*
** my_sort_int_tab.c for my_sort_int_tab in /home/balbo_a/rendu/Piscine-C-Jour_04
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Fri Oct  4 22:07:15 2013 Alan Balbo
** Last update Fri Oct  4 23:34:37 2013 Alan Balbo
*/

int	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
   while (i < size)
    {
      while (j < size - 1)
	{
	  if (tab[j] > tab[j + 1])
	    {
	      my_swap(&tab[j], &tab[j + 1]);
	    }
	  j = j + 1;
	}
      i = i + 1;
      j = 0;
    }
}

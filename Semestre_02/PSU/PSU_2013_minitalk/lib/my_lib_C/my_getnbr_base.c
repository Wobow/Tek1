/*
** my_getnbr_base.c for my_getnbr_base in /home/balbo_a/rendu/Piscine-C-Jour_06
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Oct  7 22:45:46 2013 Alan Balbo
** Last update Mon Mar 17 03:02:56 2014 BALBO Alan
*/

int	my_power_recur(int n, int p)
{
  if (p == 0)
    return (1);
  return (my_power_recur(n, p - 1) * n);
}

int	my_getnbr_base(char *str, char *base)
{
  int	i;
  int	j;
  int	p;
  int	out;

  i = my_strlen(str) - 1;
  p = 0;
  out = 0;
  while (i >= 0)
    {
      j = 0;
      while (str[i] != base[j] && base[j])
	j++;
      out += my_power_recur(my_strlen(base), p)* j;
      p++;
      i--;
    }
  return (out);
}

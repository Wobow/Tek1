/*
** 102chiffrement.c for 102chiffrement in /home/balbo_a/102chiffrement-2018-balbo_a
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Mon Nov 18 16:54:58 2013 Alan Balbo
** Last update Mon Nov 25 15:30:46 2013 Alan Balbo
*/

#include "head.h"

int	my_getalpha(char c, t_ruc *t)
{
  if (c >= 'a' && c <= 'z')
    return (c - 96);
  else if (c == 32)
    return (0);
  else
    {
      free(t->matrice);
      free(t->message);
      free(t);
      exit(write(0, "lol, only lowercase characters and spaces are allowed\n", 55));
    }
}

int	 check_base(t_ruc *t)
{
  int	i;
  int	j;

  i = 0;
  while (t->base[i])
    {
      j = 0;
      while (t->base[j])
	{
	  if (t->base[j] == t->base[i] && i != j)
	    return (0);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}

void	get_message(t_ruc *t, char *str)
{
  int	i;

  i = my_strlen(str);
  if (i % 2)
    i = i + 1;
  t->message = xmalloc(sizeof(int) * (i + 1));
  t->convert_matrice = xmalloc(sizeof(int) * (i + 1));
  t->message[i] = 27;
  i = 0;
  while (str[i])
    {
      t->message[i] = my_getalpha(str[i], t);
      i = i + 1;
    }
  i = 0;
  while (i < my_strlen(str) && ++i)
    t->message[i - 1] = my_getalpha(str[i - 1], t);
}

void	my_putnbr_base(int nbr, char *base)
{
  if (nbr >= my_strlen(base))
    my_putnbr_base(nbr / my_strlen(base), base);
  my_putchar(base[nbr % my_strlen(base)]);
}

int	my_getnbr_base(char *nbr, char *base)
{
  int	i;
  int	j;
  int	out;

  i = 0;
  out = 0;
  while (nbr[i])
    {
      j = 0;
      while (nbr[i] != base[j] && base[j])
	j = j + 1;
      out = out + j * pow(my_strlen(base), my_strlen(nbr) - 1 - i);
      i = i + 1;
    }
  return (out);
}

void	encrypt(t_ruc *t, char *str)
{
  int	i;

  get_message(t, str);
  while (t->message[i] != 27)
    {
      if (i % 2 == 0)
	t->convert_matrice[i] = t->matrice[0] * t->message[i] + t->matrice[2] * t->message[i + 1];
      else
	t->convert_matrice[i] = t->matrice[3] * t->message[i] + t->matrice[1] * t->message[i - 1];
      my_putnbr_base(t->convert_matrice[i], t->base);
      my_putchar(32);
      i = i + 1;
    }
}

int	my_super_strlen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i = i + 1;
  return (i);
}

void	invert_matrice(t_ruc *t)
{
  int	i;
  int	c;
  float	fact;

  i = 0;
  fact = t->matrice[0] * t->matrice[3] - t->matrice[2] * t->matrice[1];
  if (fact)
    {
      while (i < 4)
	{
	  if (i == 1 || i == 2)
	    t->matrice[i] = ((float)1 / (float)fact) * (float)-t->matrice[i];
	  else if (i == 0)
	    {
	      c = t->matrice[3];
	      t->matrice[3] = (float)((float)1 / (float)fact) * (float)t->matrice[0];
	      t->matrice[0] = (float)((float)1 / (float)fact) * (float)c;
	    }
	  i = i + 1;
	}
    }
  else
    {
      my_putstr("Matrice irréversible : impossible de décrypter.\n");
      exit(0);
    }
}

void	decrypt(t_ruc *t, char *str)
{
  int	nbr;
  char	**intab;
  int	i;

  intab = my_str_to_wordtab(str);
  i = 0;
  t->message = xmalloc(sizeof(int) * (my_super_strlen(intab) + 1));
  t->message[my_super_strlen(intab)] = 27;
  while (intab[i])
    {
      t->message[i] = my_getnbr_base(intab[i], t->base);
      i = i + 1;
    }
  i = 0;
  t->convert_matrice = xmalloc(sizeof(int) * (my_super_strlen(intab) + 1));
  t->convert_matrice[my_super_strlen(intab)] = 0;
  invert_matrice(t);
  i = 0;
  while (t->message[i] != 27)
    {
      if (i % 2 == 0)
	t->convert_matrice[i] = t->matrice[0] * t->message[i] + t->matrice[2] * t->message[i + 1];
      else
	t->convert_matrice[i] = t->matrice[3] * t->message[i] + t->matrice[1] * t->message[i - 1];
      my_putnbr_base(t->convert_matrice[i], " abcdefghijklmnopqrstuvwxyz");
      i = i + 1;
    }
}

int	main(int argc, char **argv)
{
  t_ruc *t;
  int	i;

  if (argc == 8)
    {
      i = 0;
      t = xmalloc(sizeof(*t));
      t->matrice = xmalloc(sizeof(float) * 4);
      t->base = argv[6];
      if (!check_base(t))
	exit(write(1, "Error : check your base please :)\n", 34));
      while (i < 4 && ++i)
	t->matrice[i - 1] = my_getnbr(argv[1 + i]);
      i = 0;
      if (my_getnbr(argv[7]))
	decrypt(t, argv[1]);
      else
	encrypt(t, argv[1]);
    }
  else
    my_printf("Usage : ./I need 7 parameters instead of %d... :)", argc - 1);
  my_putchar(10);
  return (0);
}

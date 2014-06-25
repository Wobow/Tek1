/*
** my_aff_comb.c for my_aff_comb in /home/balbo_a/rendu/Piscine-C-Jour_03
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Wed Oct  2 10:12:29 2013 Alan Balbo
** Last update Thu Oct  3 21:32:16 2013 Alan Balbo
*/

int	print_combi(char c1, char c2, char c3)
{
  my_putchar(c1);
  my_putchar(c2);
  my_putchar(c3);
  if (c1 != '7')
    {
      my_putchar(44);
      my_putchar(32);
    }
}

int	my_aff_comb()
{
  char	char1;
  char	char2;
  char	char3;

  char1 = 48;
  char2 = 0;
  char3 = 0;
  while (char1 <= 55)
    {
      char2 = char1 + 1;
      while (char2 <= 56)
	{
	  char3 = char2 + 1;
	  while (char3 <= 57)
	    {
	      print_combi(char1, char2, char3);
	      char3 = char3 + 1;
	    }
	  char2 = char2 + 1;
	}
      char1 = char1 + 1;
    }
}

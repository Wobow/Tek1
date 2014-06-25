/*
** my_str_isalpha.c for my_str_isalpha in /home/balbo_a/rendu/Piscine-C-Jour_06
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 16:56:14 2013 Alan Balbo
** Last update Mon Oct  7 17:18:04 2013 Alan Balbo
*/

int	my_str_isalpha(char *str)
{
  int	i;
  int	out;

  i = 0;
  out = 1;
  while (str[i] != '\0')
    {
      if (str[i] >= '[' && str[i] <= '`')
	{
	  out = 0;
	}
      else if (str[i] < 65 || str[i] > 122)
	{
	  out = 0;
	}
      i = i + 1;
    }
  return (out);
}

/*
** my_strcapitalize.c for my_strcapitalize in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_09
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 15:31:47 2013 Alan Balbo
** Last update Thu Oct 10 20:15:58 2013 Alan Balbo
*/

int	verif_char(char c)
{
  int	out;

  out = 1;
  if ((c > 47 && c < 57) || (c > 'A' && c < 'z'))
    {
      if (c < 91 || c > 96)
	{
	  out = 0;
	}
    }
  return (out);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (verif_char(str[i]) == 1 && str[i + 1] >= 'a' && str[i + 1] <= 'z')
	{
	  str[i + 1] = str[i + 1] - 32;
	}
      else if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
	{
	  str[i] = str[i] - 32;
	}
      else if (str[i] >= 'A' && str[i] <= 'Z' && verif_char(str[i - 1]) == 0)
	{
	  if (i != 0)
	    {
	      str[i] = str[i] + 32;
	    }
	}
      i = i + 1;
    }
  return (str);
}

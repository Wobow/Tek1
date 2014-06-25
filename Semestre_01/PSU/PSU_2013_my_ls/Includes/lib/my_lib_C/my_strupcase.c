/*
** my_strupcase.c for my_strupcase in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_07
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 14:00:19 2013 Alan Balbo
** Last update Mon Oct  7 15:28:04 2013 Alan Balbo
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
      	{
      	  str[i] = str[i] - 32;
      	}
      i = i + 1;
    }
  return (str);
}

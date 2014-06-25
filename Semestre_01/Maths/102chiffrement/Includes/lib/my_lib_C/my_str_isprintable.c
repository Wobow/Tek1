/*
** my_str_isprintable.c for my_str_isprintable in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_14
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 18:14:51 2013 Alan Balbo
** Last update Mon Oct  7 18:51:37 2013 Alan Balbo
*/

int	my_str_isprintable(char *str)
{
  int   i;
  int   out;

  i = 0;
  out = 1;
  while (str[i] != '\0')
    {
      if (str[i] < 9 || (str[i] > 12 && str[i] < 32) && str[i] != 127)
        {
          out = 0;
        }
      i = i + 1;
    }
  return (out);
}
